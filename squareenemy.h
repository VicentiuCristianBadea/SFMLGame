#ifndef SQUAREENEMY_H
#define SQUAREENEMY_H

#include "enemy.h"


class SquareEnemy : public Enemy
{
    sf::CircleShape* enemy;

public:
    ~SquareEnemy(){};
    SquareEnemy();

    void init() override;
    sf::CircleShape* getEnemy() override;
};

#endif // SQUAREENEMY_H
