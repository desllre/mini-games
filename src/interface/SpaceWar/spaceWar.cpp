#include "spaceWar.h"
#include "ship.h"

Ship ship;

void spaceWar(sf::RenderWindow& window){
    window.setActive();

    sf::Texture bgTexture;
    bgTexture.loadFromFile("../Textures/SpaceWar/space.png");
    sf::Sprite bgSprite(bgTexture);

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
        window.clear();
        window.draw(bgSprite);
        ship.Draw(window);
        window.display();
    }
}