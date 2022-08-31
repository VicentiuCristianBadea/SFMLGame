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
    this->updateMousePositions();
    this->updateEnemies();
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
    this->renderEnemies();

    this->window->display();
}

bool Game::running()
{
    return this->window->isOpen();
}

void Game::updateMousePositions()
{
    //  @return void
    //  Updates the mouse positions relative to window

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::spawnEnemy()
{
    //  sets random color, position, add to vector
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
    );

    //  Select color
    this->enemy.setFillColor(sf::Color::Green);

    //  Spawn enemy
    this->enemies.push_back(this->enemy);
}

void Game::updateEnemies()
{
    if(static_cast<int>(this->enemies.size()) < this->maxEnemies)
    {
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else
        {
            this->enemySpawnTimer += 1.f;
        }
    }

    for(auto &e: this->enemies)
    {
        e.move(0.f, 1.f);
    }

}

void Game::renderEnemies()
{
    for(auto &e: this->enemies)
    {
        this->window->draw(e);
    }
}



//  Private Functions
void Game::initVariables()
{
    this->window = nullptr;
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->style = sf::Style::Titlebar | sf::Style::Close;
    this->title = "Game 1";

    this->points = 0;
    this->enemySpawnTimerMax = 1000.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;

}
void Game::initWindow()
{
    this->window = new sf::RenderWindow(this->videoMode, this->title, this->style);
    this->window->setFramerateLimit(60);
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
