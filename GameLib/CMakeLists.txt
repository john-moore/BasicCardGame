cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 20)

set (SOURCE Card.cpp
            Deck.cpp
            Hand.cpp
            Poker.cpp
        Player.cpp
        Player.h
        Game.cpp
        Game.h
        FiveCardDraw.cpp
        FiveCardDraw.h
        GameExceptions.cpp
        GameExceptions.h)

add_library(GameLib STATIC ${SOURCE})
target_include_directories(GameLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")






