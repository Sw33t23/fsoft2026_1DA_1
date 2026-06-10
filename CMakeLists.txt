cmake_minimum_required(VERSION 3.20) # Version 4.1 is very high; 3.20 is standard
project(fsoft2026_1DA_1)

set(CMAKE_CXX_STANDARD 17)

include_directories(GamesPlatform/Headers)

add_executable(fsoft2026_1DA_1
        GamesPlatform/main.cpp
        GamesPlatform/Source/Container/JogadorContainer.cpp
        GamesPlatform/Source/Controller/BlackjackController.cpp
        GamesPlatform/Source/Controller/GaloController.cpp
        GamesPlatform/Source/Controller/JogadorController.cpp
        GamesPlatform/Source/Controller/MaiorOuMenorController.cpp
        GamesPlatform/Source/Controller/MenuController.cpp
        GamesPlatform/Source/Controller/RankingController.cpp
        GamesPlatform/Source/Model/Blackjack.cpp
        GamesPlatform/Source/Model/Galo.cpp
        GamesPlatform/Source/Model/MaiorOuMenor.cpp
        GamesPlatform/Source/Model/Ranking.cpp
        GamesPlatform/Source/Service/JogadorService.cpp
        GamesPlatform/Source/View/BlackjackView.cpp
        GamesPlatform/Source/View/GaloView.cpp
        GamesPlatform/Source/View/JogadorView.cpp
        GamesPlatform/Source/View/MaiorOuMenorView.cpp
        GamesPlatform/Source/View/RankingView.cpp

)