#include "SFML/Graphics.hpp"
#include "object.h"
#include "cstdlib"

#pragma once

class Enemys{
public:
    Enemys() = default;
    ~Enemys() = default;

    void Draw(sf::RenderWindow&);
    void CreateEnemy();

private:
    std::vector<Object> enemys;
};