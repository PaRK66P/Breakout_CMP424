#include "PowerupFastBall.h"

PowerupFastBall::PowerupFastBall(sf::RenderWindow* window, Paddle* paddle, Ball* ball)
    : PowerupBase(window, paddle, ball)
{
    _sprite.setFillColor(ballEffectsColour);
}

PowerupFastBall::~PowerupFastBall()
{
}

std::pair<POWERUPS, float> PowerupFastBall::applyEffect()
{
    _ball->setVelocity(FAST_BALL_VELOCITY_COEFFICIENT, FAST_BALL_PADDLE_DURATION);
    return { fastBall, FAST_BALL_PADDLE_DURATION };
}