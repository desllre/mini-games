#include "SFML/Graphics.hpp"
#include "object.h"
#include "array"

class Ship{
public:
    Ship();

    void Move();

    void Draw(sf::RenderWindow&);



    enum Directs{
        Left = 0,
        Right = 1,
        Forward= 2,
        Down = 3
    };
private:
    Directs direct = Directs::Forward;
    std::array<sf::Texture, 4> textures;
    sf::Sprite currentSprite;
    float x;
    float y;
    uint16_t width;
    uint16_t height;
    bool isMoving = false;
};