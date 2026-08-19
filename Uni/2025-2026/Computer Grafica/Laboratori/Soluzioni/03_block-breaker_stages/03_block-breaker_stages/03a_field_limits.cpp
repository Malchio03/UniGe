#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Angle.hpp>

#include "textures.hpp"



//////////////////////
// Initial defaults //
//////////////////////

// window
const char* window_title = "03a - field limits";
const unsigned window_width = 800;
const unsigned window_height = 600;
const float max_frame_rate = 60;

// ball
const float ball_initial_speed = 300.0;
const float ball_initial_radius = 20.0;
sf::Angle ball_initial_angle = sf::degrees(-70);

// paddle
const float paddle_initial_speed = 400.0;
const sf::Vector2f paddle_initial_size = {160.0, 20.0};



///////////////////////////////////
// Internal state representation //
///////////////////////////////////

struct Ball
{
    float radius;
    sf::Vector2f pos;
    sf::Texture texture;
    float speed;
    sf::Angle angle;

    Ball ();
    void draw (sf::RenderWindow& window);
    void move (float elapsed);
};

struct Paddle
{
    sf::Vector2f size;
    sf::Vector2f pos;
    sf::Texture texture;
    float speed;

    Paddle ();
    void draw (sf::RenderWindow& window);
    void move_left (float elapsed);
    void move_right (float elapsed);
};

struct State
{
    Ball ball;
    Paddle paddle;
    bool move_paddle_left;
    bool move_paddle_right;
    bool pause;
    bool focus;

    State () : ball(),
               paddle(),
               move_paddle_left(false),
               move_paddle_right(false),
               pause(true),
               focus(false) {}
    void draw (sf::RenderWindow& window);
    void field_limits ();
    void collisions ();
    void update (float elapsed);
};

Ball::Ball ()
{
    radius = ball_initial_radius;
    float ball_px = ((float) window_width / 2.0) - ball_initial_radius;
    float ball_py = (float) window_height - paddle_initial_size.y - (ball_initial_radius * 2);
    pos = {ball_px, ball_py};
    texture = sf::Texture (ball_png, ball_png_len);
    speed = ball_initial_speed;
    angle = ball_initial_angle;
}

Paddle::Paddle ()
{
    size = paddle_initial_size;
    float paddle_px = ((float) window_width / 2.0) - (paddle_initial_size.x / 2.0);
    float paddle_py = (float) window_height - paddle_initial_size.y;
    pos = {paddle_px, paddle_py};
    texture = sf::Texture (paddle_png, paddle_png_len);
    speed = paddle_initial_speed;
}



//////////
// Draw //
//////////

void Ball::draw (sf::RenderWindow& window)
{
    sf::CircleShape b (radius);
    b.setTexture (&texture);
    b.setPosition (pos);
    window.draw (b);
}

void Paddle::draw (sf::RenderWindow& window)
{
    sf::RectangleShape p (size);
    p.setTexture (&texture);
    p.setPosition (pos);
    window.draw (p);
}

void State::draw (sf::RenderWindow& window)
{
    ball.draw (window);
    paddle.draw (window);
}



////////////
// Update //
////////////

// helper functions

sf::Angle reflect_horizontal (sf::Angle a)
{
    sf::Vector2f v (1.0, a);
    v.x = -v.x;
    return v.angle();
}

sf::Angle reflect_vertical (sf::Angle a)
{
    sf::Vector2f v (1.0, a);
    v.y = -v.y;
    return v.angle();
}

// class members implementation

void Ball::move (float elapsed)
{
    sf::Vector2f displacement (speed * elapsed, angle);
    pos += displacement;
}

void Paddle::move_left (float elapsed)
{
    pos.x -= speed * elapsed;
}

void Paddle::move_right (float elapsed)
{
    pos.x += speed * elapsed;
}

void State::field_limits ()
{
    if (paddle.pos.x < 0.0)
        paddle.pos.x = 0.0;
    if (paddle.pos.x + paddle.size.x > window_width)
        paddle.pos.x = window_width - paddle.size.x;

    if (ball.pos.x <= 0.0)
        ball.angle = reflect_horizontal (ball.angle);
    if (ball.pos.x + ball.radius * 2.0 >= window_width)
        ball.angle = reflect_horizontal (ball.angle);
    if (ball.pos.y <= 0.0)
        ball.angle = reflect_vertical (ball.angle);

    if (ball.pos.y + ball.radius * 2.0 >= window_height - paddle_initial_size.y)
    // if (ball.pos.y + ball.radius * 2.0 >= window_height - paddle_initial_size.y * 3.0)
        ball.angle = reflect_vertical (ball.angle);
}

void State::collisions ()
{
    field_limits ();
}

void State::update (float elapsed)
{
    if (pause)
        return;

    ball.move (elapsed);

    if (move_paddle_left)
        paddle.move_left (elapsed);
    if (move_paddle_right)
        paddle.move_right (elapsed);

    collisions ();
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

template <typename T>
void handle (T& event, State& state) {}

void handle (const sf::Event::KeyPressed& key, State& state)
{
    if (!state.focus)
        return;

    switch (key.scancode) {
    case sf::Keyboard::Scancode::Space:
        state.pause = !state.pause;
        return;
    case sf::Keyboard::Scancode::Left:
        state.move_paddle_left = true;
        return;
    case sf::Keyboard::Scancode::Right:
        state.move_paddle_right = true;
        return;
    default:
        return;
    }
}

void handle (const sf::Event::KeyReleased& key, State& state)
{
    if (!state.focus)
        return;

    switch (key.scancode) {
    case sf::Keyboard::Scancode::Left:
        state.move_paddle_left = false;
        return;
    case sf::Keyboard::Scancode::Right:
        state.move_paddle_right = false;
        return;
    default:
        return;
    }
}

void handle (const sf::Event::FocusGained&, State& state)
{
    state.focus = true;
}

void handle (const sf::Event::FocusLost&, State& state)
{
    state.pause = true;
    state.focus = false;
}



//////////
// Loop //
//////////

int main()
{
    sf::RenderWindow window (sf::VideoMode ({window_width, window_height}), window_title);
    window.setFramerateLimit (max_frame_rate);

    State state;
    sf::Clock clock;

    while (window.isOpen())
    {
        // events
        window.handleEvents (
                             [&window](const sf::Event::Closed&) { handle_close (window); },
                             [&window](const sf::Event::Resized& event) { handle_resize (event, window); },
                             [&state] (const auto& event) { handle (event, state); }
        );

        // update
        state.update (clock.restart().asSeconds());

        // display
        window.clear (sf::Color::Black);
        state.draw (window);
        window.display ();
    }
}
