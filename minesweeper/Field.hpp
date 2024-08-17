    #include <iostream>
    #include <array>
    #include <utility>
    #include <random>

    #include "Tile.hpp"


    template <int N = 20, int mine_number = (N * N) /2 >
    class Field
    {
        public:
            
            // Konstuktor bazowy, inicjalizuje wszystkie miejsca 
            Field()
            {
                // Ustawia 
                for(int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        _field[i][j] = new Tile(i, j);
                    }
                }

                choose_mines_spots();

                set_and_flood();
            }

            // Rysuje plansze
            void paint() const
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

                int count = 0;
                while (count < mine_number) 
                {
                    int x = distrib(gen);
                    int y = distrib(gen);

                    bool is_taken = false;
                    for (const auto& spot : _spots)
                    {
                        if (spot.first == x && spot.second == y) 
                        {
                            is_taken = true;
                            break;
                        }
                    }

                    if (!is_taken) 
                    {
                        _spots[count] = {x, y};
                        count++;
                    }
                }
            }       

            // ustawia miny na miejscach oraz daje inforamcje o minach sasiednim polom
            void set_and_flood()
            {
                for(auto i : _spots) 
                { 
                    _field[i.first()][i.second()].set_mine();
                    
                    if((i.first() - 1) >= 0 && (i.second() - 1) >= 0) _field[i.first() - 1][i.second() - 1].add_number_of_mines();
                    if((i.first() - 1) >= 0 && (i.second() >= 0)) _field[i.first() - 1][i.second()].add_number_of_mines();
                    if((i.first() - 1) >= 0 && ((i.secnod() + 1) >= 0)) -field[i.first() - 1][i.second() + 1].add_number_of_mines();

                    if(i.first() >= 0 && (i.second() - 1) >= 0) _field[i.first()][i.second() - 1].add_number_of_mines();
                    if(i.first() >= 0 && (i.second() + 1) >= 0) _field[i.first()][i.second() + 1].add_number_of_mines();

                    if((i.first() + 1) >= 0 && (i.second() - 1) >= 0) _field[i.first() + 1][i.second() - 1].add_number_of_mines();
                    if((i.first() + 1) >= 0 && (i.second() >= 0)) _field[i.first() + 1][i.second()].add_number_of_mines();
                    if((i.first() + 1) >= 0 && ((i.secnod() + 1) >= 0)) -field[i.first() + 1][i.second() + 1].add_number_of_mines();
                
                }
            }

        private:

            // przetrzymuje pozycje min
            std::array<std::pair<int ,int>, mine_number> _spots;    

            // Pole do gry
            std::array<std::array<Tile, N>, N> _field;
    };