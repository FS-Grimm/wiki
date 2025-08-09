cmake_minimum_required(VERSION 3.30)
project(Wiki)

set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
FetchContent_Declare(
        nlohmann_json
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(nlohmann_json)
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
