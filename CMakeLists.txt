cmake_minimum_required(VERSION 3.28)
project(Wiki)

set(CMAKE_CXX_STANDARD 20)



add_executable(Wiki
        main.cpp
        TManagers/TopTableManager.cpp
        Card/Card.cpp
        TManagers/BottomTableManager.cpp
        Deck/Deck.cpp
        Deck/TopDeck.cpp
        Deck/BottomDeck.cpp
        Parser/jsonParser.cpp
        printer.cpp
        Card/ChampCard.cpp
        Parser/json.hpp
)
