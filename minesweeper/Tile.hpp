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

            // Flaguje pole
            void flag();

        private:
            
            // pozycja pola
            int _x;
            int _y;

           // czy pole jest odkryte
            bool _revealed;

            // charaktrystyka pola
            bool _mine;
            bool _flag;

            // liczba min w okolicy
            int _number_of_mines;
    };