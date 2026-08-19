#include <SFML/Graphics.hpp>



//////////////////////
// Initial defaults //
//////////////////////

// window
const char* window_title = "01a - basic structure";
const unsigned window_width = 800;
const unsigned window_height = 600;
const float max_frame_rate = 60;

// ball
const float ball_initial_radius = 10.0;

// paddle
const sf::Vector2f paddle_initial_size = {100.0, 16.0};



///////////////////////////////////
// Internal state representation //
///////////////////////////////////

struct Ball
{
    float radius;
    sf::Vector2f pos;

    Ball ();
    void draw (sf::RenderWindow& window);
};

struct Paddle
{
    sf::Vector2f size;
    sf::Vector2f pos;

    Paddle ();
    void draw (sf::RenderWindow& window);
};

struct State
{
    Ball ball;
    Paddle paddle;

    State () {}
    void draw (sf::RenderWindow& window);
};

Ball::Ball ()
{
    radius = ball_initial_radius;
    float ball_px = ((float) window_width / 2.0) - ball_initial_radius;
    float ball_py = (float) window_height - paddle_initial_size.y - (ball_initial_radius * 2);
    pos = {ball_px, ball_py};
}

Paddle::Paddle ()
{
    size = paddle_initial_size;
    float paddle_px = ((float) window_width / 2.0) - (paddle_initial_size.x / 2.0);
    float paddle_py = (float) window_height - paddle_initial_size.y;
    pos = {paddle_px, paddle_py};
}



//////////
// Draw //
//////////

void Ball::draw (sf::RenderWindow& window)
{
    sf::CircleShape b (radius);
    b.setPosition (pos);
    window.draw (b);
}

void Paddle::draw (sf::RenderWindow& window)
{
    sf::RectangleShape p (size);
    p.setPosition (pos);
    window.draw (p);
}

void State::draw (sf::RenderWindow& window)
{
    ball.draw (window);
    paddle.draw (window);
}



////////////
// Events //
////////////

void handle_close (sf::RenderWindow& window)
{
    window.close();
}
void handle_resize (const sf::Event::Resized& resized, sf::RenderWindow& window)
{   // constrain aspect ratio and map always the same portion of the world
    float aspect = static_cast<float>(window_width)/static_cast<float>(window_height);
    sf::Vector2u ws = resized.size;
    float new_aspect = static_cast<float>(ws.x)/static_cast<float>(ws.y);
    if (new_aspect < aspect)
        ws = {ws.x,static_cast<unsigned>(ws.x/aspect)};
        else
        ws = {static_cast<unsigned>(ws.y*aspect),ws.y};
    window.setSize(ws);
}



//////////
// Loop //
//////////

int main()
{
    sf::RenderWindow window (sf::VideoMode ({window_width, window_height}), window_title);
    window.setFramerateLimit (max_frame_rate);
    window.setMinimumSize(window.getSize());

    State state;

    while (window.isOpen())
    {
        // events
        window.handleEvents (
                             [&window](const sf::Event::Closed&) { handle_close (window); },
                             [&window](const sf::Event::Resized& event) { handle_resize (event, window); }
        );

        // display
        window.clear (sf::Color::Black);
        state.draw (window);
        window.display ();
    }
}
