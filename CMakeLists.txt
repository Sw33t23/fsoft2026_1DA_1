cmake_minimum_required(VERSION 3.20)
project(fsoft2026_1DA_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(GamesPlatform)
include_directories(GamesPlatform/JogoDoGalo)
include_directories(GamesPlatform/MaiorOuMenor)
include_directories(GamesPlatform/blackjack)
include_directories(GamesPlatform/Controller)
include_directories(GamesPlatform/View)

add_executable(fsoft2026_1DA_1
        GamesPlatform/main.cpp
        GamesPlatform/Model/blackjack.cpp
        GamesPlatform/View/BlackjackView.cpp
        GamesPlatform/Controller/BlackjackController.cpp
        GamesPlatform/Model/MaiorOuMenor.cpp
        GamesPlatform/JogoDoGalo/Galo.cpp
        GamesPlatform/Ranking/Ranking.cpp
)