#include <iostream>
#include <vector>


class Tile
{
    public:
        // Konstruktor
        Tile(int x, int y): _x(x), _y(y), _revealed(0) {}  

        bool check()
        {
            if(_mine) return 0;
            else 
            {
                _revealed = 1;
                return 1;
            }
        }

        void draw()
        {
            if(_revealed) std::cout << "()";
            if(_flag) std::cout << "&";
            else std::cout << "[]";
        }


    private:
        
        // pozycja pola
        int _x;
        int _y;

        // charaktrystyka pola
        bool _flag;
        bool _mine;

        // czy pole jest odkryte
        bool _revealed;

        // liczba min w okolicy
        int number;
};
