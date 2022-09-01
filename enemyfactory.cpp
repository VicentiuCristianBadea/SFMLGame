#include "circleenemy.h"
#include "enemyfactory.h"
#include "squareenemy.h"
#include "triangleenemy.h"

EnemyFactory::EnemyFactory()
{

}

Enemy EnemyFactory::createEnemy(const int option)
{

    switch(option){
    case 0:
        return CircleEnemy();
        break;
    case 1:
        return TriangleEnemy();
        break;
    case 2:
        return SquareEnemy();
        break;
    default:
        return SquareEnemy();
        break;

    }
}
