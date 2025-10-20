#pragma once

// implemented powerups
enum POWERUPS
{
    bigPaddle,
    smallPaddle,
    fastBall,
    slowBall,
    fireBall,
    none
};

// Window settings
constexpr unsigned int WINDOW_WIDTH = 800;
constexpr unsigned int WINDOW_HEIGHT = 600;
constexpr const char* WINDOW_TITLE = "Breakout";

// Paddle settings
constexpr float PADDLE_WIDTH = 150.0f;
constexpr float PADDLE_HEIGHT = 20.0f;
constexpr float PADDLE_SPEED = 300.0f;
constexpr float PADDLE_ROTATION = 15.0f;
constexpr float PADDLE_ROTATION_RESET_TIME = 0.1f;
constexpr float PADDLE_MOUSE_BUFFER_SPACE = 10.0f;
const sf::Vector2f PADDLE_START_POSITION = sf::Vector2f(325, 550);

// Ball settings
constexpr float BALL_RADIUS = 10.0f;
constexpr float BALL_SPEED = 400.0f;

// Brick settings
constexpr float BRICK_WIDTH = 75.0f;
constexpr float BRICK_HEIGHT = 20.0f;
constexpr float BRICK_PADDING = 5.0f;
constexpr float BRICK_TOP_PADDING = 100.0f;
constexpr int BRICK_ROWS = 5;
constexpr int BRICK_COLUMNS = 10;

// Power-up settings
constexpr float POWERUP_RADIUS = 20.0f;             // size of powerup on screen
constexpr float POWERUP_FLOAT_DOWN_SPEED = 250.0f;  // speed of fall
constexpr float POWERUP_APLITUDE_OF_FALL = 80.0f;   // waviness of fall
constexpr float POWERUP_INITIAL_Y = 5;
constexpr float POWERUP_INITIAL_WIDTH_PADDING = 0.05; // percentage of screen width away from either side
constexpr float POWERUP_INITIAL_WIDTH = 1 - (2 * POWERUP_INITIAL_WIDTH_PADDING);
constexpr float POWERUP_FREQUENCY = 7.5f;           // time between minimum powerup spawn
constexpr int POWERUP_SPAWN_CHANCE = 700;

// Big paddle settings
constexpr float BIG_PADDLE_WIDTH_COEFFICIENT = 1.5f;
constexpr float BIG_PADDLE_DURATION = 5.0f;
const std::string BIG_PADDLE_TEXT = "Big";

// Small paddle settings
constexpr float SMALL_PADDLE_WIDTH_COEFFICIENT = 0.67f;
constexpr float SMALL_PADDLE_DURATION = 5.0f;
const std::string SMALL_PADDLE_TEXT = "Small";

// Fast ball settings
constexpr float FAST_BALL_VELOCITY_COEFFICIENT = 2.0f;
constexpr float FAST_BALL_PADDLE_DURATION = 5.0f;
const std::string FAST_BALL_TEXT = "Fast";

// Slow ball settings
constexpr float SLOW_BALL_VELOCITY_COEFFICIENT = 0.5f;
constexpr float SLOW_BALL_PADDLE_DURATION = 5.0f;
const std::string SLOW_BALL_TEXT = "Slow";

// Fire ball settings
constexpr float FIRE_BALL_PADDLE_DURATION = 5.0f;
const std::string FIRE_BALL_TEXT = "Fire";

// UI settings
constexpr float UI_LIFE_RADIUS = 15.0f;
constexpr float UI_LIFE_PADDING = 20.0f;
constexpr float UI_LIFE_OUTLINE_THICKNESS = 4.0f;

// Text settings
constexpr unsigned int MASTER_TEXT_SIZE = 48;
const sf::Vector2f MASTER_TEXT_POSITION = sf::Vector2f(50, 400);
constexpr unsigned int MESSAGING_SYSTEM_TEXT_SIZE = 24;
const sf::Vector2f MESSAGING_SYSTEM_TEXT_POSITION = sf::Vector2f(10, 10);
constexpr unsigned int POWERUP_TEXT_SIZE = 30;
const sf::Vector2f POWERUP_TEXT_POSITION = sf::Vector2f(600, 10);

// Other game settings
constexpr float PAUSE_TIME_BUFFER = 0.5f;
constexpr int INITIAL_LIVES = 3;

// Colour Palette
const sf::Color ballEffectsColour = sf::Color(100, 100, 200, 255); // blue-ish?
const sf::Color paddleEffectsColour = sf::Color(255, 250, 205); // lemon chiffon -- very fancy.
const sf::Color extraBallEffectsColour = sf::Color(41, 110, 1); // metallic green
const sf::Color masterTextColour = sf::Color::Yellow; // yellow
const sf::Color messagingSystemTextColour = sf::Color::White; // white
const sf::Color powerupTextColor = sf::Color::Cyan; // cyan
const sf::Color lifeFillColour = sf::Color::Red; // red
const sf::Color lifeOutlineColour = sf::Color::Cyan; // cyan

// Font filenames
const std::string  montSFont = "font/montS.ttf";

// Text string messages
const std::string emptyStringMessage = "";
const std::string gameOverStringMessage = "Game Over";
const std::string levelCompleteStringMessage = "Level Completed";
const std::string pauseStringMessage = "Paused";


