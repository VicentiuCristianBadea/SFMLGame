#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
public:
    virtual ~Enemy(){};
    virtual void init(){};
    virtual sf::CircleShape* getEnemy();

private:
    sf::CircleShape* enemy;
};

#endif // ENEMY_H
