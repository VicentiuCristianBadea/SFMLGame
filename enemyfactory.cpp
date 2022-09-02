#include "circleenemy.h"
#include "enemyfactory.h"
#include "squareenemy.h"
#include "triangleenemy.h"

#include <qdebug.h>

Enemy* EnemyFactory::createEnemy(const unsigned option)
{

    qDebug() << option << '\n';

    switch(option){
    case 0:
        return new CircleEnemy();
        break;
    case 1:
        return new TriangleEnemy();
        break;
    case 2:
        return new SquareEnemy();
        break;
    default:
        return new SquareEnemy();
        break;

    }
}
