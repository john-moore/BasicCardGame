#ifndef GAME_H
#define GAME_H
#include <Deck.h>
#include <iostream>

#include "Player.h"
#include <memory>


class Game {
public:

    enum class GameType {
        FiveCardDraw
    };


    static std::shared_ptr<Game> instance();
    static void startGame(GameType gameType = GameType::FiveCardDraw,
        std::istream& input = std::cin,
        std::ostream& output = std::cout,
        std::ostream& error = std::cerr);

    static void stopGame();

    void addPlayer(const std::string& name);
    [[nodiscard]] std::shared_ptr<Player> findPlayer(const std::string& name) const;

    virtual ~Game() = default;

    virtual int beforeTurn(Player& player) = 0;
    virtual int turn(Player& player) = 0;
    virtual int afterTurn(Player& player) = 0;

    virtual int beforeRound() = 0;
    virtual int round() = 0;
    virtual int afterRound() = 0;

protected:

    Game(std::istream& input, std::ostream& output, std::ostream& error);

    static std::shared_ptr<Game> game;
    Deck mainDeck;

    std::vector<std::shared_ptr<Player>> players;

    std::istream& input;
    std::ostream& output;
    std::ostream& error;

private:

};



#endif //GAME_H
