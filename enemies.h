#ifndef ENEMIES_H
#define ENEMIES_H

#include <vector>

#include "enemy.h"


class Enemies
{

public:

    ~Enemies(){};
    Enemies(){};


    static void addEnemy(sf::Window*);
    static void moveEnemies(sf::Window*, int&, unsigned);
    static void removeClickedEnemy(int, unsigned&, bool&, sf::Vector2f);
    static void spawnEnemy(sf::Window*);


    static std::vector<Enemy*> enemyVector;
    static Enemy* enemy;

    const static float enemySpawnTimerMax;
    const static int maxEnemies;
    static float enemySpawnTimer;

};

#endif // ENEMIES_H
