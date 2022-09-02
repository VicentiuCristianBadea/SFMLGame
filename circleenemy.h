#ifndef CIRCLEENEMY_H
#define CIRCLEENEMY_H

#include <enemy.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class CircleEnemy : public Enemy
{

    sf::CircleShape* enemy;

public:
    ~CircleEnemy(){};
    CircleEnemy();

    void init() override;
    sf::CircleShape* getEnemy() override;
};

#endif // CIRCLEENEMY_H
