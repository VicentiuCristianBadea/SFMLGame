#include "game.h"

#include <qdebug.h>
#include <QCoreApplication>
#include <enemies.h>

//  Constructors, Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}


//  Public Functions
void Game::update()
{
    this->pollEvents();

    if(this->endGame == false)
    {
        this->updateMousePositions();
        this->updateEnemies();
        this->updateUI();
    }

    if(this->health <= 0)
        this->endGame = true;

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
    this->renderUI();

    this->window->display();
}

bool Game::running() const
{
    return this->window->isOpen();
}

bool Game::getEndGame() const
{
    return this->endGame;
}

void Game::updateMousePositions()
{
    //  @return void
    //  Updates the mouse positions relative to window

    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
{
    Enemies::Get().addEnemy(this->window);
    Enemies::Get().moveEnemies(this->window, this->health, this->points);
    Enemies::Get().removeClickedEnemy(this->health, this->points, this->mouseHeld, this->mousePosView);
}

void Game::updateUI()
{
    this->healthText.setString("Health: " + std::to_string(this->health));
    this->pointsText.setString("Points: " + std::to_string(this->points));
}

void Game::renderEnemies()
{
    for(auto &e: Enemies::Get().getEnemyVector())
    {
        this->window->draw(*e->getEnemy());
    }
}

void Game::renderUI()
{
    this->window->draw(this->healthText);
    this->window->draw(this->pointsText);
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
    this->mouseHeld = false;
    this->health = 10;
    this->endGame = false;

    this->fontFile = "C:\\Users\\vilyb\\Documents\\QT\\build-FirstProject-Qt_6_2_4_MinGW_7_3_0_64_bit-Debug\\debug\\Kanit-Black.ttf";
    //  Don't forget to add the linux filepath version

    if(!font.loadFromFile(fontFile))
        qDebug() << "ERROR::GAME::CPP: Failed to load the font file." << '\n' << QString::fromStdString(fontFile) << '\n';

    this->healthText.setFont(font);
    this->pointsText.setFont(font);

    this->healthText.setCharacterSize(24);
    this->pointsText.setCharacterSize(24);

    this->healthText.setFillColor(sf::Color::White);
    this->pointsText.setFillColor(sf::Color::White);

    this->healthText.setPosition(10.f, 0.f);
    this->pointsText.setPosition(10.f, 50.f);
}
void Game::initWindow()
{
    this->window = new sf::RenderWindow(this->videoMode, this->title, this->style);
    this->window->setFramerateLimit(60);
}


