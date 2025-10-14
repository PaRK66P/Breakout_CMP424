#include "PowerupSlowBall.h"

PowerupSlowBall::PowerupSlowBall(sf::RenderWindow* window, Paddle* paddle, Ball* ball)
    : PowerupBase(window, paddle, ball)
{
    _sprite.setFillColor(ballEffectsColour); 
}

PowerupSlowBall::~PowerupSlowBall()
{
}

std::pair<POWERUPS, float> PowerupSlowBall::applyEffect()
{
    _ball->setVelocity(SLOW_BALL_VELOCITY_COEFFICIENT, SLOW_BALL_PADDLE_DURATION);
    return { slowBall, SLOW_BALL_PADDLE_DURATION };
}