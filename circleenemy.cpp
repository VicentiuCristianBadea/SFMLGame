#include "circleenemy.h"

CircleEnemy::CircleEnemy()
{
    enemy = new sf::CircleShape();
}

sf::CircleShape* CircleEnemy::getEnemy()
{
    return this->enemy;
}

void CircleEnemy::init()
{
    this->enemy->setPosition(10.f, 10.f);
    this->enemy->setRadius(50.f);
    this->enemy->setScale(sf::Vector2f(0.5f, 0.5f ));
    this->enemy->setFillColor(sf::Color::Cyan);
}

