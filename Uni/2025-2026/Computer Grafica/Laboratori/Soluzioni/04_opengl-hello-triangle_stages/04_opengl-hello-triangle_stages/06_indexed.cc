#define GLAD_GL_IMPLEMENTATION // Necessary for the header-only version.
#include "glad/gl.h"

#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>



////////////////////
// How it's drawn //
////////////////////

// the Shaders class is now implemented in this header-only module
#include "03_hotshaders.hh"



/////////////////////////////
// Window and OpenGL setup //
/////////////////////////////

class Setup
{
public:
    sf::Window* window;

    Setup ()
    {
        sf::ContextSettings settings;
        settings.depthBits = 32;
        settings.stencilBits = 8;
        settings.antiAliasingLevel = 4;
        settings.attributeFlags = sf::ContextSettings::Attribute::Core;
        settings.majorVersion = 4;
        settings.minorVersion = 1;

        window = new sf::Window (
                                 sf::VideoMode({800, 600}),
                                 "SFML + OpenGL",
                                 sf::Style::Default,
                                 sf::State::Windowed,
                                 settings
                                 );
        window->setVerticalSyncEnabled (true);

        if (!window->setActive (true)) {
            std::cerr << "Failure: error during SFML OpenGL Activation." << std::endl;
            exit (1);
        }
        sf::ContextSettings gotten = window->getSettings();

        std::cout << "depth bits: " << gotten.depthBits << std::endl;
        std::cout << "stencil bits: " << gotten.stencilBits << std::endl;
        std::cout << "antialiasing level: " << gotten.antiAliasingLevel << std::endl;
        std::cout << "SFML GL version: " << gotten.majorVersion << "." << gotten.minorVersion << std::endl;

        int version = gladLoadGL (sf::Context::getFunction);
        if (!version) {
            std::cerr << "Failure: error during glad loading." << std::endl;
            exit (1);
        }
        std::cout << "GLAD GL version: " << GLAD_VERSION_MAJOR(version) << "." << GLAD_VERSION_MINOR(version) << std::endl;
    }

    ~Setup ()
    {
        delete window;
    }
};



//////////////////
// What to draw //
//////////////////

class Scene
{
public:
    std::vector<float> points;
    std::vector<unsigned int> indices;
    GLuint vbo;
    GLuint ebo;
    GLuint vao;

    // Location of the uniform "mod_color" in the fragment shader
    GLint mod_color_location;
    // we define two different color modifications as RGB static arrays
    // NOTE: this is a brutal hack for the sake of simplicity.
    //       see comments inside 05_fragment.frag for further details.
    static constexpr float darken_color[3] = {-0.2, -0.2, -0.2};
    static constexpr float lighten_color[3] = {0.2, 0.2, 0.2};
    Scene () { load (); }
    ~Scene () { clean (); }

    void load ()
    {
        // coordinates in clip space! no transformation involved
        points = {
            
            0.0, 0.5, 0.0, // red, top center
            0.8, 0.0, 0.0,

            0.5,-0.5, 0.0, // green, bottom right
            0.0, 0.8, 0.0,

           -0.5,-0.5, 0.0, // blue, bottom left
            0.0, 0.0, 0.8

        };

        // 1 face, 3 indices per face, CCW order
        indices = {
            0, 2, 1
        };

        // we want just one buffer, and we retrieve the name OpenGL assigns to it.
        glGenBuffers (1, &vbo);
        // bind it as the current VBO
        glBindBuffer (GL_ARRAY_BUFFER, vbo);
        // transfer data from CPU RAM to GPU RAM.
        glBufferData (GL_ARRAY_BUFFER,
                      points.size() * sizeof (float),
                      points.data(),
                      GL_STATIC_DRAW);

        // we want just one buffer container, and we retrieve the name OpenGL assigns to it.
        glGenVertexArrays (1, &vao);
        // bind it as the current vao.
        glBindVertexArray (vao);

        // Attribute 0: position (x, y, z)
        glVertexAttribPointer (0,
                               3,
                               GL_FLOAT,
                               GL_FALSE,
                               6 * sizeof(float),
                               (void*)0);
        glEnableVertexAttribArray (0);

        // Attribute 1: color (r, g, b)
        glVertexAttribPointer (1,
                               3,
                               GL_FLOAT,
                               GL_FALSE,
                               6 * sizeof(float),
                               (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray (1);

        // element buffer object
        glGenBuffers(1, &ebo); 
        // MUST be bound after the VAO's binding!
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                     indices.size() * sizeof (unsigned int),
                     indices.data(),
                     GL_STATIC_DRAW);
    }

    void clean ()
    {
        glDeleteVertexArrays (1, &vao);
        glDeleteBuffers (1, &vbo);
    }

    // // when data will be dynamically loaded, reloading will be useful
    // void reload ()
    // {
    //     clean ();
    //     load ();
    // }
};




/////////////
// Draw!!! //
/////////////

void draw (Scene& scene, float elapsed)
{
    // clear the buffers
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    static float accumulator = 0.0;

    accumulator += elapsed;

    // alternate colors every second, with original colors in between transitions
    if (accumulator < 1.0)
        glUniform3fv (scene.mod_color_location, 1, scene.lighten_color);
    else if (accumulator < 2.0 || (accumulator >= 3.0 && accumulator < 4.0))
        glUniform3f (scene.mod_color_location, 0.0, 0.0, 0.0);
    else if (accumulator < 3.0)
        glUniform3fv (scene.mod_color_location, 1, scene.darken_color);
    else
        accumulator = 0.0;


    // draw 3 triangles with 9 indices
    glDrawElements(GL_TRIANGLES, scene.indices.size(), GL_UNSIGNED_INT, 0);
}



////////////////////
// SFML Callbacks //
////////////////////

void handle (const sf::Event::KeyPressed& key, Scene& scene, Shaders& shaders)
{
    switch (key.scancode) {
    case sf::Keyboard::Scancode::Space:
        shaders.reload ("05_vertex.vert", "05_fragment.frag");
        glUseProgram (shaders.program);
        return;
    default:
        return;
    }
}



//////////
// Main //
//////////

int main()
{
    // setup SFML + OpenGL, using GLAD
    Setup setup;
    sf::Window& window = *setup.window;

    // create a default scene
    Scene scene;

    // create default shaders
    // Shaders shaders;
    
    // load shaders from files
    Shaders shaders ("05_vertex.vert", "05_fragment.frag");


    ///////////////
    // Main Loop //
    ///////////////

    // Put the shader program, and the VAO, in focus in OpenGL's state machine
    // these can changed dynamically as needed in the loop too.
    glUseProgram (shaders.program);
    glBindVertexArray (scene.vao);

    // Get the location of the mod_color uniform variable, store it in our scene
    scene.mod_color_location = glGetUniformLocation (shaders.program, "mod_color");

    sf::Clock clock;

    bool running = true;
    while (running)
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                running = false;
            else if (const auto* resized = event->getIf<sf::Event::Resized>())
                glViewport (0, 0, resized->size.x, resized->size.y);
            else if (const auto* key_pressed = event->getIf<sf::Event::KeyPressed>())
                handle (*key_pressed, scene, shaders);
        }

        // draw, using the current VAO and current ShaderProgram
        draw (scene, clock.restart().asSeconds());

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    return 0;


}
