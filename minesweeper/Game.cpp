#include "Game.hpp"

Game::Game() : _flag_counter(0)
{
    Field dude;
    field = dude;

    _number_of_mines = field.get_mine_number();

}

void Game::dispaly() { field.paint(); }