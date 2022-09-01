#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "enemy.h"

class EnemyFactory
{
private:


public:

    ~EnemyFactory();
    EnemyFactory();

    static Enemy createEnemy(const int);

};

#endif // ENEMYFACTORY_H
