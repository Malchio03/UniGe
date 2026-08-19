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
/// GUI State

struct State
{
    sf::RenderWindow window;
    int menubar_height = 50;
    sf::Color colors[7] = {sf::Color::White, sf::Color::Red, sf::Color::Green, sf::Color::Blue,
                           sf::Color::Cyan, sf::Color::Yellow, sf::Color::Magenta};

    State(unsigned w, unsigned h, std::string title)
    {
        window = sf::RenderWindow(sf::VideoMode({w, h}), title);
    }
};

///
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
/// Funzioni callback
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
    float button_size = gs.menubar_height;
    float shape_radius = button_size * 3.0 / 10.0;
    sf::RectangleShape button({button_size, button_size});
    button.setFillColor(sf::Color::Transparent);
    button.setOutlineThickness(-3.f);
    sf::CircleShape shape(shape_radius);
    shape.setOrigin({shape_radius, shape_radius});
    for (int i = 0; i < 5; i++)
    {
        button.setPosition({button_size * i, 0});
        button.setOutlineColor(GRAY);
        gs.window.draw(button);
        shape.setPosition({static_cast<float>(button_size * (i + 0.5)), button_size / 2});
        if (i > 0)
            shape.setPointCount(2 + i);
        else
            shape.setPointCount(30);
        gs.window.draw(shape);
    }

    for (int i = 0; i < 7; i++)
    {
        button.setPosition({gs.window.getSize().x + button_size * (i - 7), 0});
        button.setOutlineColor(GRAY);
        button.setFillColor(gs.colors[i]);
        gs.window.draw(button);
    }
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
