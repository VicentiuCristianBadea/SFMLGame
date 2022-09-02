#ifndef TRIANGLEENEMY_H
#define TRIANGLEENEMY_H

#include "enemy.h"

class TriangleEnemy : public Enemy
{
public:
    ~TriangleEnemy(){};
    TriangleEnemy();

    void init() override;
    sf::CircleShape* getEnemy() override;

private:
    sf::CircleShape* enemy;
};

#endif // TRIANGLEENEMY_H
