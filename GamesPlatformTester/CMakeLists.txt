set(GamesPlatform_SOURCES
        ../GamesPlatform/Source/Model/MaiorOuMenor.cpp
        ../GamesPlatform/Source/Model/Blackjack.cpp
        ../GamesPlatform/Source/Model/Galo.cpp
        ../GamesPlatform/Source/Model/Ranking.cpp
        ../GamesPlatform/Source/Container/JogadorContainer.cpp
        ../GamesPlatform/Source/Service/JogadorService.cpp
)

add_executable(GamesPlatformTester
        MaiorOuMenorTest.cpp
        BlackjackTest.cpp
        GaloTest.cpp
        RankingTest.cpp
        JogadorContainerTest.cpp
        JogadorServiceTest.cpp
        ${GamesPlatform_SOURCES}
)

target_include_directories(GamesPlatformTester PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../GamesPlatform/Headers
        C:/FSOFT_ESTE/GamesPlatform/cmake-build-debug/_deps/googletest-src/googletest/include
)

target_link_libraries(GamesPlatformTester PRIVATE
        gtest_main
        gtest
)

include(GoogleTest)
gtest_discover_tests(GamesPlatformTester)