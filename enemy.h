#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy{
protected:
    sf::CircleShape enemy;

public:
    virtual ~Enemy(){};
    virtual void init();

    sf::CircleShape getEnemy();
};

#endif // ENEMY_H
