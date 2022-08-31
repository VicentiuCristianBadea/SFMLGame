#include "game.h"

//  Constructors, Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();

}

Game::~Game()
{
    delete this->window;
}


//  Public Functions
void Game::update()
{
    this->pollEvents();

//      Update Mouse Position
//    std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " " <<
//                 sf::Mouse::getPosition().y << '\n';

    //  Relative to the window
    qDebug() << "Mouse pos: "
              << sf::Mouse::getPosition(*this->window).x << " "
              << sf::Mouse::getPosition(*this->window).y << '\n';
}

void Game::pollEvents()
{
    while(this->window->pollEvent(this->ev))
    {
        switch(this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        default:
            break;
        }

    }
}

void Game::render()
{

    /*
        @return void

        - clear old frame
        - render objects
        - display frame in window

        Renders the game objects.
    */

    this->window->clear();

    //  Draw Game Objects
    this->window->draw(this->enemy);

    this->window->display();
}

bool Game::running()
{
    return this->window->isOpen();
}

//  Private Functions
void Game::initVariables()
{
    this->window = nullptr;
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->style = sf::Style::Titlebar | sf::Style::Close;
    this->title = "Game 1";
}
void Game::initWindow()
{
    this->window = new sf::RenderWindow(this->videoMode, this->title, this->style);
    this->window->setFramerateLimit(30);
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f ));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}
