#include "menu.h"

// /usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf

Menu::button::button(const std::string fontPath, const std::string buttonText, const sf::Color bgColor, int textSize, float rectX, float rectY, float width, float height, float textX, float textY){

    this->x = rectX;
    this->y = rectY;
    this->width = width;
    this->height = height;

    rect.setFillColor(bgColor);
    rect.setOutlineThickness(4.);
    rect.setPosition(rectX, rectY);
    rect.setSize(sf::Vector2f(width, height));

    font.loadFromFile(fontPath);
    text = sf::Text(buttonText, font, textSize);
    text.setColor(sf::Color::Black);
    text.setPosition( textX,textY);

};

void Menu::button::setActive(const float cursorX, const float cursorY){
    if( cursorX >= x && cursorX <= (x + width) &&  cursorY >= y && cursorY <= (y + height))
        isActive = true;
    else
        isActive = false;
}

Menu::Menu(): changeGame("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf", "ChangeGame",
                         sf::Color(116, 219, 210), 20, 450, 400, 250 , 60, 510, 415),
              end("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf", "Exit",
                  sf::Color(116, 219, 210), 20, 450, 500, 250 , 60, 550, 515){
    bgColor = sf::Color::White;
}

void Menu::Draw(sf::RenderWindow& window) {
    if (changeGame.isActive) {
        changeGame.rect.setOutlineColor(sf::Color::Red);
    }
    else{
        changeGame.rect.setOutlineColor(sf::Color::Black);
    }

    if (end.isActive) {
        end.rect.setOutlineColor(sf::Color::Red);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            window.close();
    }
    else {
        end.rect.setOutlineColor(sf::Color::Black);
    }

    window.draw(changeGame.rect);
    window.draw(end.rect);

    window.draw(changeGame.text);
    window.draw(end.text);
}

sf::Color& Menu::GetBgColor(){
    return bgColor;
}

void Menu::setButtonActive(const sf::Vector2i vect){//сюда будут передаваться координаты курсора
    changeGame.setActive(vect.x, vect.y);
    end.setActive(vect.x, vect.y);
}