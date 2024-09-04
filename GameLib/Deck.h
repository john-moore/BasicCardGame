#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"
#include "Hand.h"

class Hand;

class Deck {
public:
    Deck() = default;

    explicit Deck(std::istream& deckStream);
    void load(std::istream& deckStream);

    void addCard(const Card& c);

    void shuffle();

    size_t size() const;

    friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
    friend Hand& operator<<(Hand& hand, Deck& deck);

private:
    std::vector<Card> cards;
};


#endif //DECK_H
