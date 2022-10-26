#include "ResourceHolder.h"

#include "SFML/Graphics.hpp"
#include "vector"
#include "string"

#pragma once

class Enemys{
public:
    Enemys() = default;
    ~Enemys() = default;

    void pushEnemy(const std::string&, const float&, const float&);

    void Draw(sf::RenderWindow&);

    uint8_t Amount();
private:
    std::vector<sf::Sprite> enemys;
};