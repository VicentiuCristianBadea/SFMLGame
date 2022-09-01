#ifndef ENEMY_CPP
#define ENEMY_CPP

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Enemy
{

protected:
    sf::CircleShape enemy;

public:
    virtual ~Enemy(){};
    virtual void init();

    sf::CircleShape getEnemy(){
        return enemy;
    }
};


class SquareEnemy : public Enemy
{
public:

    ~SquareEnemy(){};

    SquareEnemy()
    {
        this->init();
    }

    void init() override
    {
        this->enemy.setPointCount(4);
        this->enemy.setPosition(10.f, 10.f);
        this->enemy.setRadius(5);
        this->enemy.setScale(sf::Vector2f(0.5f, 0.5f ));
        this->enemy.setFillColor(sf::Color::Cyan);
    }
};


class CircleEnemy : public Enemy
{
public:

    ~CircleEnemy(){};

    CircleEnemy()
    {
        this->init();
    }

    void init() override
    {
        this->enemy.setPosition(10.f, 10.f);
        this->enemy.setRadius(5.f);
        this->enemy.setScale(sf::Vector2f(0.5f, 0.5f ));
        this->enemy.setFillColor(sf::Color::Cyan);
    }
};


class TriangleEnemy : public Enemy
{
public:

    ~TriangleEnemy(){};

    TriangleEnemy()
    {
        this->init();
    }

    void init() override
    {
        this->enemy.setPointCount(3);
        this->enemy.setPosition(10.f, 10.f);
        this->enemy.setRadius(5.f);
        this->enemy.setScale(sf::Vector2f(0.5f, 0.5f ));
        this->enemy.setFillColor(sf::Color::Cyan);
    }
};



class EnemyFactory
{
public:
    ~EnemyFactory(){};

    static Enemy createEnemy(int& option)
    {
        switch(option){
        case 0:
            return CircleEnemy();
            break;
        case 1:
            return TriangleEnemy();
            break;
        case 2:
            return SquareEnemy();
            break;
        default:
            return SquareEnemy();
            break;
        }
    }
};


#endif
