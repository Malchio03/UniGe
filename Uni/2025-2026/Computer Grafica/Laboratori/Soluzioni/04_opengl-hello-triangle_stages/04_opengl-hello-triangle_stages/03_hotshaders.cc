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
    GLuint vbo;
    GLuint vao;

    Scene () { load (); }
    ~Scene () { clean (); }

    void load ()
    {
        // coordinates in clip space! no transformation involved
        points = {
            0.0f,  0.5f,  0.0f,  // x,y,z of first point
            0.5f, -0.5f,  0.0f,  // x,y,z of second point
            -0.5f, -0.5f,  0.0f   // x,y,z of third point
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
        // we describe how the attribute 0 is organized inside our buffer
        glVertexAttribPointer (0,
                               3,
                               GL_FLOAT,
                               GL_FALSE,
                               0,
                               NULL);
        // we enable attribute 0 to be passed as input to the vertex shader
        glEnableVertexAttribArray (0);
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

// right now, draw needs to know the number of vertices only
// everything else is in GPU memory, pulled from the current VAO
// the drawing style is computed inside the GPU, by the shader program
void draw (size_t num_vertices)
{
    // clear the buffers
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // draw 3 vertices as a single triangle
    glDrawArrays (GL_TRIANGLES, 0, num_vertices);
}



////////////////////
// SFML Callbacks //
////////////////////

void handle (const sf::Event::KeyPressed& key, Scene& scene, Shaders& shaders)
{
    switch (key.scancode) {
    case sf::Keyboard::Scancode::Space:
        shaders.reload ("03_vertex.vert", "03_fragment.frag");
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

    // // create default shaders
    // Shaders shaders;
    
    // load shaders from files
    Shaders shaders ("03_vertex.vert", "03_fragment.frag");

    // Put the shader program, and the VAO, in focus in OpenGL's state machine
    // these can changed dynamically as needed in the loop too.
    glUseProgram (shaders.program);
    glBindVertexArray (scene.vao);



    ///////////////
    // Main Loop //
    ///////////////

    bool running = true;
    while (running) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                running = false;
            else if (const auto* resized = event->getIf<sf::Event::Resized>())
                glViewport (0, 0, resized->size.x, resized->size.y);
            else if (const auto* key_pressed = event->getIf<sf::Event::KeyPressed>())
                handle (*key_pressed, scene, shaders);
        }

        // draw, using the current VAO and current ShaderProgram
        draw (scene.points.size());
 
        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    return 0;


}
