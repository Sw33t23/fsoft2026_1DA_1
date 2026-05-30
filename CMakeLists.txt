cmake_minimum_required(VERSION 3.20) # Version 4.1 is very high; 3.20 is standard
project(fsoft2026_1DA_1)

set(CMAKE_CXX_STANDARD 14)

# Tell CMake where to look for your .h files
include_directories(GamesPlatform/MaiorOuMenor)
include_directories(GamesPlatform/blackjack)

add_executable(fsoft2026_1DA_1
        GamesPlatform/main.cpp
        GamesPlatform/MaiorOuMenor/MaiorOuMenor.cpp
        GamesPlatform/MaiorOuMenor/MaiorOuMenor.h
        GamesPlatform/blackjack/blackjack.cpp
        GamesPlatform/blackjack/blackjack.cpp
        GamesPlatform/Controller/controller.h
        GamesPlatform/Controller/controller.cpp
        GamesPlatform/Jogo do Galo/Galo.cpp
        GamesPlatform/Ranking/Ranking.h
        GamesPlatform/Ranking/Ranking.cpp
)