#include "enemys.h"

#include "iostream"

void Enemys::AddEnemy(const std::string& KeyName){
    bool (*review)(float&, float&, std::vector<sf::Sprite>&);
    // в обычной игре таким способом спавнить энеми просто глупость
    review = [](float& x, float& y, std::vector<sf::Sprite>& vect){
        for(auto& i: vect){
            sf::IntRect buffRect = i.getTextureRect();
            if(x >= buffRect.left && x <= (buffRect.left + buffRect.width) && y >= buffRect.top && y <= (buffRect.top + buffRect.height))
                return true;
        }
        return false;
    };

    if ( enemys.size() <= 8){
        srand(time(0));
        float x = rand() % 1200;
        float y = rand() % 400;
        while (true){
            if( review(x, y, enemys) ){
                x = rand() % 1136;
                y = rand() % 500;
            } else {
                break;
            }
        }
        pushEnemy(KeyName, x, y);
        std::cout << x << "  " << y << std::endl;
    }

}

void Enemys::pushEnemy(const std::string& KeyName, const float& x, const float& y){
    if (enemys.size() == 8){
        return;
    }
    enemys.emplace_back( sf::Sprite(*TextureHolder.getResources(KeyName)) );
    enemys[enemys.size() - 1].setPosition(x, y);
}

void Enemys::Draw(sf::RenderWindow& window){
    for(auto& i: enemys){
        window.draw(i);
    }
}

uint8_t Enemys::Amount() {
    return enemys.size();
}

/*
void CreateEnemy(std::vector<Object> vect) {
    bool (*review)(float&, float&, std::vector<Object>&);
    // в обычной игре таким способом спавнить энеми просто глупость
    review = [](float& x, float& y, std::vector<Object>& vect){
        for(auto& i: vect){
            if(x >= i.x && x <= (i.x + i.width) && y >= i.y && y <= (i.y + i.height))
                return true;
        }
        return false;
    };
    uint8_t amountEnemys = vect.size();
    if ( amountEnemys <= 8){
        srand(time(0));
        float x = rand() % 1200;
        float y = rand() % 400;
        while (true){
            if( review(x, y, vect) ){
                x = rand() % 1200;
                y = rand() % 500;
            } else {
                break;
            }
        }
        vect.push_back(Object());
        vect[amountEnemys].init(x, y, 64, 64);
    }

}
 */