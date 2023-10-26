#include <iostream>
#include <string>
#include "MainGame.h"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        std::cout << "Welcome to" << argv[0] << "\n";
    }
    auto mainGame = MainGame(1024, 768, GameState::PLAY);
    mainGame.run();
    return 0;
}