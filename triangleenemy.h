#ifndef TRIANGLEENEMY_H
#define TRIANGLEENEMY_H

#include "enemy.h"

class TriangleEnemy : public Enemy
{
public:
    ~TriangleEnemy(){};
    TriangleEnemy();

    void init() override;
    std::shared_ptr<sf::CircleShape> getEnemy() override;

private:
    std::shared_ptr<sf::CircleShape> enemy;
};

#endif // TRIANGLEENEMY_H
