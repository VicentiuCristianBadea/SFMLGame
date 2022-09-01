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
//    if(static_cast<int>(this->enemies.size()) < this->maxEnemies)
//    {
//        if(this->enemySpawnTimer >= this->enemySpawnTimerMax)
//        {
//            this->spawnEnemy();
//            this->enemySpawnTimer = 0.f;
//        }
//        else
//        {
//            this->enemySpawnTimer += 1.f;
//        }
//    }

//    for(unsigned long long i = 0; i < this->enemies.size(); i++)
//    {
//        this->enemies[i].move(0.f, 1.f);

//        if(this->enemies[i].getPosition().y + (this->enemies[i].getSize().y / 2) > this->window->getSize().y)
//        {
//            this->enemies.erase(this->enemies.begin() + i);
//            this->health -= 1;
//            qDebug() << "Points: " << this->points << " | Health: " << this->health << '\n';
//        }
//    }

    // Check if clicked

//    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
//    {
//        if(this->mouseHeld == false)
//        {
//            this->mouseHeld = true;
//            bool deleted = false;
//            for(size_t i = 0; i < this->enemies.size() && deleted == false; i++)
//            {
//                if(this->enemies[i].getGlobalBounds().contains(this->mousePosView))
//                {
//                    deleted = true;
//                    this->enemies.erase(this->enemies.begin() + i);
//                    //  Gain points
//                    this->points += 1;
//                    qDebug() << "Points: " << this->points << " | Health: " << this->health << '\n';
//                }
//            }
//        }
//    }
//    else
//    {
//        this->mouseHeld = false;
//    }

    this->enemiesObj.addEnemy(enemyObj, this->window);
    this->enemiesObj.removeEnemy(this->window, this->health, this->points);
    this->enemiesObj.removeClickedEnemy(this->health, this->points, this->mouseHeld, this->mousePosView);
}

void Game::updateUI()
{
    this->healthText.setString("Health: " + std::to_string(this->health));
    this->pointsText.setString("Points: " + std::to_string(this->points));
}

void Game::renderEnemies()
{
//    for(auto &e: this->enemies)
//    {
//        this->window->draw(e);
//    }
    for(auto &e: enemiesObj.enemyVector)
    {
        this->window->draw(e.getEnemy());
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
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;

    this->mouseHeld = false;
    this->health = 10;
    this->endGame = false;

    this->fontFile = "/home/vily/Packages/Fonts/Kanit/Kanit-Black.ttf";

    if(!font.loadFromFile(fontFile))
        qDebug() << "ERROR::GAME::CPP: Failed to load the font file." << '\n';

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

void Game::initEnemies()
{
//    this->enemy.setPosition(10.f, 10.f);
//    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
//    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f ));
//    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemyObj.init();
}
