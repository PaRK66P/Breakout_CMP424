#pragma once

#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"

class Paddle
{
public:
    Paddle(sf::RenderWindow* window);
    ~Paddle();

    void resetValues();
    void moveLeft(float dt);
    void moveRight(float dt);
    void update(float dt);
    void render();
    void setPosition(sf::Vector2f);
    void moveToCenter();
    sf::FloatRect getBounds() const;
    float getXPosition();
    void setWidth(float coeff, float duration);

private:


    sf::RenderWindow* _window;
    sf::RectangleShape _sprite;
    float _width = PADDLE_WIDTH;
    bool _isAlive;
    float _timeInNewSize = 0.0f;
    bool _hasRotated;
    float _currentRotation = 0.0f;
    float _paddlePosition;
    float _timeTillRotationReset;
};
