#include "enemys.h"

#include "iostream"

Enemys::Enemys(){
    texture.loadFromFile("../Textures/SpaceWar/Enemy/enemy.png");
    enemy.setTexture(texture);
}

void Enemys::AddEnemy(){
    bool (*review)(float&, float&, std::vector<Parametrs>&);
    // в обычной игре таким способом спавнить энеми просто глупость
    review = [](float& x, float& y, std::vector<Parametrs>& vect){
        for(auto& i: vect){
            if(x >= i.x - 20 && x <= (i.x + i.width + 20) && y >= i.y - 20 && y <= (i.y + i.height + 20))
                return true;
        }
        return false;
    };

    if ( enemysPos.size() <= 8){
        srand(time(0));
        float x = rand() % 1200;
        float y = rand() % 400;
        while (true){
            if( review(x, y, enemysPos) ){
                x = rand() % 1136;
                y = rand() % 500;
            } else {
                break;
            }
        }
        pushEnemy(x, y);
    }

}

void Enemys::pushEnemy(const float& x, const float& y){
    if (enemysPos.size() == 8){
        return;
    }
    enemysPos.push_back(Parametrs(x, y, 64, 64));
}

void Enemys::Draw(sf::RenderWindow& window){
    for(auto& i: enemysPos){
        enemy.setPosition(i.x, i.y);
        window.draw(enemy);
    }
}

uint8_t Enemys::Amount() {
    return enemysPos.size();
}

bool Enemys::CheckEnemy(const float&x, const float&y){
    for(auto i: enemysPos){
        if (x >= i.x && x <= i.x + i.width)
            if (y >= i.y && y <= i.y + i.height)
                return true;
    }
    return false;
}

void Enemys::DeleteEnemy(const float& x, const float& y){
    for(auto i = enemysPos.begin(); i != enemysPos.end(); ++i){
        if (x >= i->x && x <= i->x + i->width)
            if (y >= i->y && y <= i->y + i->height){
                enemysPos.erase(i);
                return;
            }

    }
}