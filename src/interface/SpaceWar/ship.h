#include "SFML/Graphics.hpp"
#include "vector"
#include "array"

class Weapon{
private:
    struct Laser{
        sf::RectangleShape laser;
        uint32_t length = 40;
        uint32_t x;
        uint32_t y;
    };
public:

    void Move(){}

    Weapon();

private:
    std::vector<Laser> lasers;
};

class Ship: public Weapon{
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