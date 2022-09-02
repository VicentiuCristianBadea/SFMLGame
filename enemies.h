#ifndef ENEMIES_H
#define ENEMIES_H

#include <vector>

#include "enemy.h"


class Enemies
{

public:

    ~Enemies(){};
    Enemies(const Enemies&) = delete;
    void operator=(const Enemies&) = delete;

    static Enemies& Get();

    void addEnemy(sf::Window*);
    void moveEnemies(sf::Window*, int&, unsigned);
    void removeClickedEnemy(int, unsigned&, bool&, sf::Vector2f);
    void spawnEnemy(sf::Window*);

    std::vector<Enemy*> getEnemyVector();


private:
    Enemies(){};

    std::vector<Enemy*> enemyVector;
    Enemy* enemy;
    const float enemySpawnTimerMax{10.f};
    float enemySpawnTimer{enemySpawnTimerMax};
    const int maxEnemies{5};

};

#endif // ENEMIES_H
