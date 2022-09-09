#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "enemy.h"

namespace BadGuys{

    enum factoryOptions{SQUARE, TRIANGLE, CIRCLE};


    class EnemyFactory
    {
    public:
        ~EnemyFactory(){};
        EnemyFactory(const EnemyFactory&) = delete;
        void operator=(const EnemyFactory&) = delete;

        static EnemyFactory& Get();
        std::shared_ptr<Enemy> createEnemy(const unsigned);

    private:
        EnemyFactory(){};
};

}

#endif // ENEMYFACTORY_H
