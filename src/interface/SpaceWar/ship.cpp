#include "ship.h"

#include "iostream"

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
        x -= 0.3;
        currentSprite.setTexture(textures[Directs::Left]);
        isMoving = true;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        x += 0.3;
        currentSprite.setTexture(textures[Directs::Right]);
        isMoving = true;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        y -= 0.3;
        currentSprite.setTexture(textures[Directs::Forward]);
        isMoving = true;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        y += 0.3;
        currentSprite.setTexture(textures[Directs::Down]);
        isMoving = true;
    }
}

void Ship::Draw(sf::RenderWindow& window){
    Move();
    if (!isMoving){
        currentSprite.setTexture(textures[Directs::Forward]);
    } else{
        isMoving = false;
    }
    currentSprite.setPosition(x, y);
    window.draw(currentSprite);
}