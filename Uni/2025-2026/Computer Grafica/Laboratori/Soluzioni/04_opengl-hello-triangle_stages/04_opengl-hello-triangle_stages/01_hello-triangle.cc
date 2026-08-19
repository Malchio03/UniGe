#define GLAD_GL_IMPLEMENTATION // Necessary for the header-only version.
#include "glad/gl.h"

#include <SFML/Window.hpp>
#include <iostream>


int main()
{
    /////////////////////////////
    // Window and OpenGL setup //
    /////////////////////////////

    sf::ContextSettings settings;
    settings.depthBits = 32;
    settings.stencilBits = 8;
    settings.antiAliasingLevel = 4;
    settings.attributeFlags = sf::ContextSettings::Attribute::Core;
    settings.majorVersion = 4;
    settings.minorVersion = 1;

    sf::Window window(
        sf::VideoMode({800, 600}),
        "SFML + OpenGL",
        sf::Style::Default,
        sf::State::Windowed,
        settings
    );
    window.setVerticalSyncEnabled (true);

    if (!window.setActive (true)) {
        std::cerr << "Failure: error during SFML OpenGL Activation." << std::endl;
        return 1;
    }
    sf::ContextSettings gotten = window.getSettings();

    std::cout << "depth bits: " << gotten.depthBits << std::endl;
    std::cout << "stencil bits: " << gotten.stencilBits << std::endl;
    std::cout << "antialiasing level: " << gotten.antiAliasingLevel << std::endl;
    std::cout << "SFML GL version: " << gotten.majorVersion << "." << gotten.minorVersion << std::endl;

    int version = gladLoadGL (sf::Context::getFunction);
    if (!version) {
        std::cerr << "Failure: error during glad loading." << std::endl;
        return 1;
    }
    std::cout << "GLAD GL version"<<GLAD_VERSION_MAJOR(version)<<"."<< GLAD_VERSION_MINOR(version)<<std::endl;



    //////////////////
    // What to draw //
    //////////////////

    // Coordinates in clip space! no transformation involved
    float points[] = {
        0.0f,  0.5f,  0.0f,  // x,y,z of first point
        0.5f, -0.5f,  0.0f,  // x,y,z of second point
       -0.5f, -0.5f,  0.0f   // x,y,z of third point
    };

    GLuint vbo;
    // We want just one buffer, and we retrieve the name OpenGL assigns to it.
    glGenBuffers (1, &vbo);
    // Bind it as the current VBO
    glBindBuffer (GL_ARRAY_BUFFER, vbo);
    // Transfer data from CPU RAM to GPU RAM.
    glBufferData (GL_ARRAY_BUFFER, sizeof (points), points, GL_STATIC_DRAW);

    GLuint vao;
    // Generate just one buffer container, and retrieve the name OpenGL assigns to it.
    glGenVertexArrays (1, &vao);
    // Bind it as the current vao.
    glBindVertexArray (vao);
    // Describe how the attribute 0 is organized inside our buffer
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    // Enable attribute 0 to be passed as input to the vertex shader
    glEnableVertexAttribArray (0);


    ////////////////////
    // How it's drawn //
    ////////////////////

    // Define shaders
    const char* vertex_source =
        "#version 410 core\n"
        "layout(location = 0) in vec3 vp;"
        "void main() {"
        "  gl_Position = vec4 (vp, 1.0);"
        "}";
    const char* fragment_source =
        "#version 410 core\n"
        "out vec4 frag_colour;"
        "void main() {"
        "  frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
        "}";

    // Compile, attach and link them
    GLuint vertex = glCreateShader (GL_VERTEX_SHADER);
    glShaderSource (vertex, 1, &vertex_source, NULL);
    glCompileShader (vertex);
    GLuint fragment = glCreateShader (GL_FRAGMENT_SHADER);
    glShaderSource (fragment, 1, &fragment_source, NULL);
    glCompileShader (fragment);
    GLuint shader_program = glCreateProgram();
    glAttachShader (shader_program, fragment);
    glAttachShader (shader_program, vertex);
    glLinkProgram (shader_program);

    // After linking the shaders, they can be safely deleted
    glDeleteShader (vertex);
    glDeleteShader (fragment);



    ///////////////
    // Main Loop //
    ///////////////

    // Put the shader program, and the VAO, in focus in OpenGL's state machin.
    // these can changed dynamically as needed in the loop too.
    glUseProgram (shader_program);
    glBindVertexArray (vao);

    bool running = true;
    while (running) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                running = false;
            else if (const auto* resized = event->getIf<sf::Event::Resized>())
                glViewport (0, 0, resized->size.x, resized->size.y);
        }

        // clear the buffers
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        /////////////
        // Draw!!! //
        /////////////

        // draw 3 vertices as a single triangle
        glDrawArrays (GL_TRIANGLES, 0, 3);

        // End the current frame (internally swaps the front and back buffers)
        window.display();
    }

    return 0;
}
