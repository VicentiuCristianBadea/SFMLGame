#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <memory>

class Enemy
{
public:
    Enemy();
    virtual ~Enemy();
    virtual void init(){};
    virtual std::shared_ptr<sf::CircleShape> getEnemy();

    const sf::Color& randomColor();


    void initBase(sf::CircleShape&);
    void setPoints(unsigned);
    void toggleTouchedEnd();


private:

    std::shared_ptr<sf::CircleShape> enemy;
    unsigned points;
    bool touchedEnd;
};

#endif // ENEMY_H
