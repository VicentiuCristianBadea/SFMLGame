#include "circleenemy.h"

CircleEnemy::CircleEnemy()
{
    CircleEnemy::init();
}

void CircleEnemy::init()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setRadius(5);
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f ));
    this->enemy.setFillColor(sf::Color::Cyan);
}

