#ifndef CIRCLEENEMY_H
#define CIRCLEENEMY_H

#include <enemy.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class CircleEnemy : public Enemy
{
public:
    ~CircleEnemy(){};
    CircleEnemy();

    void init() override;
    sf::CircleShape* getEnemy() override;

private:
    sf::CircleShape* enemy;
};

#endif // CIRCLEENEMY_H
