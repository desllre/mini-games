#include "enemys.h"

void Enemys::pushEnemy(const std::string& KeyName, const float& x, const float& y){
    if (enemys.size() == 0){
        return;
    }
    enemys.push_back( sf::Sprite(*TextureHolder.getResources(KeyName)) );
}

void Enemys::Draw(sf::RenderWindow& window){
    for(auto& i: enemys){
        window.draw(i);
    }
}

uint8_t Enemys::Amount() {
    return enemys.size();
}