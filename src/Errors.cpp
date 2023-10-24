#include "Errors.h"

#include <cstdlib>
#include <iostream>
#include <SDL/SDL.h>

void Errors::fatalError(const std::string &errorText)
{
    std::cout << errorText << "\n";
    std::cout << "Enter any key to quit...\n";

    int tmp;
    std::cin >> tmp;

    SDL_Quit();
    exit(1);
}
