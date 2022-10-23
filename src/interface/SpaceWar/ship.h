#include "SFML/Graphics.hpp"
#include "array"

// на самом деле универсальнее было бы сделать класс, содержащий текстурки координаты и тд любого объекта, но так как это мини игра - мне впадлу

class Ship{
public:
    Ship();

    enum Directs{
        Left = 0,
        Right = 1,
        Forward= 2,
        Back = 3
    };
private:
    Directs direct = Directs::Forward;
    std::array<sf::Sprite, 4> sprites;
    float x;
    float y;
    uint16_t width;
    uint16_t height;
};