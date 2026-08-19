#define GLAD_GL_IMPLEMENTATION // Necessary for the header-only version.
#include "glad/gl.h"
#include <SFML/Window.hpp>
// GLM: include only strict dependencies, as shown in https://github.com/g-truc/glm/blob/master/manual.md#section1
#include <glm/mat4x4.hpp>         // mat4
#include <glm/trigonometric.hpp>  //radians

#include <iostream>
#include <cstdlib>



////////////////////
// How it's drawn //
////////////////////

#include "./include/hotshaders.hh"



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
        sf::ContextSettings gotten = window->getSettings ();

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



//////////////////////////
// What and how to draw //
//////////////////////////

class Camera
{
private:
    GLint vp_loc;
    float phi_deg = 210.0;
    float theta_deg = 1.0;

public:
    Camera (Shaders& shaders)
    {
        vp_loc = glGetUniformLocation (shaders.program, "vp");
        update ();
    }

    void drag (float dx, float dy)
    {
        phi_deg += dx * 0.1;
        theta_deg += dy * 0.1;
        theta_deg = theta_deg > 90.0? 90.0 : theta_deg;
        theta_deg = theta_deg < -90.0? -90.0 : theta_deg;
        update ();
    }

private:
    void update ()
    {
        // prepare rotation matrices
        //// Convert degrees to radians, compute sin and cos
        float ps = glm::sin (glm::radians (phi_deg));
        float pc = glm::cos (glm::radians (phi_deg));
        glm::mat4 ry = glm::mat4(
                                  pc, 0.0, -ps, 0.0, // 1st column
                                 0.0, 1.0, 0.0, 0.0, // 2nd column
                                  ps, 0.0,  pc, 0.0, // 3rd column
                                 0.0, 0.0, 0.0, 1.0
                                 );

        //// Convert degrees to radians, compute sin and cos
        float ts = glm::sin (glm::radians (theta_deg));
        float tc = glm::cos (glm::radians (theta_deg));
        glm::mat4 rx = glm::mat4(
                                 1.0, 0.0, 0.0, 0.0, // 1st column
                                 0.0,  tc, ts,  0.0, // 2nd column
                                 0.0, -ts, tc,  0.0, // 3rd column
                                 0.0, 0.0, 0.0, 1.0
                                 );

        // prepare translation matrix
        glm::mat4 tz = glm::mat4(
                                 1.0, 0.0, 0.0, 0.0, // 1st column
                                 0.0, 1.0, 0.0, 0.0, // 2nd column
                                 0.0, 0.0, 1.0, 0.0, // 3rd column
                                 0.0, 0.0,-2.0, 1.0  // translate object along the Z axis
                                 );

        // prepare projection matrix
        float fd = 2.0;             // focal distance
        float fcp = 3.0;             // distance far clip plane
        float ncp = 1.0;             // distance near clip plane
        float a = (fcp + ncp) / (ncp - fcp);       // coefficient 3rd col
        float b = 2.0 * fcp * ncp / (ncp - fcp);   // coefficient 4th col

        /*** NOTE *******************************************************
         **  We use fd directly as coefficient in the first two lines. **
         **  It works because our scene is in a unitary cube.          **
         **  If the image plane is centered about the view axis, with  **
         **  width 2r and height 2t in view space, the coefficients    **
         **  containing fd must be scaled accordingly.                 **
         ****************************************************************/
        glm::mat4 pr = glm::mat4(
                                 fd,  0.0, 0.0,  0.0,    // 1st column
                                 0.0,  fd, 0.0,  0.0,    // 2nd column
                                 0.0, 0.0,   a, -1.0,    // 3rd column
                                 0.0, 0.0,   b,  0.0     // 4th column
                                 );

        // Compute VP matrix and update it
        glm::mat4 vp; 
        vp = pr * tz * rx * ry;
        glUniformMatrix4fv (vp_loc, 1, GL_FALSE, &vp[0][0]);
    }
};

class Scene
{
private:
    // data to be drawn
    std::vector<float> points;
    std::vector<unsigned int> indices;
    GLuint vbo;
    GLuint ebo;
    GLuint vao;

public:
    Scene () { load (); }
    ~Scene () { clean (); }

    void load ()
    {
        // coordinates in clip space! no transformation involved
        // we define a very simple shape, resembling a butterfly:
        // two non-intersecting triangles joined by a single vertex
        // this shape is not closed, so culling will be disabled
        points = {
            
            0.0, 0.5, 0.0, // red/magenta mix (kind of...), top center
            0.8, 0.0, 0.4,

            0.5,-0.5, 0.3, // green, bottom right, back
            0.0, 0.8, 0.0,

           -0.5,-0.5, 0.3, // blue, bottom left, back
            0.0, 0.0, 0.8,

            0.5,-0.5,-0.3, // cyan, bottom right, front
            0.0, 0.8, 0.8,

           -0.5,-0.5,-0.3, // yellow, bottom left, front
            0.8, 0.8, 0.0
        };

        // 2 faces, 3 indices per face, CCW order
        indices = {
            0, 3, 4,
            0, 2, 1
        };

        // we want just one buffer, and we retrieve the name OpenGL assigns to it.
        glGenBuffers (1, &vbo);
        // bind it as the current VBO
        glBindBuffer (GL_ARRAY_BUFFER, vbo);
        // transfer data from CPU RAM to GPU RAM.
        glBufferData (GL_ARRAY_BUFFER,
                      points.size () * sizeof (float),
                      points.data (),
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

        glGenBuffers(1, &ebo); 
        // MUST be bound after the VAO's binding!
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                     indices.size () * sizeof (unsigned int),
                     indices.data (),
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

    void draw ()
    {
        // clear the buffers
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw all elements as described by indices
        glDrawElements(GL_TRIANGLES, indices.size (), GL_UNSIGNED_INT, 0);
    }
};



////////////////////
// SFML Callbacks //
////////////////////

void handle (const sf::Event::KeyPressed& key, Shaders& shaders)
{
    switch (key.scancode) {
    case sf::Keyboard::Scancode::Space:
        shaders.reload ("03_vertex.vert", "00_fragment.frag");
        shaders.use ();
        return;
    default:
        return;
    }
}

void handle (const sf::Event::MouseMoved* mouse, Camera& camera)
{
    float x = mouse->position.x;
    float y = mouse->position.y;
    static float prev_x = 0;
    static float prev_y = 0;

    float dx = x - prev_x; 
    float dy = y - prev_y; 
    // std::cout <<"dx: "<<dx<<" | dy: "<<dy<<"\n";
    prev_x = x;
    prev_y = y;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        camera.drag (dx, dy);
}



//////////
// Main //
//////////

int main ()
{
    //// Startup ////

    // setup SFML + OpenGL, using GLAD
    Setup setup;
    sf::Window& window = *setup.window;

    // load shaders from files, and use them
    Shaders shaders ("03_vertex.vert", "00_fragment.frag");
    shaders.use ();

    // create an orbiting camera
    Camera camera (shaders);
    // create a default scene
    Scene scene;

    // face culling (temporarily disabled, because the butterfly is not a closed surface)
    // glEnable (GL_CULL_FACE);
    // glCullFace (GL_BACK);

    // depth testing
    glEnable (GL_DEPTH_TEST);


    //// Main Loop ////

    bool running = true;
    while (running)
    {
        while (const std::optional event = window.pollEvent ())
        {
            if (event->is<sf::Event::Closed> ())
                running = false;
            else if (const auto* resized = event->getIf<sf::Event::Resized> ())
                glViewport (0, 0, resized->size.x, resized->size.y);
            else if (const auto* key_pressed = event->getIf<sf::Event::KeyPressed> ())
                handle (*key_pressed, shaders);
            else if (const auto* mouse = event->getIf<sf::Event::MouseMoved> ())
                handle (mouse, camera);
        }
        // draw, using the current VAO and current ShaderProgram
        scene.draw ();

        // end the current frame (internally swaps the front and back buffers)
        window.display ();
    }

    return 0;
}
