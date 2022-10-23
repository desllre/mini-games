#include "SFML/Graphics.hpp"

#pragma once

class Interface{
public:
    Interface();
    virtual void Draw(sf::RenderWindow&) = 0;
    ~Interface();
private:

};

