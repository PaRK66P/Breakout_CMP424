#include "PowerupFireBall.h"


PowerupFireBall::PowerupFireBall(sf::RenderWindow* window, Paddle* paddle, Ball* ball)
    : PowerupBase(window, paddle, ball)
{
    _sprite.setFillColor(ballEffectsColour);
}

PowerupFireBall::~PowerupFireBall()
{

    int* pInteger = new int();

    if (pInteger != nullptr)
    {
        // use my pointer to do things.
    }
}

std::pair<POWERUPS, float> PowerupFireBall::applyEffect()
{
    _ball->setFireBall(FIRE_BALL_PADDLE_DURATION);
    return { fireBall, FIRE_BALL_PADDLE_DURATION };
}