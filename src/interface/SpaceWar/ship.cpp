#include "ship.h"

#include "iostream"

void Weapon::Shoot(float x, float y){
    if (lasers.size() <= 10){
        lasers.push_back(Laser( x + 15, y - 40));
    }
}

void Weapon::Move(Enemys& enemys){

    for(auto i = lasers.begin(); i < lasers.end(); ++i){

        if (i->y <= -25){
            lasers.erase(i);
        }

        if (enemys.CheckEnemy(i->x, i->y)){
            enemys.DeleteEnemy(i->x, i->y);
            lasers.erase(i);
            return;
        }
        i->y -= 0.3;
        i->laser.move(0, -0.4);
    }
}

void Weapon::Draw(sf::RenderWindow& window){
    for( auto i: lasers){
        window.draw(i.laser);
    }
}


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

void Ship::Move(Enemys& enemys) {
    weapon.Move(enemys);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        x -= 0.6;
        currentSprite.setTexture(textures[Directs::Left]);
        isMoving = true;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        x += 0.6;
        currentSprite.setTexture(textures[Directs::Right]);
        isMoving = true;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        y -= 0.6;
        currentSprite.setTexture(textures[Directs::Forward]);
        isMoving = true;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        y += 0.6;
        currentSprite.setTexture(textures[Directs::Down]);
        isMoving = true;
    }
}

void Ship::Draw(sf::RenderWindow& window){
    weapon.Draw(window);
    if (!isMoving){
        currentSprite.setTexture(textures[Directs::Forward]);
    } else{
        isMoving = false;
    }
    currentSprite.setPosition(x, y);
    window.draw(currentSprite);
}

void Ship::Shoot() {
    weapon.Shoot(x, y);
}

float Ship::getX(){
    return x;
}
float Ship::getY(){
    return y;
}

uint16_t Ship::getWidth() { return width; }
uint16_t Ship::getHeight() { return height; }