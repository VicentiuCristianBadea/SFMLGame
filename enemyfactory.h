#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "enemy.h"

class EnemyFactory
{
public:
    ~EnemyFactory(){};
    EnemyFactory(const EnemyFactory&) = delete;
    void operator=(const EnemyFactory&) = delete;

    static EnemyFactory& Get();
    Enemy* createEnemy(const unsigned);

private:
    EnemyFactory(){};
};

#endif // ENEMYFACTORY_H
