include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.14.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../Project/Headers)


set(PROJECT_SOURCES
        ../Project/Source/Model/MaiorOuMenor.cpp
        ../Project/Source/Model/Blackjack.cpp
        ../Project/Source/Model/Galo.cpp
        ../Project/Source/Model/Ranking.cpp
        ../Project/Source/Container/JogadorContainer.cpp
        ../Project/Source/Service/JogadorService.cpp
)


add_executable(ProjectTester
        Tests/MaiorOuMenorTest.cpp
        Tests/BlackjackTest.cpp
        Tests/GaloTest.cpp
        Tests/RankingTest.cpp
        Tests/JogadorContainerTest.cpp
        Tests/JogadorServiceTest.cpp
        ${PROJECT_SOURCES}
)


target_link_libraries(ProjectTester
        gtest_main
        gtest
)


gtest_discover_tests(ProjectTester)
