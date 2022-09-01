#ifndef ENEMIES_H
#define ENEMIES_H

#include <vector>

#include "enemy.h"


class Enemies
{

private:



    static float enemySpawnTimerMax;
    static float enemySpawnTimer;

public:

    Enemies();
    static void addEnemy(Enemy&, sf::Window*);
    static void removeEnemy(sf::Window*, int&, unsigned);
    static void removeClickedEnemy(int, unsigned&, bool&, sf::Vector2f);
    static void spawnEnemy(Enemy&, sf::Window*);


    static std::vector<Enemy> enemyVector;
};

#endif // ENEMIES_H
