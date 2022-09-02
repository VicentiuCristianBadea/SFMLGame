#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "enemy.h"

class EnemyFactory
{
private:

    EnemyFactory(){};

public:

    ~EnemyFactory(){};
    EnemyFactory(const EnemyFactory&) = delete;
    void operator=(const EnemyFactory&) = delete;

    static EnemyFactory& Get();

    Enemy* createEnemy(const unsigned);
};

#endif // ENEMYFACTORY_H
