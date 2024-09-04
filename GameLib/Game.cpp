
#include "Game.h"

#include "FiveCardDraw.h"
#include "GameExceptions.h"

std::shared_ptr<Game> Game::game;

std::shared_ptr<Game> Game::instance() {
    if (!game) throw InstanceNotAvailableException("Game instance not found");
    return game;
}

Game::Game(std::istream& input, std::ostream& output, std::ostream& error) :
    input(input),
    output(output),
    error(error) {}

void Game::startGame(GameType gameType, std::istream& input, std::ostream& output, std::ostream& error) {
    if (game) throw GameAlreadyStartedexception("A game has already been started");
    if (gameType == GameType::FiveCardDraw) {
        game = std::make_shared<FiveCardDraw>(input, output, error);
    }
}

void Game::stopGame() {
    if (!game) throw NoGameInProgressException("Trying to stop game that hasn't been started");
    game.reset();
}

void Game::addPlayer(const std::string &name) {
    for (auto& p : players) {
        if (p->name == name) throw PlayerAlreadyExistsException("Player " + name + " already exists");
    }

    players.push_back(std::make_shared<Player>(name));
}

std::shared_ptr<Player> Game::findPlayer(const std::string &name) const {
    for (auto& p : players) {
        if (p->name == name) return p;
    }

    return{};
}






