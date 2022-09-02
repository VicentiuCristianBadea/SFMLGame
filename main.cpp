
#include <iostream>
#include <QCoreApplication>

#include "game.h"

int main(int argc, char *argv[])
{
    //  Init srand
    QCoreApplication a(argc, argv);

    std::srand(static_cast<unsigned>(time(NULL)));

    //  Init Game Engine
    Game game{Game()};

    // Game Loop
    while(game.running() && !game.getEndGame())
    {
        game.update();
        game.render();
    }

    //End of Application

    return 0;
}
