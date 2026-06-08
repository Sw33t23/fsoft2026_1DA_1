cmake_minimum_required(VERSION 3.20)
project(fsoft2026_1DA_1)

set(CMAKE_CXX_STANDARD 14)

# Caminhos para os cabeçalhos (.h) de todos os módulos
include_directories(GamesPlatform)
include_directories(GamesPlatform/MaiorOuMenor)
include_directories(GamesPlatform/blackjack)
include_directories(GamesPlatform/JogoDoGalo)
include_directories(GamesPlatform/Controller)
include_directories(GamesPlatform/View)
include_directories(GamesPlatform/Model)
include_directories(GamesPlatform/Ranking)
include_directories(Utils)

# Executável com TODOS os ficheiros do projeto reunidos
add_executable(fsoft2026_1DA_1
        # Main
        GamesPlatform/main.cpp

        # Modelos / Lógica dos Jogos
        GamesPlatform/MaiorOuMenor/MaiorOuMenor.cpp
        GamesPlatform/Model/MaiorOuMenor.cpp
        GamesPlatform/blackjack/blackjack.cpp
        GamesPlatform/Model/blackjack.cpp
        GamesPlatform/Model/RankingModel.cpp

        # Controllers
        GamesPlatform/Controller/controller.cpp
        GamesPlatform/Controller/MaiorOuMenorController.cpp
        GamesPlatform/Controller/GaloController.cpp
        GamesPlatform/Controller/BlackjackController.cpp

        # Views
        GamesPlatform/View/GaloView.cpp
        GamesPlatform/View/BlackjackView.cpp

        # Ranking e Jogo do Galo principal
        GamesPlatform/Ranking/Ranking.cpp
        GamesPlatform/JogoDoGalo/Galo.cpp

        # Utils partilhado
        Utils/GaloUtils.cpp
)