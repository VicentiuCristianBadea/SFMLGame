#ifndef GAME_H
#define GAME_H

/*

    Class that acts as the game engine.
    Wrapper class.

*/
#include <string>
#include <iostream>
#include <QDebug>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{

private:

    //  Variables
    //  Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    sf::Uint32 style;


    std::string title;

    //  Game Objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    //  Game Logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;

    //  Mouse positions
    sf::Vector2i mousePosWindow;


    void initVariables();
    void initWindow();
    void initEnemies();

public:
    //Constructors, Destructors
    Game();
    virtual ~Game();

    // Functions
    void update();
    void render();
    void pollEvents();
    void updateMousePositions();
    void spawnEnemy();
    void updateEnemies();
    void renderEnemies();

    //  Accessors
    bool running();

};

#endif // GAME_H
