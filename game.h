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

    static void addPoints(unsigned);
    static void removeLife();
    static unsigned getPoints();
    static int getHealth();

    //  Accessors
    bool running() const;
    bool getEndGame() const;

    inline static unsigned points = 0;
    inline static int health = 10;

private:
    //  Variables
    //  Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    sf::Uint32 style;


    std::string title;

    //  Game Objects
    sf::Font font;
    std::string fontFile;


    //  Game Logic

    bool mouseHeld;

    bool endGame;
    sf::Text pointsText;
    sf::Text healthText;

    //  Mouse positions
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;


    void initVariables();
    void initWindow();
};

#endif // GAME_H
