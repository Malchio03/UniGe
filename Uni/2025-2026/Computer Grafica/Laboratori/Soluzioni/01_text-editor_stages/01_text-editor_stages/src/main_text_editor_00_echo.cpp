////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

////////////////////////////////////////////////////////////
/// GUI State
const int FONT_SIZE = 20;

struct State
{
    // General resources
    sf::RenderWindow window;
    const sf::Font font{"../resources/tuffy.ttf"};
    // Text buffer
    std::vector<std::string> log;

    State(unsigned w, unsigned h, std::string title)
    {
        window = sf::RenderWindow(sf::VideoMode({w, h}), title);
        // window.setVerticalSyncEnabled(true); // alternative to setFramerateLimit
        window.setFramerateLimit(60);
        log.resize(1, "");
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
    unsigned last = gs.log.size() - 1;
    // if (textEnter.unicode == 10 || textEnter.unicode == 13)
    if (textEnter.unicode == '\n' || textEnter.unicode == '\r') // enter
        gs.log.emplace_back("");
    else if (textEnter.unicode >= ' ' && textEnter.unicode <= '~') // printable char
    {
        gs.log[last] += static_cast<char>(textEnter.unicode);
    }
}

// void handle(const sf::Event::KeyPressed &keyPressed, State &gs)
// {
// }

// void handle(const sf::Event::MouseMoved &mouseMoved, State &gs)
// {
// }

// void handle(const sf::Event::MouseButtonPressed &, State &gs)
// {
// }

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

int main()
{
    State gs(800, 600, "Text echo");
    sf::Text logText{gs.font, "", FONT_SIZE};
    while (gs.window.isOpen()) // main loop
    {
        // event loop and handler through callbacks
        gs.window.handleEvents([&](const auto &event)
                               { handle(event, gs); });

        // Show log
        gs.window.clear();
        if (gs.log.size() > 24u) // Limit the log to the last 24 entries
            gs.log.erase(gs.log.begin(), gs.log.begin() + static_cast<int>(gs.log.size() - 24u));
        for (std::size_t i = 0; i < gs.log.size(); ++i)
        {
            logText.setPosition({50.f, static_cast<float>(i * FONT_SIZE) + 50.f});
            logText.setString(gs.log[i]);
            gs.window.draw(logText);
        }
        gs.window.display();
    }
}
