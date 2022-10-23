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

Menu::Menu(): OlegGame("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf", "OlegGame",
                         sf::Color(116, 219, 210), 20, 450, 260, 250 , 60, 520, 275),
              MaksGame("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf", "MaksGame",
                       sf::Color(116, 219, 210), 20, 450, 340, 250 , 60, 520, 355),
              VovaGame("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf", "VovaGame",
                       sf::Color(116, 219, 210), 20, 450, 420, 250 , 60, 520, 435),
              end("/usr/share/fonts/truetype/ubuntu/Ubuntu-B.ttf", "Exit",
                  sf::Color(116, 219, 210), 20, 450, 500, 250 , 60, 550, 515){
    bgColor = sf::Color::White;
}

void Menu::Draw(sf::RenderWindow& window) {
    if (OlegGame.isActive) {
        OlegGame.rect.setOutlineColor(sf::Color::Red);
    }
    else{
        OlegGame.rect.setOutlineColor(sf::Color::Black);
    }

    if (MaksGame.isActive) {
        MaksGame.rect.setOutlineColor(sf::Color::Red);
    }
    else{
        MaksGame.rect.setOutlineColor(sf::Color::Black);
    }

    if (VovaGame.isActive) {
        VovaGame.rect.setOutlineColor(sf::Color::Red);
    }
    else{
        VovaGame.rect.setOutlineColor(sf::Color::Black);
    }

    if (end.isActive) {
        end.rect.setOutlineColor(sf::Color::Red);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            window.close();
    }
    else {
        end.rect.setOutlineColor(sf::Color::Black);
    }

    window.draw(OlegGame.rect);
    window.draw(MaksGame.rect);
    window.draw(VovaGame.rect);
    window.draw(end.rect);

    window.draw(OlegGame.text);
    window.draw(MaksGame.text);
    window.draw(VovaGame.text);
    window.draw(end.text);
}

sf::Color& Menu::GetBgColor(){
    return bgColor;
}

void Menu::setButtonActive(const sf::Vector2i vect){//сюда будут передаваться координаты курсора
    OlegGame.setActive(vect.x, vect.y);
    MaksGame.setActive(vect.x, vect.y);
    VovaGame.setActive(vect.x, vect.y);
    end.setActive(vect.x, vect.y);
}