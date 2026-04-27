cmake_minimum_required(VERSION 4.1)
project(fsoft2026_1DA_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(GamesPlatform/MaiorOuMenor)

add_executable(fsoft2026_1DA_1
        GamesPlatform/.idea/.gitignore
        GamesPlatform/.idea/.name
        GamesPlatform/MaiorOuMenor/MaiorOuMenor.cpp
        GamesPlatform/MaiorOuMenor/MaiorOuMenor.h
        GamesPlatform/main.cpp)
