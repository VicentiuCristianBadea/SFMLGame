#include "triangleenemy.h"

TriangleEnemy::TriangleEnemy()
{
    this->enemy = new sf::CircleShape();
}

sf::CircleShape* TriangleEnemy::getEnemy()
{
    return this->enemy;
}

void TriangleEnemy::init()
{
    this->initBase(*enemy);
    this->enemy->setPointCount(3);

}
