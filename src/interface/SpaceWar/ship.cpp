#include "ship.h"

Ship::Ship() {
    sf::Texture tmpTexture;
    tmpTexture.loadFromFile("../Textures/SpaceWar/Ship/ShipLeft.png");
    textures[0] = tmpTexture;
    tmpTexture.loadFromFile("../Textures/SpaceWar/Ship/ShipRight.png");
    textures[1] = tmpTexture;
    tmpTexture.loadFromFile("../Textures/SpaceWar/Ship/Ship.png");
    textures[2] = textures[3] = tmpTexture;
    width = 30;
    height = 42;
    x = 585;
    y = 600;
    currentSprite = sf::Sprite(textures[Directs::Forward]);
    currentSprite.setPosition(x,y);
}

void Ship::Move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        x -= 0.5;
        currentSprite.setTexture(textures[Directs::Left]);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        x += 0.5;
        currentSprite.setTexture(textures[Directs::Right]);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        y -= 0.5;
        currentSprite.setTexture(textures[Directs::Forward]);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        y += 0.5;
        currentSprite.setTexture(textures[Directs::Down]);
    }
}

void Ship::Draw(sf::RenderWindow& window){
    Move();
    currentSprite.setPosition(x, y);
    window.draw(currentSprite);
}