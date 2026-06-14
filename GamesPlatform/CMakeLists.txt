cmake_minimum_required(VERSION 3.20) # Version 4.1 is very high; 3.20 is standard
project(fsoft2026_1DA_1)

set(CMAKE_CXX_STANDARD 17)

include_directories(Headers)

add_executable(fsoft2026_1DA_1
        main.cpp
        Source/Container/JogadorContainer.cpp
        Source/Controller/BlackjackController.cpp
        Source/Controller/GaloController.cpp
        Source/Controller/JogadorController.cpp
        Source/Controller/MaiorOuMenorController.cpp
        Source/Controller/MenuController.cpp
        Source/Controller/RankingController.cpp
        Source/Model/Blackjack.cpp
        Source/Model/Galo.cpp
        Source/Model/MaiorOuMenor.cpp
        Source/Model/Ranking.cpp
        Source/Service/JogadorService.cpp
        Source/View/BlackjackView.cpp
        Source/View/GaloView.cpp
        Source/View/JogadorView.cpp
        Source/View/MaiorOuMenorView.cpp
        Source/View/RankingView.cpp

)