#include "enemies.h"

#include "enemyfactory.h"

#include <QDebug>

Enemies::Enemies()
{

}

void Enemies::addEnemy(Enemy& enemy, sf::Window* window)
{
    if(enemySpawnTimer >= enemySpawnTimerMax)
    {
        spawnEnemy(enemy, window);
        enemySpawnTimer = 0.f;
    }
    else
    {
        enemySpawnTimer += 1.f;
    }
}

void Enemies::removeEnemy(sf::Window* window, int& health, unsigned points)
{
    for(unsigned long long i = 0; i < enemyVector.size(); i++)
    {
        enemyVector[i].getEnemy().move(0.f, 1.f);

        if(enemyVector[i].getEnemy().getPosition().y + (enemyVector[i].getEnemy().getRadius() / 2) > window->getSize().y)
        {
            enemyVector.erase(enemyVector.begin() + i);
            health -= 1;
            qDebug() << "Points: " << points << " | Health: " << health << '\n';
        }
    }

}


void Enemies::removeClickedEnemy(int health, unsigned& points, bool& mouseHeld, sf::Vector2f mousePosView)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(mouseHeld == false)
        {
            mouseHeld = true;
            bool deleted = false;
            for(size_t i = 0; i < enemyVector.size() && deleted == false; i++)
            {
                if(enemyVector[i].getEnemy().getGlobalBounds().contains(mousePosView))
                {
                    deleted = true;
                    enemyVector.erase(enemyVector.begin() + i);
                    //  Gain points
                    points += 1;
                    qDebug() << "Points: " << points << " | Health: " << health << '\n';
                }
            }
        }
    }
    else
    {
        mouseHeld = false;
    }
}

void Enemies::spawnEnemy(Enemy& enemy, sf::Window* window)
{

    enemy = EnemyFactory::createEnemy(rand() % 5);

    enemy.getEnemy().setPosition(
        static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy.getEnemy().getRadius())),
        0.f
    );

    //  Select color
    enemy.init();

    //  Spawn enemy
    enemyVector.push_back(enemy);
}


