#include "object.h"

Object::Object(const std::string pathToPng, float x, float y, uint16_t width, uint16_t height):
                                                        x(x), y(y), width(width), height(height){
    texture.loadFromFile(pathToPng);
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}

Object& Object::operator= (Object& other){
    texture = other.texture;
    sprite.setTexture(texture);
    x = other.x;
    y = other.y;
    width = other.width;
    height = other.height;
}

void Object::init(const std::string pathToPng, float x, float y, uint16_t width, uint16_t height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    texture.loadFromFile(pathToPng);
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}
