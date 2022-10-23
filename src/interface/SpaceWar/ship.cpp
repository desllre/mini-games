#include "ship.h"

Ship::Ship() {
    sf::Texture tmpTexture;
    tmpTexture.loadFromFile("../Textures/SpaceWar/Ship/ShipLeft.png");
    sprites[0] = sf::Sprite(tmpTexture);
    tmpTexture.loadFromFile("../Textures/SpaceWar/Ship/ShipRight.png");
    sprites[1] = sf::Sprite(tmpTexture);
    tmpTexture.loadFromFile("../Textures/SpaceWar/Ship/Ship.png");
    sprites[2] = sprites[3] = sf::Sprite(tmpTexture);
    width = 30;
    height = 42;
    x = 585;
    y = 600;
}

