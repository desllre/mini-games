#include "spaceWar.h"
#include "ship.h"
#include "enemy.h"

Enemys enemys;
Ship ship;

void spaceWar(sf::RenderWindow& window){
    window.setActive();

    sf::Texture bgTexture;
    bgTexture.loadFromFile("../Textures/SpaceWar/space.png");
    sf::Sprite bgSprite(bgTexture);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                window.setActive(false);
            }
        }
        if (clock.getElapsedTime() >= sf::seconds(2)){
            enemys.CreateEnemy();
            clock.restart();
        }

        ship.Move();

        window.clear();
        window.draw(bgSprite);
        enemys.Draw(window);
        ship.Draw(window);
        window.display();
    }
}