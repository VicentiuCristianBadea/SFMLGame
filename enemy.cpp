#ifndef ENEMY_CPP
#define ENEMY_CPP

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "enemy.h"
#include "game.h"


Enemy::~Enemy()
{
    qDebug() << "Destroying enemy\n";
    if(this->touchedEnd)
    {
        Game::removeLife();
    }
    else
    {
        Game::addPoints(this->points);
    }
}

sf::CircleShape* Enemy::getEnemy()
{
    return this->enemy;
}

const sf::Color& Enemy::randomColor()
{
    unsigned num = rand() % 100;

    if(num > 0 && num < 25)
        return sf::Color::Green;
    else if(num > 25 && num < 50)
        return sf::Color::Red;
    else
        return sf::Color::Cyan;
}

void Enemy::initBase(sf::CircleShape& enemy)
{
    enemy.setPosition(10.f, 10.f);
    enemy.setRadius(50.f);
    enemy.setScale(sf::Vector2f(0.5f, 0.5f ));
    enemy.setFillColor(this->randomColor());
}

void Enemy::setPoints(unsigned x)
{
    this->points = x;
}

void Enemy::toggleTouchedEnd()
{
    this->touchedEnd = true;
}




#endif
