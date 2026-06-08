cmake_minimum_required(VERSION 3.20)
project(fsoft2026_1DA_1)

set(CMAKE_CXX_STANDARD 14)

# Tell CMake where to look for .h files
include_directories(GamesPlatform/MaiorOuMenor)
include_directories(GamesPlatform/blackjack)
include_directories(GamesPlatform/JogoDoGalo)
include_directories(GamesPlatform/Controller)
include_directories(GamesPlatform/View)
include_directories(GamesPlatform/Ranking)
include_directories(Utils)

add_executable(fsoft2026_1DA_1
        # Main
        GamesPlatform/main.cpp

        # MaiorOuMenor
        GamesPlatform/MaiorOuMenor/MaiorOuMenor.cpp

        # Blackjack
        GamesPlatform/blackjack/blackjack.cpp

        # Controller (todos os jogos)
        GamesPlatform/Controller/MaiorOuMenorController.cpp
        GamesPlatform/Controller/GaloController.cpp

        # View (todos os jogos)
        GamesPlatform/View/GaloView.cpp

        # Ranking
        GamesPlatform/Ranking/Ranking.cpp

        # Jogo do Galo
        GamesPlatform/JogoDoGalo/Galo.cpp

        # Utils partilhado por todos os jogos
        Utils/GaloUtils.cpp
)