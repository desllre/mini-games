#include "SFML/Graphics.hpp"
#include "string"

#pragma once

struct Object{

    Object(const std::string, float, float, uint16_t, uint16_t);

    sf::Texture texture;
    sf::Sprite sprite;
    float x;
    float y;
    uint16_t width;
    uint16_t height;
};