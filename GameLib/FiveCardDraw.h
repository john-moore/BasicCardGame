
#ifndef FIVECARDDRAW_H
#define FIVECARDDRAW_H
#include "Game.h"


class FiveCardDraw : public Game {
public:
    explicit FiveCardDraw(
        std::istream& input = std::cin,
        std::ostream& output = std::cout,
        std::ostream& error = std::cerr);

    int beforeRound() override;

    int round() override;

    int afterRound() override;

    int beforeTurn(Player &player) override;

    int turn(Player &player) override;

    int afterTurn(Player &player) override;



protected:

    size_t dealer;
    Deck discardDeck;
};



#endif //FIVECARDDRAW_H
