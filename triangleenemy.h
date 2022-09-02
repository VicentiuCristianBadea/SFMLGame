#ifndef TRIANGLEENEMY_H
#define TRIANGLEENEMY_H

#include "enemy.h"

class TriangleEnemy : public Enemy
{

    sf::CircleShape* enemy;

public:
    ~TriangleEnemy(){};
    TriangleEnemy();

    void init() override;
    sf::CircleShape* getEnemy() override;
};

#endif // TRIANGLEENEMY_H
