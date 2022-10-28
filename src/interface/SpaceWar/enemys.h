#include "ResourceHolder.h"

#include "SFML/Graphics.hpp"
#include "vector"
#include "map"
#include "string"

#pragma once

class Enemys{
private:
    struct Parametrs{
        Parametrs();
        Parametrs(uint32_t x, uint32_t y, uint32_t width, uint32_t height):x(x), y(y), width(width), height(height){}
        uint32_t x = 0;
        uint32_t y = 0;
        uint32_t width = 0;
        uint32_t height = 0;
    };
public:
    Enemys();
    ~Enemys() = default;

    void AddEnemy();

    void Draw(sf::RenderWindow&);

    uint8_t Amount();
private:
    void pushEnemy(const float&, const float&);

    std::vector<Parametrs> enemysPos;
    sf::Texture texture;
    sf::Sprite enemy;
    // Криво сделано. Тут должен быть map<vector, string> который будет хранить
    // имена спрайтов и координаты для каждого из них (Для большего кол-ва enemy)
    // Или мб что-то подобное. Суть в том, что различных противников может быть больше
};
