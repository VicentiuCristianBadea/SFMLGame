#include "enemies.h"

#include "enemyfactory.h"
#include "game.h"

#include <QDebug>


std::vector<std::shared_ptr<Enemy>> Enemies::getEnemyVector()
{
    return enemyVector;
}

Enemies& Enemies::Get()
{
    static Enemies instance;
    return instance;
}

//  Define Enemies Functions
void Enemies::addEnemy(sf::Window* window)
{
    if(static_cast<int>(enemyVector.size()) < maxEnemies)
    {
        if(enemySpawnTimer >= enemySpawnTimerMax)
        {
            spawnEnemy(window);
            enemySpawnTimer = 0.f;
        }
        else
        {
            enemySpawnTimer += 1.f;
        }
    }
}

void Enemies::moveEnemies(sf::Window* window)
{
    for(unsigned long long i = 0; i < enemyVector.size(); i++)
    {
        enemyVector[i]->getEnemy()->move(0.f, 1.f);

        if(enemyVector[i]->getEnemy()->getPosition().y + (enemyVector[i]->getEnemy()->getRadius() / 2) > window->getSize().y)
        {
            enemyVector[i]->toggleTouchedEnd();
            enemyVector.erase(enemyVector.begin() + i);
            qDebug() << "Points: " << Game::getPoints() << " | Health: " << Game::getHealth() << '\n';
        }
    }

}


void Enemies::removeClickedEnemy(bool& mouseHeld, sf::Vector2f mousePosView)
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if(mouseHeld == false)
        {
            mouseHeld = true;
            bool deleted = false;
            for(size_t i = 0; i < enemyVector.size() && deleted == false; i++)
            {
                if(enemyVector[i]->getEnemy()->getGlobalBounds().contains(mousePosView))
                {
                    deleted = true;
                    enemyVector.erase(enemyVector.begin() + i);
                    qDebug() << "Points: " << Game::getPoints() << " | Health: " << Game::getHealth() << '\n';
                }
            }
        }
    }
    else
    {
        mouseHeld = false;
    }
}

void Enemies::spawnEnemy(sf::Window* window)
{

    enemy = BadGuys::EnemyFactory::Get().createEnemy(rand() % 5);
    enemy->init();
    enemy->getEnemy()->setPosition(
        static_cast<float>(rand() % static_cast<int>(window->getSize().x - enemy->getEnemy()->getRadius())),
        0.f
    );

    //  Spawn enemy
    enemyVector.push_back(enemy);
}


