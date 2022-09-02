#include "enemies.h"

#include "enemyfactory.h"

#include <QDebug>

//  Initialize static variables
std::vector<Enemy*> Enemies::enemyVector;

const float Enemies::enemySpawnTimerMax = 10.f;
const int Enemies::maxEnemies = 5;
float Enemies::enemySpawnTimer = Enemies::enemySpawnTimerMax;
Enemy* Enemies::enemy;


//  Define Enemies Functions
void Enemies::addEnemy(sf::Window* window)
{
    if(Enemies::enemyVector.size() < Enemies::maxEnemies)
    {
        if(Enemies::enemySpawnTimer >= Enemies::enemySpawnTimerMax)
        {
            spawnEnemy(window);
            Enemies::enemySpawnTimer = 0.f;
        }
        else
        {
            Enemies::enemySpawnTimer += 1.f;
        }
    }
}

void Enemies::moveEnemies(sf::Window* window, int& health, unsigned points)
{
    for(unsigned long long i = 0; i < enemyVector.size(); i++)
    {
        Enemies::enemyVector[i]->getEnemy()->move(0.f, 1.f);

        if(Enemies::enemyVector[i]->getEnemy()->getPosition().y + (Enemies::enemyVector[i]->getEnemy()->getRadius() / 2) > window->getSize().y)
        {
            Enemies::enemyVector.erase(Enemies::enemyVector.begin() + i);
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
            for(size_t i = 0; i < Enemies::enemyVector.size() && deleted == false; i++)
            {
                if(Enemies::enemyVector[i]->getEnemy()->getGlobalBounds().contains(mousePosView))
                {
                    deleted = true;
                    Enemies::enemyVector.erase(Enemies::enemyVector.begin() + i);
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

void Enemies::spawnEnemy(sf::Window* window)
{

    Enemies::enemy = EnemyFactory::createEnemy(rand() % 5);

    //  Select color
    Enemies::enemy->init();

    Enemies::enemy->getEnemy()->setPosition(
        static_cast<float>(rand() % static_cast<int>(window->getSize().x - Enemies::enemy->getEnemy()->getRadius())),
        0.f
    );



    //  Spawn enemy
    Enemies::enemyVector.push_back(Enemies::enemy);
}


