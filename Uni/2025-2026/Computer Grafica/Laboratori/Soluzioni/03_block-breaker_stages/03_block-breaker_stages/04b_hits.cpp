#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Angle.hpp>

#include "textures.hpp"



//////////////////////
// Initial defaults //
//////////////////////

// window
const char* window_title = "04b - hits";
const unsigned window_width = 800;
const unsigned window_height = 600;
const float max_frame_rate = 60;

// ball
const float ball_initial_speed = 300.0;
const float ball_initial_radius = 10.0;
sf::Angle ball_initial_angle = sf::degrees (-70);
sf::Angle ball_left_max_angle = sf::degrees (-170);

// paddle
const float paddle_initial_speed = 400.0;
const sf::Vector2f paddle_initial_size = {100.0, 16.0};

// wall of blocks
const sf::Vector2f wall_displacement = {25.0, 100.0};
const sf::Vector2f wall_size = {750.0, 150.0};
const sf::Vector2i block_num = {16, 6};
const sf::Color block_fill_color = sf::Color(220, 200, 20);
const sf::Color block_outline_color = sf::Color(220, 140, 90);
const float block_outline_thickness = 2.0;



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
    bool hit (Ball &ball);
    void strike (Ball& ball);
};

struct Block
{
    sf::Vector2f pos;
    sf::Vector2f size;
    bool intact;

    Block (sf::Vector2f pos, sf::Vector2f size) : pos (pos),
                                                  size (size),
                                                  intact (true) {}
    void draw (sf::RenderWindow& window);
    bool is_inside (sf::Vector2f p);
    void hit (Ball& ball);
};

struct Wall
{
    std::vector<Block> blocks;

    Wall ();
    void draw (sf::RenderWindow& window);
    void hit (Ball& ball);
};

struct State
{
    Ball ball;
    Paddle paddle;
    Wall wall;

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
    void restart ();
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

Wall::Wall ()
{
    sf::Vector2f block_size = {
        wall_size.x / (float)block_num.x,
        wall_size.y / (float)block_num.y
    };
    for (int bx = 0; bx < block_num.x; bx++)
        for (int by = 0; by < block_num.y; by++) {
            sf::Vector2f block_pos = {
                (bx * block_size.x) + wall_displacement.x,
                (by * block_size.y) + wall_displacement.y
            };

            blocks.push_back (Block (block_pos, block_size));
        }
}

void State::restart ()
{
    paddle = Paddle ();
    ball = Ball ();
    wall = Wall ();
    move_paddle_left = false;
    move_paddle_right = false;
    pause = true;
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

void Block::draw (sf::RenderWindow& window)
{
    if (!intact)
        return;

    sf::RectangleShape s (size);
    s.setFillColor (block_fill_color);
    s.setOutlineThickness(block_outline_thickness);
    s.setOutlineColor(block_outline_color);
    s.setPosition (pos);
    window.draw (s);
}

void Wall::draw (sf::RenderWindow& window)
{
    for (auto& block : blocks)
        block.draw (window);
}

void State::draw (sf::RenderWindow& window)
{
    ball.draw (window);
    paddle.draw (window);
    wall.draw (window);
}



////////////
// Update //
////////////

// helper functions

float linear_interpolation (float v0, float v1, float t)
{
  return (1 - t) * v0 + t * v1;
}

sf::Angle reflect_horizontal (sf::Angle a)
{
    sf::Vector2f v (1.0, a);
    v.x = -v.x;
    return v.angle ();
}

sf::Angle reflect_vertical (sf::Angle a)
{
    sf::Vector2f v (1.0, a);
    v.y = -v.y;
    return v.angle ();
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

bool Paddle::hit (Ball& ball)
{
    sf::Vector2f v (1.0, ball.angle);
    return
        v.y > 0 &&
        ball.pos.y + ball.radius * 2.0 >= window_height - size.y &&
        ball.pos.x + ball.radius * 2.0 > pos.x &&
        ball.pos.x < pos.x + size.x;
}

void Paddle::strike (Ball& ball)
{
    if (!hit (ball))
        return;

    float ball_center_x = ball.pos.x + ball.radius;
    float paddle_center_x = pos.x + size.x / 2.0;
    float relative_normalized_distance =
        (ball_center_x - paddle_center_x) / (size.x + ball.radius * 2.0) + 0.5;
    sf::Angle ball_right_max_angle = reflect_horizontal (ball_left_max_angle);

    float new_angle_radians =
        linear_interpolation (ball_left_max_angle.asRadians (),
                              ball_right_max_angle.asRadians (),
                              relative_normalized_distance);
    sf::Angle new_angle = sf::radians (new_angle_radians);

    float ball_center_y = ball.pos.y + ball.radius;
    float paddle_center_y = pos.y + size.y / 2.0;
    if (ball_center_y > paddle_center_y)
        new_angle = reflect_vertical (new_angle);

    ball.angle = new_angle;
}

bool Block::is_inside (sf::Vector2f p)
{
    return
        p.x >= pos.x &&
        p.y >= pos.y &&
        p.x <= pos.x + size.x &&
        p.y <= pos.y + size.y;
}

void Block::hit (Ball& ball)
{
    sf::Vector2f center = {
        ball.pos.x + ball.radius,
        ball.pos.y + ball.radius
    };
    sf::Vector2f north = {
        center.x, center.y - ball.radius
    };
    sf::Vector2f east = {
        center.x + ball.radius, center.y
    };
    sf::Vector2f south = {
        center.x, center.y + ball.radius
    };
    sf::Vector2f west = {
        center.x - ball.radius, center.y
    };

    sf::Vector2f v (1.0, ball.angle);
    if (is_inside (north) && v.y < 0) {
        ball.angle = reflect_vertical (ball.angle);
        intact = false;
    }
    if (is_inside (east) && v.x > 0) {
        ball.angle = reflect_horizontal (ball.angle);
        intact = false;
    }
    if (is_inside (south) && v.y > 0) {
        ball.angle = reflect_vertical (ball.angle);
        intact = false;
    }
    if (is_inside (west) && v.x < 0) {
        ball.angle = reflect_horizontal (ball.angle);
        intact = false;
    }
}

void Wall::hit (Ball& ball)
{
    for (auto& block : blocks)
        if (block.intact) {
            block.hit (ball);
    }
}

void State::field_limits ()
{
    if (paddle.pos.x < 0.0)
        paddle.pos.x = 0.0;
    if (paddle.pos.x + paddle.size.x > window_width)
        paddle.pos.x = window_width - paddle.size.x;

    sf::Vector2f v (1.0, ball.angle);
    if (ball.pos.x <= 0.0 && v.x < 0)
        ball.angle = reflect_horizontal (ball.angle);
    if (ball.pos.x + ball.radius * 2.0 >= window_width && v.x > 0)
        ball.angle = reflect_horizontal (ball.angle);
    if (ball.pos.y <= 0.0 && v.y < 0)
        ball.angle = reflect_vertical (ball.angle);
    if (ball.pos.y > window_height)
        this->restart ();
}

void State::collisions ()
{
    field_limits ();
    paddle.strike (ball);
    wall.hit (ball);
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
