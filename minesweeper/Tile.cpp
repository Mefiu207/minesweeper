#include "Tile.hpp"

Tile::Tile(int x, int y): _x(x), _y(y), _revealed(0), _mine(0), _flag(0), _number_of_mines(0) {}  

bool Tile::check()
{
    if(_mine) return 0;
    else 
    {
        _revealed = 1;
        return 1;
    }
}

void Tile::draw()
{
    // if(_revealed) std::cout << _number_of_mines;
    // if(_flag) std::cout << " & ";
    // else std::cout << "#";
    if (_mine) std::cout << "*";
    else std::cout << _number_of_mines;
}

void Tile::add_number_of_mines() { if(!_mine) _number_of_mines++; }

void Tile::set_mine() { _mine = 1; }