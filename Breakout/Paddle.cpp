#include "Paddle.h"
#include "CONSTANTS.h"
#include <iostream>

Paddle::Paddle(sf::RenderWindow* window)
    : _window(window), _width(PADDLE_WIDTH), _timeInNewSize(0.0f), _isAlive(true)
{
    _sprite.setFillColor(sf::Color::Cyan);
    moveToCenter();
    _sprite.setSize(sf::Vector2f(_width, PADDLE_HEIGHT));
}

Paddle::~Paddle()
{
}

void Paddle::resetValues()
{
    moveToCenter();
    _timeInNewSize = 0.0f;
    _isAlive = true;

    _hasRotated = false;
    _sprite.setRotation(0.0f);
}

void Paddle::moveLeft(float dt)
{
    if (_paddlePosition > 0)
    {
        _paddlePosition -= dt * PADDLE_SPEED;
        
        _sprite.setPosition(sf::Vector2f(_paddlePosition, PADDLE_START_POSITION.y));
    }
    _hasRotated = true;
    _currentRotation = -15.0f;
}

void Paddle::moveRight(float dt)
{
    if (_paddlePosition < static_cast<float>(WINDOW_WIDTH) - _width)
    {
        _paddlePosition += dt * PADDLE_SPEED;
    }
    _hasRotated = true;
    _currentRotation = 15.0f;
}

void Paddle::update(float dt)
{
    
    _sprite.setPosition(sf::Vector2f(_paddlePosition, PADDLE_START_POSITION.y));
    
    if (!_hasRotated)
    {
        if (_timeTillRotationReset > 0.f)
        {
            _timeTillRotationReset = std::max(_timeTillRotationReset - dt, 0.0f);

            float rotation = _currentRotation;
            float scalar = rotation < 0.0f ? -1 : 1;

            float tweeningValue = _timeTillRotationReset / PADDLE_ROTATION_RESET_TIME;
            float tweeningScalar = tweeningValue < 0.5 ? 2 * tweeningValue * tweeningValue : 1 - ((-2 * tweeningValue + 2) * (-2 * tweeningValue + 2)) / 2;

            _sprite.setRotation(rotation * tweeningScalar);

            _sprite.move(sf::Vector2f(0.0f, (-_width * sin(rotation)) * tweeningScalar / 4.0f));
            
        }
    }
    else
    {
        _timeTillRotationReset = PADDLE_ROTATION_RESET_TIME;
        _sprite.setRotation(_currentRotation);

        _sprite.move(sf::Vector2f(0.0f, (-_width * sin(_currentRotation)) / 4.0f));
        _hasRotated = false;
    }
    
    
    if (_timeInNewSize > 0)
    {
        _timeInNewSize -= dt;
    }
    else
    {
        setWidth(1.0f, 0.0f); // Reset to default width after duration
    }
}

void Paddle::render()
{
    _window->draw(_sprite);
}

void Paddle::setPosition(sf::Vector2f newPosition)
{
    _paddlePosition = newPosition.x;
    _sprite.setPosition(sf::Vector2f(_paddlePosition, PADDLE_START_POSITION.y));
}

void Paddle::moveToCenter()
{
    setPosition(sf::Vector2f(PADDLE_START_POSITION));
    _paddlePosition = PADDLE_START_POSITION.x;
}

sf::FloatRect Paddle::getBounds() const
{
    return _sprite.getGlobalBounds();
}

float Paddle::getXPosition()
{
    return _paddlePosition + _width / 2.0f;
}

// update width by SF of coeff. 
// ensure centre remains consistent.
void Paddle::setWidth(float coeff, float duration)
{
    _width = coeff * PADDLE_WIDTH;
    _sprite.setSize(sf::Vector2f(_width, _sprite.getSize().y));
    _timeInNewSize = duration;
    float newX = _sprite.getPosition().x + (_width - PADDLE_WIDTH) / 2;
    _sprite.setPosition(newX, _sprite.getPosition().y);
}
