#include "circleenemy.h"

CircleEnemy::CircleEnemy()
{
    this->enemy = std::make_shared<sf::CircleShape>();
}

std::shared_ptr<sf::CircleShape> CircleEnemy::getEnemy()
{
    return this->enemy;
}

void CircleEnemy::init()
{
    this->initBase(*enemy);
    this->setPoints(2);
}

