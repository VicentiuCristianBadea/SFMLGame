#include "triangleenemy.h"

TriangleEnemy::TriangleEnemy()
{
    this->enemy = std::make_shared<sf::CircleShape>();
}

std::shared_ptr<sf::CircleShape> TriangleEnemy::getEnemy()
{
    return this->enemy;
}

void TriangleEnemy::init()
{
    this->initBase(*enemy);
    this->enemy->setPointCount(3);
    this->setPoints(7);
}
