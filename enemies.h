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
    void moveEnemies(sf::Window*);
    void removeClickedEnemy(bool&, sf::Vector2f);
    void spawnEnemy(sf::Window*);

    std::vector<std::shared_ptr<Enemy>> getEnemyVector();


private:
    Enemies(){};

    std::vector<std::shared_ptr<Enemy>> enemyVector;
    std::shared_ptr<Enemy> enemy;
    const float enemySpawnTimerMax{10.f};
    float enemySpawnTimer{enemySpawnTimerMax};
    const int maxEnemies{5};

};

#endif // ENEMIES_H
