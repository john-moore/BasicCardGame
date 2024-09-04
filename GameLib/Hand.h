#ifndef HAND_H
#define HAND_H

#include <vector>
#include "Card.h"
#include "Deck.h"

class Deck;

class Hand {
public:
    Hand() = default;
    Hand(const Hand& other) = default;
    Hand& operator=(const Hand& other) = default;
    [[nodiscard]] size_t size() const;

    bool operator==(const Hand& other) const;
    bool operator!=(const Hand& other) const;
    bool operator<(const Hand& other) const;

    friend std::ostream& operator<<(std::ostream& stream, const Hand& hand);
    friend Hand& operator<<(Hand& hand, Deck& deck);

    const Card& operator[](size_t posn) const;

    void removeCard(size_t posn);

    [[nodiscard]] std::string asString() const;

private:
    void checkPosn(size_t posn) const;


    std::vector<Card> cards;


};

#endif //HAND_H
