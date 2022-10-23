#include "enemy.h"


#include "iostream"

void Enemys::Draw(sf::RenderWindow& window) {
    for (auto& i: enemys ){
        window.draw(i.sprite);
    }
}

void Enemys::CreateEnemy() {
    bool (*review)(float&, float&, std::vector<Object>&);
    // в обычной игре таким способом спавнить энеми просто глупость
    review = [](float& x, float& y, std::vector<Object>& vect){
        for(auto& i: vect){
            if(x >= i.x && x <= (i.x + i.width) && y >= i.y && y <= (i.y + i.height))
                return true;
        }
        return false;
    };
    uint8_t amountEnemys = enemys.size();
    if ( amountEnemys <= 8){
        srand(time(0));
        float x = rand() % 1200;
        float y = rand() % 400;
        while (true){
            if( review(x, y, enemys) ){
                x = rand() % 1200;
                y = rand() % 500;
            } else {
                break;
            }
        }
        enemys.push_back(Object());
        enemys[amountEnemys].init("../Textures/SpaceWar/Enemy/enemy.png", x, y, 64, 64);
        std::cout << x << "  " << y << std::endl;
    }

}