#include "squareenemy.h"

SquareEnemy::SquareEnemy()
{
    enemy = new sf::CircleShape();
}

sf::CircleShape* SquareEnemy::getEnemy()
{
    return this->enemy;
}

void SquareEnemy::init()
{
    this->enemy->setPointCount(4);
    this->enemy->setPosition(10.f, 10.f);
    this->enemy->setRadius(50.f);
    this->enemy->setScale(sf::Vector2f(0.5f, 0.5f ));
    this->enemy->setFillColor(sf::Color::Cyan);
}


