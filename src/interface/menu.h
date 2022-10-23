#include "SFML/Graphics.hpp"
#include "thread"
#include "interface.h"
#include "string"
#include "iostream"

#include "SpaceWar/spaceWar.h"

#pragma once

class Menu: public Interface{
public:
    Menu();
    void Draw(sf::RenderWindow&);

    sf::Color& GetBgColor();

    void setButtonActive(const sf::Vector2i);

private:
    struct button{
        button(const std::string, const std::string,const sf::Color,
               int, float, float, float, float, float, float);

        void setActive(const float, const float);

        sf::Font font;
        sf::Text text;
        sf::RectangleShape rect;
        bool isActive=false;
        float x;
        float y;
        float width;
        float height;
    };
    button OlegGame;
    button MaksGame;
    button VovaGame;
    button end;
    sf::Color bgColor;
};

