cmake_minimum_required(VERSION 3.28.0)

project(Minesweeper)

include_directories(Field.hpp Tile.hpp Game.hpp)

add_executable(${PROJECT_NAME} main.cpp Tile.cpp Game.cpp)