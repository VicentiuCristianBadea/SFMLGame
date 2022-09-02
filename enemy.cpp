#ifndef ENEMY_CPP
#define ENEMY_CPP

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "enemy.h"


sf::CircleShape* Enemy::getEnemy()
{
    return this->enemy;
}

#endif
