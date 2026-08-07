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

    void adjustView()
    {
        text_view.size = {static_cast<int>(window.getSize().x / FONT_WIDTH - 2),
                          static_cast<int>(window.getSize().y / FONT_SIZE - 2)};
        text_view.position.x = std::min(text_view.position.x, cursor_pos.x);
        text_view.position.y = std::min(text_view.position.y, cursor_pos.y);
        text_view.position.x = std::max(text_view.position.x, cursor_pos.x - text_view.size.x + 1);
        text_view.position.y = std::max(text_view.position.y, cursor_pos.y - text_view.size.y + 1);
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
    gs.adjustView();
}

void handle(const sf::Event::KeyPressed &keyPressed, State &gs)
{
    if (keyPressed.scancode == sf::Keyboard::Scancode::Up)
    {
        if (gs.cursor_pos.y > 0)
        {
            gs.cursor_pos.y--;
            gs.cursor_pos.x = std::min(gs.cursor_pos.x, (int)gs.log[gs.cursor_pos.y].size());
        }
    }
    else if (keyPressed.scancode == sf::Keyboard::Scancode::Down)
    {
        if (gs.cursor_pos.y < gs.log.size() - 1)
        {
            gs.cursor_pos.y++;
            gs.cursor_pos.x = std::min(gs.cursor_pos.x, (int)gs.log[gs.cursor_pos.y].size());
        }
    }
    else if (keyPressed.scancode == sf::Keyboard::Scancode::Left)
    {
        if (gs.cursor_pos.x > 0 || gs.cursor_pos.y > 0)
        {
            gs.cursor_pos.x--;
            if (gs.cursor_pos.x < 0)
            {
                gs.cursor_pos.y--;
                gs.cursor_pos.x = gs.log[gs.cursor_pos.y].size();
            }
        }
    }
    else if (keyPressed.scancode == sf::Keyboard::Scancode::Right)
    {
        if (gs.cursor_pos.y < gs.log.size() - 1 || gs.cursor_pos.x < gs.log[gs.cursor_pos.y].size())
        {
            gs.cursor_pos.x++;
            if (gs.cursor_pos.x > gs.log[gs.cursor_pos.y].size())
            {
                gs.cursor_pos.y++;
                gs.cursor_pos.x = 0;
            }
        }
    }
    gs.adjustView();
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
    gs.adjustView();
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

    // show text in view
    unsigned lines_to_print = std::min(static_cast<unsigned>(gs.log.size() - gs.text_view.position.y),
                                       static_cast<unsigned>(gs.text_view.size.y));
    for (unsigned i = 0; i < lines_to_print; ++i)
    {
        logText.setPosition({FONT_WIDTH, static_cast<float>(i * FONT_SIZE) + FONT_SIZE});
        if (gs.text_view.position.x < gs.log[i + gs.text_view.position.y].size())
        {
            logText.setString(gs.log[i + gs.text_view.position.y].substr((size_t)gs.text_view.position.x, (size_t)gs.text_view.size.x));
            gs.window.draw(logText);
        }
    }
    // show cursor
    logText.setPosition({static_cast<float>((gs.cursor_pos.x - gs.text_view.position.x + 1) * FONT_WIDTH),
        static_cast<float>((gs.cursor_pos.y - gs.text_view.position.y + 1) * FONT_SIZE + 3)});
        // static_cast<float>((gs.cursor_pos.y - gs.text_view.position.y) * FONT_SIZE)});
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
