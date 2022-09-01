#ifndef TRIANGLEENEMY_H
#define TRIANGLEENEMY_H

#include "enemy.h"

class TriangleEnemy : public Enemy
{
public:
    ~TriangleEnemy();
    TriangleEnemy();

    virtual void init() override;
};

#endif // TRIANGLEENEMY_H
