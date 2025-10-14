#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "CONSTANTS.h"
#include <iostream>

int main()
{

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    GameManager gameManager(&window);
    gameManager.initialize();

    sf::Clock clock;
    float deltaTime;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        deltaTime = clock.restart().asSeconds();

        gameManager.update(deltaTime);

        window.clear();
        gameManager.render();
        window.display();
    }

    return 0;
}
