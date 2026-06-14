include(FetchContent)


FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.14.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


set(GamesPlatform_SOURCES
        ../GamesPlatform/Source/Model/MaiorOuMenor.cpp
        ../GamesPlatform/Source/Model/Blackjack.cpp
        ../GamesPlatform/Source/Model/Galo.cpp
        ../GamesPlatform/Source/Model/Ranking.cpp
        ../GamesPlatform/Source/Container/JogadorContainer.cpp
        ../GamesPlatform/Source/Service/JogadorService.cpp
)


add_executable(GamesPlatformTester
        GamesPlatformTester/MaiorOuMenorTest.cpp
        GamesPlatformTester/BlackjackTest.cpp
        GamesPlatformTester/GaloTest.cpp
        GamesPlatformTester/RankingTest.cpp
        GamesPlatformTester/JogadorContainerTest.cpp
        GamesPlatformTester/JogadorServiceTest.cpp
        ${GamesPlatform_SOURCES}
)


target_include_directories(GamesPlatformTester PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../GamesPlatform/Headers)


target_link_libraries(GamesPlatformTester PRIVATE
        gtest_main
        gtest
)

include(GoogleTest)
gtest_discover_tests(GamesPlatformTester)