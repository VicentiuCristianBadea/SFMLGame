#ifndef CIRCLEENEMY_H
#define CIRCLEENEMY_H

#include <enemy.h>

class CircleEnemy : public Enemy
{
public:
    ~CircleEnemy();
    CircleEnemy();

    virtual void init() override;
};

#endif // CIRCLEENEMY_H
