#ifndef GAME_H
#define GAME_H

/*

    Class that acts as the game engine.
    Wrapper class.

*/
#include "enemies.h"
#include "enemyfactory.h"

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
    sf::Font font;
    std::string fontFile;


    //  Game Logic
    unsigned points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    bool mouseHeld;
    int health;
    bool endGame;
    sf::Text pointsText;
    sf::Text healthText;

    //  Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;


    void initVariables();
    void initWindow();
    void initEnemies();



    Enemies enemiesObj;
    Enemy enemyObj;
    EnemyFactory enemyFactory;


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
    void updateUI();
    void renderUI();

    //  Accessors
    bool running() const;
    bool getEndGame() const;

};

#endif // GAME_H
