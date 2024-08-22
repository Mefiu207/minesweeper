#include <iostream>

#include "Field.hpp"

// Klasa do gry. Przechowuje plansze i ustawia parametry rozgrywki oraz warunki zwyciestwa i porazki
class Game
{
    public:

        // Konstruktor
        Game();

        // Pokazuje plansze z danymi
        void dispaly();

    private:

        // Przechowuje informacje o ilości flag danych przez gracza
        int _flag_counter;

        // Przechowuje informacje ilosci bomb
        int _number_of_mines;

        // Pole rozgrywki
        Field field;
};