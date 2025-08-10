cmake_minimum_required(VERSION 3.30)
project(Wiki)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        nlohmann_json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.7.1
)
FetchContent_MakeAvailable(catch2)

add_executable(Wiki
        main.cpp
        TManagers/TopTableManager.cpp
        Card/Card.cpp
        TManagers/BottomTableManager.cpp
        Deck/Deck.cpp
        Deck/TopDeck.cpp
        Deck/BottomDeck.cpp
        Parser/jsonParser.cpp
)
target_link_libraries(Wiki PRIVATE nlohmann_json::nlohmann_json)

add_executable(WikiTests
        Tests/ParserTest.cpp
        Parser/jsonParser.cpp
        Card/Card.cpp
        Deck/Deck.cpp
        Deck/TopDeck.cpp
        Deck/BottomDeck.cpp
        TManagers/TopTableManager.cpp
        TManagers/BottomTableManager.cpp
)
target_link_libraries(WikiTests
        PRIVATE
        nlohmann_json::nlohmann_json
        Catch2::Catch2WithMain
)

include(CTest)
include(Catch)
catch_discover_tests(WikiTests)
