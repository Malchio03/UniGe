#define GLAD_GL_IMPLEMENTATION // Necessary for the header-only version.
#include "glad/gl.h" // See file to check used options and generator URL

#include <SFML/Window.hpp>
#include <iostream>



int main()
{
    /////////////////////////////
    // Window and OpenGL setup //
    /////////////////////////////

    // Options for OpenGL context, to be kept in sync with GLAD options!
    sf::ContextSettings settings;
    settings.depthBits = 32;
    settings.stencilBits = 8;
    settings.antiAliasingLevel = 4;
    settings.attributeFlags = sf::ContextSettings::Attribute::Core;
    settings.majorVersion = 4;
    settings.minorVersion = 1;

    // Create the window with chosen options
    sf::Window window(
        sf::VideoMode({800, 600}),
        "SFML + OpenGL",
        sf::Style::Default,
        sf::State::Windowed,
        settings
    );
    window.setVerticalSyncEnabled (true);

    // Activate the window's OpenGL context
    if (!window.setActive (true)) {
        std::cerr << "Failure: error during SFML OpenGL Activation." << std::endl;
        return 1;
    }

    // Check what we have received back
    sf::ContextSettings gotten = window.getSettings();
    std::cout << "depth bits: " << gotten.depthBits << std::endl;
    std::cout << "stencil bits: " << gotten.stencilBits << std::endl;
    std::cout << "antialiasing level: " << gotten.antiAliasingLevel << std::endl;
    std::cout << "SFML GL version: " << gotten.majorVersion << "." << gotten.minorVersion << std::endl;

    // GLAD magic!
    // SFML provides a function to retrieve OpenGL's functions at runtime
    // GLAD uses it to load all the OpenGL functions that are needed for our configuration
    int version = gladLoadGL (sf::Context::getFunction);
    if (!version) {
        std::cerr << "Failure: error during glad loading." << std::endl;
        return 1;
    }
    // Final check that we got what we want
    std::cout << "GLAD GL version: "<<GLAD_VERSION_MAJOR(version)<<"."<< GLAD_VERSION_MINOR(version)<<std::endl;


    ///////////////
    // Main Loop //
    ///////////////

    bool running = true;
    while (running) {
        // handle events
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
            {
                // end the program
                running = false;
            }
            else if (const auto* resized = event->getIf<sf::Event::Resized>())
            {
                // adjust the viewport when the window is resized
                glViewport (0, 0, resized->size.x, resized->size.y);
            }
        }

        // clear the buffers
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw here

        // end the current frame (internally swaps the front and back buffers)
        window.display();
    }

    return 0;
}
