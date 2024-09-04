#include <iostream>
#include "Deck.h"
#include <fstream>

#include "Poker.h"
#include "Game.h"


enum ErrorCodes {
    no_args = 1,
    no_filename,
    invalid_args,
    too_many_args,
    runtime_error,
};

void printUsage(std::string_view name) {
    std::cout << "usage: " << name << " <filename> [-shuffle]" << std::endl;
}

int main(int argc, char** argv) {
    if (argc == 1) {
        printUsage(argv[0]);
        return ErrorCodes::no_args;
    }
    if (argc > 3) {
        printUsage(argv[0]);
        return ErrorCodes::too_many_args;
    }
    if (argc == 2 && !strcmp(argv[1], "-shuffle")) {
        printUsage(argv[0]);
        return ErrorCodes::no_filename;
    }
    if (argc == 3 && !!strcmp(argv[1], "-shuffle")  && !!strcmp(argv[2], "-shuffle")) {
        printUsage(argv[0]);
        return ErrorCodes::invalid_args;
    }

    const std::string_view filename { !strcmp(argv[1], "-shuffle")  ? argv[2] : argv[1] };
    const bool shuffle { argc == 3 };
    const std::filesystem::path path(filename);
    try {
        Game::startGame(Game::GameType::FiveCardDraw);
        auto gamePtr = Game::instance();
        gamePtr->addPlayer("John");
        gamePtr->addPlayer("Sue");
        gamePtr->beforeRound();
        gamePtr->round();
        gamePtr->afterRound();

    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
        return ErrorCodes::runtime_error;
    }
}
