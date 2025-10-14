#include "GameManager.h"
#include "Ball.h"
#include "PowerupManager.h"
#include <iostream>

GameManager::GameManager(sf::RenderWindow* window)
    : _window(window), _paddle(nullptr), _ball(nullptr), _brickManager(nullptr), _powerupManager(nullptr),
    _messagingSystem(nullptr), _ui(nullptr), _pause(false), _time(0.f), _lives(INITIAL_LIVES), _pauseHold(0.f), _levelComplete(false),
    _powerupInEffect({ none,0.f }), _timeLastPowerupSpawned(0.f)
{
    _font.loadFromFile(montSFont);
    _masterText.setFont(_font);
    _masterText.setPosition(MASTER_TEXT_POSITION);
    _masterText.setCharacterSize(MASTER_TEXT_SIZE);
    _masterText.setFillColor(masterTextColour);
}

void GameManager::initialize()
{
    _paddle = new Paddle(_window);
    _brickManager = new BrickManager(_window, this);
    _messagingSystem = new MessagingSystem(_window);
    _ball = new Ball(_window, BALL_SPEED, this); 
    _powerupManager = new PowerupManager(_window, _paddle, _ball);
    _ui = new UI(_window, _lives, this);

    createGame();
}

void GameManager::update(float dt)
{
    _powerupInEffect = _powerupManager->getPowerupInEffect();
    _ui->updatePowerupText(_powerupInEffect);
    _powerupInEffect.second -= dt;
    

    if (_lives <= 0)
    {
        _masterText.setString(gameOverStringMessage);
        resetGameCheck();
        
        return;
    }
    if (_levelComplete)
    {
        _masterText.setString(levelCompleteStringMessage);
        resetGameCheck();
        
        return;
    }
    // pause and pause handling
    if (_pauseHold > 0.f) _pauseHold -= dt;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        if (!_pause && _pauseHold <= 0.f)
        {
            _pause = true;
            _masterText.setString(pauseStringMessage);
            _pauseHold = PAUSE_TIME_BUFFER;
        }
        if (_pause && _pauseHold <= 0.f)
        {
            _pause = false;
            _masterText.setString(emptyStringMessage);
            _pauseHold = PAUSE_TIME_BUFFER;
        }
    }
    if (_pause)
    {
        return;
    }

    // timer.
    _time += dt;


    if (_time > _timeLastPowerupSpawned + POWERUP_FREQUENCY && rand() % POWERUP_SPAWN_CHANCE == 0)
    {
        _powerupManager->spawnPowerup();
        _timeLastPowerupSpawned = _time;
    }

    // move paddle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _paddle->moveRight(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _paddle->moveLeft(dt);

    // update everything 
    _paddle->update(dt);
    _ball->update(dt);
    _powerupManager->update(dt);
}

void GameManager::loseLife()
{
    _lives--;
    _ui->lifeLost(_lives);

    // TODO screen shake.
}

void GameManager::render()
{
    _paddle->render();
    _ball->render();
    _brickManager->render();
    _powerupManager->render();
    _window->draw(_masterText);
    _ui->render();
}

void GameManager::levelComplete()
{
    _levelComplete = true;
}


void GameManager::resetGameCheck()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        createGame();
    }
}

void GameManager::createGame()
{
    _time = 0.0f;
    _timeLastPowerupSpawned = 0.0f;
    _lives = INITIAL_LIVES;
    _levelComplete = false;
    _powerupInEffect = {none, 0.0f};
    _masterText.setString(emptyStringMessage);
    
    _paddle->resetValues();
    _messagingSystem->setMessage(emptyStringMessage, 0);
    _ball->resetBallValues();
    _powerupManager->resetManager();
    _ui->setLives(INITIAL_LIVES);
    
    // Create bricks
    _brickManager->createBricks(BRICK_ROWS, BRICK_COLUMNS, BRICK_WIDTH, BRICK_HEIGHT, BRICK_PADDING);
}

sf::RenderWindow* GameManager::getWindow() const { return _window; }
UI* GameManager::getUI() const { return _ui; }
Paddle* GameManager::getPaddle() const { return _paddle; }
BrickManager* GameManager::getBrickManager() const { return _brickManager; }
PowerupManager* GameManager::getPowerupManager() const { return _powerupManager; }
