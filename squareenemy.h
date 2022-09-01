#ifndef SQUAREENEMY_H
#define SQUAREENEMY_H

#include "enemy.h"


class SquareEnemy : public Enemy
{
public:
    ~SquareEnemy();
    SquareEnemy();

    virtual void init() override;
};

#endif // SQUAREENEMY_H
