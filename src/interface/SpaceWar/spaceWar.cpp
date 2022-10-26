#include "spaceWar.h"
#include "ship.h"
#include "ResourceHolder.h"
#include "enemys.h"

#include "string"

Ship ship;
Enemys enemys;

void spaceWar(sf::RenderWindow& window){
    // Загрузка текстур
    TextureHolder.loadFromFile("../Textures/SpaceWar/Enemy/enemy.png", "enemy");

    //********************************************************

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
                enemys.
                window.setActive(false);
            }
        }

        if (clock.getElapsedTime() >= sf::seconds(2)){
            clock.restart();
        }

        ship.Move();

        window.clear();
        window.draw(bgSprite);
        ship.Draw(window);
        window.display();
    }
}