#include "spaceWar.h"

void spaceWar(sf::RenderWindow& window){
    window.setActive();

    sf::Image bgImg;
    bgImg.loadFromFile("../Textures/SpaceWar/space.png");
    sf::Texture bgTexture;
    bgTexture.loadFromImage(bgImg);
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
        window.display();
    }
}