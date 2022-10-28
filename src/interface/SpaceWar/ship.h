#include "enemys.h"

#include "SFML/Graphics.hpp"
#include "vector"
#include "array"

#pragma once

class Weapon{
private:
    struct Laser{
        Laser() = default;
        Laser(float x, float y):laser(sf::Vector2f(2., 25.)), x(x), y(y){
            laser.setFillColor(sf::Color::Red);
            laser.setPosition(x,y);
        }
        sf::RectangleShape laser;
        uint32_t length = 40;
        float x;
        float y;
    };

public:

    void Shoot(float, float);

    void Move(Enemys&);

    void Draw(sf::RenderWindow&);

    Weapon() = default;

private:
    std::vector<Laser> lasers;
};

class Ship{
public:
    Ship();

    void Move(Enemys&);

    void Draw(sf::RenderWindow&);

    void Shoot();

    float getX();
    float getY();

    uint16_t getWidth();
    uint16_t getHeight();

    enum Directs{
        Left = 0,
        Right = 1,
        Forward= 2,
        Down = 3
    };
private:
    Weapon weapon;

    Directs direct = Directs::Forward;
    std::array<sf::Texture, 4> textures;
    sf::Sprite currentSprite;
    float x;
    float y;
    uint16_t width;
    uint16_t height;
    bool isMoving = false;
};