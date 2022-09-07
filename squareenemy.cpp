#include "squareenemy.h"

SquareEnemy::SquareEnemy()
{
    this->enemy = new sf::CircleShape();
}

sf::CircleShape* SquareEnemy::getEnemy()
{
    return this->enemy;
}

void SquareEnemy::init()
{
    this->initBase(*enemy);
    this->enemy->setPointCount(4);
    this->setPoints(5);
}


