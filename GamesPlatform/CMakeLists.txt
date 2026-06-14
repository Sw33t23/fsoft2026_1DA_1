cmake_minimum_required(VERSION 3.20)
project(fsoft2026_1DA_1)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_subdirectory(../GamesPlatformTester ${CMAKE_BINARY_DIR}/GamesPlatformTester)

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
        ../GamesPlatformTester/BlackjackTest.cpp
        ../GamesPlatformTester/GaloTest.cpp
        ../GamesPlatformTester/JogadorContainerTest.cpp
        ../GamesPlatformTester/JogadorServiceTest.cpp
        ../GamesPlatformTester/MaiorOuMenorTest.cpp
        ../GamesPlatformTester/RankingTest.cpp

)