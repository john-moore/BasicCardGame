#include "FiveCardDraw.h"

#include <Poker.h>
#include <ranges>
#include <sstream>
#include <set>

#include "Card.h"

FiveCardDraw::FiveCardDraw(std::istream &input, std::ostream &output, std::ostream &error) :
    Game(input, output, error), dealer(0) {

    for (auto suit = Card::Suit::begin; suit != Card::Suit::end; suit = Card::next(suit)) {
        for (auto rank = Card::Rank::begin; rank != Card::Rank::end; rank = Card::next(rank)) {
            mainDeck.addCard(Card(suit, rank));
        }
    }
}

int FiveCardDraw::beforeTurn(Player &player) {
    output << "Before Turn:" << std::endl;
    output << player << std::endl;
    bool failing { true };
    while (failing) {
        failing = false;
        output << "List positions to discard (1-based, 0 = done): " << std::endl;
        std::string cardPositions;

        std::set<int> positions;
        while (input >> cardPositions) {
            int num = std::stoi( cardPositions );
            if (num == 0) break;
            if (num > player.hand.size() || positions.contains(num)) {
                output << num << " is a bad input. Try again." << std::endl;
                failing = true;
                break;
            }
            positions.insert(num);
        }
        if (failing) continue;

        if (positions.empty()) output << "No cards chosen." << std::endl;
        else output << "Positions chosen are: " << std::endl;
        for (const auto currPos : positions) {
            output << currPos << " ";
        }
        for (const int position : std::ranges::reverse_view(positions)) {
            discardDeck.addCard(player.hand[position - 1]);
            player.hand.removeCard(position - 1);
        }
    }

    return 0;
}

int FiveCardDraw::turn(Player &player) {
    output << "Player's turn: " << player.name << std::endl;
    size_t cardsNeeded = Poker::NUM_CARDS - player.hand.size();
    if (cardsNeeded == 0) return 0;

    const auto mainCards = std::min(cardsNeeded, mainDeck.size());
    for (int i = 0; i < mainCards; ++i) {
        player.hand << mainDeck;
    }
    cardsNeeded -= mainCards;
    if (cardsNeeded == 0) return 0;
    if (cardsNeeded > discardDeck.size()) return 1;

    discardDeck.shuffle();
    for (int i = 0; i < cardsNeeded; ++i) {
        player.hand << discardDeck;
    }
    return 0;
}

int FiveCardDraw::afterTurn(Player &player) {
    output << "After turn: " << std::endl;
    output << player << std::endl;
    return 0;
}

int FiveCardDraw::beforeRound() {
    mainDeck.shuffle();

    const size_t firstPlayer = (dealer + 1) % players.size();
    for (int i = 1; i <= Poker::NUM_CARDS; ++i) {
        for (size_t playerOffset = 0; playerOffset < players.size(); ++playerOffset) {
            const size_t playerPos = (firstPlayer + playerOffset) % players.size();
            players[playerPos]->hand << mainDeck;
        }
    }

    for (const auto& player : players) {
        beforeTurn(*player);
    }

    return 0;
}

int FiveCardDraw::round() {
    for (const auto& player : players) {
        turn(*player);
        afterTurn(*player);
    }
    return 0;
}

int FiveCardDraw::afterRound() {
    output << "After round: " << std::endl;
    for (const auto& player : players) {
        output << *player << std::endl;
    }
    return 0;
}
