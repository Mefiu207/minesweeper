#include <iostream>

// #include "Tile.hpp"
// #include "Field.hpp" 
#include "Game.hpp"

int print_menu()
{
    std::cout << "Choose Your option\n";
    std::cout << "1. Classic game" << std::endl;
    std::cout << "2. Custom Game" << std::endl;
    std::cout << "3. Quit" << std::endl;
    int option;
    std::cin >> option;
    return option;
}

void play_game()
{
    Game Game;
    Game.dispaly();
}

int main()
{
    std::cout << "Hello. Welcome to minesweeper.\n";
    int option = print_menu();

    switch (option)
    {
    case 1:
        play_game();
        break;
    
    default:
        break;
    }

  
}