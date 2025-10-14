#include "PowerupBigPaddle.h"

PowerupBigPaddle::PowerupBigPaddle(sf::RenderWindow* window, Paddle* paddle, Ball* ball)
    : PowerupBase(window, paddle, ball)
{
    _sprite.setFillColor(paddleEffectsColour); // Same colour as smallPaddle
}

PowerupBigPaddle::~PowerupBigPaddle()
{
}

std::pair<POWERUPS,float> PowerupBigPaddle::applyEffect()
{
    _paddle->setWidth(BIG_PADDLE_WIDTH_COEFFICIENT, BIG_PADDLE_DURATION);
    return { bigPaddle, BIG_PADDLE_DURATION };
}