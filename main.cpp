
#include <iostream>

#include "game.h"

int main()
{
    //  Init srand
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
