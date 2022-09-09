#include "circleenemy.h"
#include "enemyfactory.h"
#include "squareenemy.h"
#include "triangleenemy.h"

#include <qdebug.h>

namespace BadGuys{
    EnemyFactory& EnemyFactory::Get()
    {
        static EnemyFactory instance;
        return instance;
    }


    std::shared_ptr<Enemy> EnemyFactory::createEnemy(const unsigned option)
    {

        qDebug() << option << '\n';

        switch(option)
        {
            case BadGuys::CIRCLE:
                return std::make_shared<CircleEnemy>();
                break;
            case BadGuys::TRIANGLE:
                return std::make_shared<TriangleEnemy>();
                break;
            case BadGuys::SQUARE:
                return std::make_shared<SquareEnemy>();
                break;
            default:
                return std::make_shared<SquareEnemy>();
                break;
        }
    }
}
