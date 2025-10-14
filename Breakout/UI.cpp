#include <sstream>

#include "UI.h"
#include "GameManager.h"
#include <iomanip>

UI::UI(sf::RenderWindow* window, int lives, GameManager* gameManager) 
	: _window(window), _gameManager(gameManager)
{
	_powerupText.setCharacterSize(POWERUP_TEXT_SIZE);
	_powerupText.setPosition(POWERUP_TEXT_POSITION);
	_powerupText.setFillColor(powerupTextColor);
	_font.loadFromFile(montSFont);
	_powerupText.setFont(_font);
}

UI::~UI()
{
}

void UI::setLives(int lives)
{
	_lives.clear();
	
	for (int i = lives; i > 0; --i)
	{
		sf::CircleShape newLife;
		newLife.setFillColor(lifeFillColour);	
		newLife.setOutlineColor(lifeOutlineColour);
		newLife.setOutlineThickness(UI_LIFE_OUTLINE_THICKNESS);
		newLife.setRadius(UI_LIFE_RADIUS);
		newLife.setPosition((UI_LIFE_RADIUS*2 + UI_LIFE_PADDING) * i, UI_LIFE_PADDING);
		_lives.push_back(newLife);
	}

	_powerupText.setString(emptyStringMessage);
}


void UI::updatePowerupText(std::pair<POWERUPS, float> powerup)
{
	std::ostringstream oss;

	switch (powerup.first)
	{
	case bigPaddle:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString(BIG_PADDLE_TEXT + " " + oss.str());
		_powerupText.setFillColor(paddleEffectsColour);
		break;
	case smallPaddle:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString(SMALL_PADDLE_TEXT + " " + oss.str());
		_powerupText.setFillColor(paddleEffectsColour);
		break;
	case slowBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString(SLOW_BALL_TEXT + " " + oss.str());
		_powerupText.setFillColor(ballEffectsColour);
		break;
	case fastBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString(FAST_BALL_TEXT + " " + oss.str());
		_powerupText.setFillColor(ballEffectsColour);
		break;
	case fireBall:
		oss << std::fixed << std::setprecision(2) << powerup.second;
		_powerupText.setString(FIRE_BALL_TEXT + " " + oss.str());
		_powerupText.setFillColor(extraBallEffectsColour);
		break;
	case none:
		_powerupText.setString(emptyStringMessage);
		
		break;
	}
}

void UI::lifeLost(int lives)
{
	_lives[_lives.size() - 1 - lives].setFillColor(sf::Color::Transparent);
}

void UI::render()
{
	_window->draw(_powerupText);
	for (sf::CircleShape life : _lives)
	{
		_window->draw(life);
	}
}