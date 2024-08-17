    #pragma once
    
    #include <iostream>

    class Tile
    {
        public:

            // Konstruktor
            Tile(int x, int y);

            // Sprawdzenie pola 
            bool check();

            // Rysowanie pola
            void draw();

            // Zwieksza licze min w okolicy
            void add_number_of_mines();

            // Ustawia mine
            void set_mine();

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
            int _number_of_mines;
    };