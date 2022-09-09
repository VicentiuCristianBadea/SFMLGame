#ifndef SQUAREENEMY_H
#define SQUAREENEMY_H

#include "enemy.h"


class SquareEnemy : public Enemy
{
public:
    ~SquareEnemy(){};
    SquareEnemy();

    void init() override;
    std::shared_ptr<sf::CircleShape> getEnemy() override;

private:
    std::shared_ptr<sf::CircleShape> enemy;
};

#endif // SQUAREENEMY_H
