////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

////////////////////////////////////////////////////////////
/// GUI State

const int FONT_SIZE = 24;
const int FONT_WIDTH = 14;

struct State
{
    // General resources
    sf::RenderWindow window;
    const sf::Font font{"../resources/dejavu-sans-mono-font/DejavuSansMono-5m7L.ttf"};
    // Text buffer
    std::vector<std::string> log;

    // Positions in text coordinates (char, row)
    sf::Vector2i cursor_pos; // posizione del cursore
    sf::IntRect text_view;   // estensione della vista in coordinate testo

    State(unsigned w, unsigned h, std::string title)
    {
        window = sf::RenderWindow(sf::VideoMode({w, h}), title);
        // window.setVerticalSyncEnabled(true); // alternative to setFramerateLimit
        window.setFramerateLimit(60);
        log.resize(1, "");
        text_view = {{0, 0}, {static_cast<int>(window.getSize().x / FONT_WIDTH - 2), static_cast<int>(window.getSize().y / FONT_SIZE - 2)}};
        cursor_pos = {0, 0};
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
    if (textEnter.unicode == '\n' || textEnter.unicode == '\r') // enter
    {
        gs.cursor_pos.y++;
        gs.cursor_pos.x = 0;
        gs.log.emplace_back("");
    }
    else if (textEnter.unicode >= ' ' && textEnter.unicode <= '~')
    {
        gs.log[gs.cursor_pos.y] += static_cast<char>(textEnter.unicode);
        gs.cursor_pos.x++;
    }
}

void handle(const sf::Event::KeyPressed &keyPressed, State &gs)
{
}

void handle(const sf::Event::MouseMoved &mouseMoved, State &gs)
{
}

void handle(const sf::Event::MouseButtonPressed &, State &gs)
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
void doGraphics(State &gs)
{
    sf::Text logText{gs.font, "", FONT_SIZE};

    gs.window.clear();

    for (std::size_t i = 0; i < gs.log.size(); ++i)
    {
        logText.setPosition({FONT_WIDTH, static_cast<float>(i * FONT_SIZE) + FONT_SIZE});
        logText.setString(gs.log[i]);
        gs.window.draw(logText);
    }
    // show cursor
    logText.setPosition({
            static_cast<float>((gs.cursor_pos.x + 1) * FONT_WIDTH),
            static_cast<float>((gs.cursor_pos.y + 1) * FONT_SIZE + 3)});
    logText.setString("_");
    logText.setFillColor(sf::Color::Green);
    gs.window.draw(logText);

    gs.window.display();
}
///
////////////////////////////////////////////////////////////

int main()
{
    State gs(800, 600, "My Editor");

    while (gs.window.isOpen()) // main loop
    {
        // event loop and handler through callbacks
        gs.window.handleEvents([&](const auto &event)
                               { handle(event, gs); });

        // Show edited text (in view)
        doGraphics(gs);
    }
}
