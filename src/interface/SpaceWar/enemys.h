#include "ResourceHolder.h"

#include "SFML/Graphics.hpp"
#include "vector"
#include "string"

#pragma once

class Enemys{
public:
    Enemys() = default;
    ~Enemys() = default;


    void AddEnemy(const std::string&);

    void Draw(sf::RenderWindow&);

    uint8_t Amount();
private:
    void pushEnemy(const std::string&, const float&, const float&);

    std::vector<sf::Sprite> enemys;
};