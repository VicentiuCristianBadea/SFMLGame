#include "circleenemy.h"

CircleEnemy::CircleEnemy()
{
    this->enemy = new sf::CircleShape();
}

sf::CircleShape* CircleEnemy::getEnemy()
{
    return this->enemy;
}

void CircleEnemy::init()
{
    this->initBase(*enemy);
    this->setPoints(2);
}

