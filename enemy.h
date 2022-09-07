#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
public:
    Enemy(){this->touchedEnd = false;};
    ~Enemy();
    virtual void init(){};
    virtual sf::CircleShape* getEnemy();

    const sf::Color& randomColor();


    void initBase(sf::CircleShape&);
    void setPoints(unsigned);
    void toggleTouchedEnd();


private:

    sf::CircleShape* enemy;
    unsigned points;
    bool touchedEnd;
};

#endif // ENEMY_H
