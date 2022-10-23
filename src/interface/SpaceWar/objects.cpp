#include "object.h"

Object::Object(const std::string pathToPng, float x, float y, uint16_t width, uint16_t height):
                                                        x(x), y(y), width(width), height(height){
    texture.loadFromFile(pathToPng);
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
}
