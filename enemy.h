#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy{

    sf::CircleShape* enemy;

public:
    virtual ~Enemy(){};
    virtual void init(){};
    virtual sf::CircleShape* getEnemy();


};

#endif // ENEMY_H
