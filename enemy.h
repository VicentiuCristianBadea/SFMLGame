#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
public:

    Enemy(){};
    virtual ~Enemy(){};
    virtual void init(){};
    virtual sf::CircleShape* getEnemy();

    const sf::Color& randomColor();

    void initBase(sf::CircleShape&);


private:
    sf::CircleShape* enemy;

};

#endif // ENEMY_H
