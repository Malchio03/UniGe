////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <math.h>

////////////////////////////////////////////////////////////
/// Utility

template <typename T1, typename T2>
double dist(sf::Vector2<T1> p1, sf::Vector2<T2> p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

const sf::Color GRAY(128, 128, 128, 255);

///
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// GUI state

struct State
{
    sf::RenderWindow window;

    State(unsigned w, unsigned h, std::string title)
    {
        window = sf::RenderWindow(sf::VideoMode({w, h}), title);
    }
};

///
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// Callback functions
void handle(const sf::Event::Closed &, State &gs)
{
    gs.window.close();
}

void handle(const sf::Event::TextEntered &textEnter, State &gs)
{
}

void handle(const sf::Event::KeyPressed &keyPressed, State &gs)
{
}

void handle(const sf::Event::MouseMoved &mouseMoved, State &gs)
{
}

void handle(const sf::Event::MouseButtonPressed &mouseBP, State &gs)
{
}

void handle(const sf::Event::MouseButtonReleased &, State &gs)
{
}

void handle(const sf::Event::Resized &resized, State &gs)
{
    sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized.size));
    gs.window.setView(sf::View(visibleArea));
}

template <typename T>
void handle(const T &, State &gs)
{
    // All unhandled events will end up here
}
///
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// Graphics
void doGUI(State &gs)
{
    // TODO: here code to display the menus
}

void doGraphics(State &gs)
{
    gs.window.clear();
    doGUI(gs);

    // TODO: add here code to display shapes in your canvas

    gs.window.display();
}
///
////////////////////////////////////////////////////////////

int main()
{
    State gs(800, 600, "Draw shapes");
    gs.window.setFramerateLimit(50);

    while (gs.window.isOpen()) // main loop
    {
        // event loop and handler through callbacks
        gs.window.handleEvents([&](const auto &event)
                               { handle(event, gs); });
        // Show update
        doGraphics(gs);
    }
}
