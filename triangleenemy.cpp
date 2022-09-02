#include "triangleenemy.h"

TriangleEnemy::TriangleEnemy()
{
    enemy = new sf::CircleShape();
}

sf::CircleShape* TriangleEnemy::getEnemy()
{
    return this->enemy;
}

void TriangleEnemy::init()
{
    this->enemy->setPointCount(3);
    this->enemy->setPosition(10.f, 10.f);
    this->enemy->setRadius(50.f);
    this->enemy->setScale(sf::Vector2f(0.5f, 0.5f ));
    this->enemy->setFillColor(sf::Color::Cyan);
}
