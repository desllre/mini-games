#include "SFML/Graphics.hpp"

#pragma once

class Interface{
public:
    Interface() = default;
    ~Interface() = default;

    virtual void Draw(sf::RenderWindow&) = 0;
private:
};

