#ifndef SQUAREENEMY_H
#define SQUAREENEMY_H

#include "enemy.h"


class SquareEnemy : public Enemy
{
public:
    ~SquareEnemy(){};
    SquareEnemy();

    void init() override;
    sf::CircleShape* getEnemy() override;

private:
    sf::CircleShape* enemy;
};

#endif // SQUAREENEMY_H
