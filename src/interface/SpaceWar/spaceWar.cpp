#include "spaceWar.h"
#include "string"

#include "iostream"

void spaceWar(sf::RenderWindow& window){

    Ship ship;
    Enemys enemys;

    window.setActive();

    sf::Texture bgTexture;
    bgTexture.loadFromFile("../Textures/SpaceWar/space.png");
    sf::Sprite bgSprite(bgTexture);

    sf::Clock enemyClock, shootClock;

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

        if (enemyClock.getElapsedTime() >= sf::seconds(2)){
            enemys.AddEnemy();
            enemyClock.restart();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootClock.getElapsedTime() >= sf::seconds(0.4)){
            ship.Shoot();
            shootClock.restart();
        }

        ship.Move(enemys);

        window.clear();

        window.draw(bgSprite);

        enemys.Draw(window);
        ship.Draw(window);

        window.display();
    }
}

