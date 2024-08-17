    #include <iostream>
    #include <vector>
    #include <utility>
    #include <random>
    #include <array>
    #include <set>

    #include "Tile.hpp"
    #define N 20
    #define mine_number 50

    // template <int N = 20, int mine_number = (N * N) /4 >
    class Field
    {
        public:
            
            void dupa(std::string cus = "dupa") { std::cout << cus << std::endl;}

            // Konstuktor bazowy, inicjalizuje wszystkie miejsca 
            Field()
            {
                for(int i = 0; i < N; i++)
                {
                    std::vector<Tile> vec;
                    vec.clear();
                    for (int j = 0; j < N; j++)
                    {
                        // std::cout << j << std::endl;
                        vec.push_back(Tile(i, j));
                        // std::cout << "dupa" << std::endl;
                    }
                    _field.push_back(vec);
                    std::cout << i << std::endl;
                }


                choose_mines_spots();

                dupa();

                set_and_flood();
            }

            // Rysuje plansze
            void paint()
            {
                for(int i = 0; i < N; i++)
                {
                    for(int j = 0; j < N; j++)
                    {
                        _field[i][j].draw();
                    }
                    std::cout << "\n";
                }
            }

            // Wybiera miejsca na miny
            void choose_mines_spots()
            {
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> distrib(0, N - 1);

                std::set<std::pair<int, int>> spots_set; // Używamy zbioru do przechowywania unikalnych pozycji min

                while (spots_set.size() < mine_number) 
                {
                    int x = distrib(gen);
                    int y = distrib(gen);

                    // Dodajemy parę do zbioru (jeśli już istnieje, nie zostanie dodana ponownie)
                    spots_set.insert({x, y});
                }

                // Konwertujemy set na vector
                _spots.assign(spots_set.begin(), spots_set.end());
            }


            // ustawia miny na miejscach oraz daje inforamcje o minach sasiednim polom
            void set_and_flood()
            {
                for(auto i : _spots) 
                { 
                    dupa("once");
                    _field[i.first][i.second].set_mine();
                    
                    if((i.first - 1) >= 0 && (i.second - 1) >= 0) _field[i.first - 1][i.second - 1].add_number_of_mines();
                    if((i.first - 1) >= 0 && (i.second >= 0)) _field[i.first - 1][i.second].add_number_of_mines();
                    if((i.first - 1) >= 0 && ((i.second + 1) >= 0)) _field[i.first - 1][i.second + 1].add_number_of_mines();

                    if(i.first >= 0 && (i.second - 1) >= 0) _field[i.first][i.second - 1].add_number_of_mines();
                    if(i.first >= 0 && (i.second + 1) >= 0) _field[i.first][i.second + 1].add_number_of_mines();
                    dupa("srodek");
                    
                    if((i.first + 1) >= 0 && (i.second - 1) >= 0) _field[i.first + 1][i.second - 1].add_number_of_mines();
                    dupa("1");
                    if((i.first + 1) >= 0 && (i.second >= 0)) _field[i.first + 1][i.second].add_number_of_mines();
                    dupa("2");
                    if((i.first + 1) >= 0 && ((i.second + 1) >= 0)) _field[i.first + 1][i.second + 1].add_number_of_mines();
                    dupa("koniec?");

                }
                dupa("koniec?");
            }

        private:

            // przetrzymuje pozycje min
            std::vector<std::pair<int ,int>> _spots;    

            // Pole do gry
            std::vector<std::vector<Tile>> _field;
    };