#ifndef GAME_H
#define GAME_H

/*

    Class that acts as the game engine.
    Wrapper class.

*/
#include <string>
#include <iostream>
#include <QDebug>

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
    sf::RectangleShape enemy;


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

    //  Accessors
    bool running();

};

#endif // GAME_H
