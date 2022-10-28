#include "SFML/Graphics.hpp"
#include "interface/menu.h"
#include "interface/SpaceWar/ResourceHolder.h"

#pragma once

Menu menu;

void Game(){

    sf::RenderWindow window(sf::VideoMode(1200, 800), "mini-games");
    sf::Color bgColor = menu.GetBgColor();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        menu.setButtonActive(sf::Mouse::getPosition(window));

        window.clear(bgColor);
        menu.Draw(window);
        window.display();
    }

}