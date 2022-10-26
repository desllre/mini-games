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
                window.setActive(false);
            }
        }

        if (clock.getElapsedTime() >= sf::seconds(2)){
            enemys.AddEnemy("enemy");
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