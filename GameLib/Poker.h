#ifndef POKERHANDSCORER_H
#define POKERHANDSCORER_H

#include <map>

#include "Hand.h"

namespace Poker {

    static constexpr int NUM_CARDS = 5;
    enum HandRank {
        no_rank,
        one_pair,
        two_pairs,
        three_of_a_kind,
        straight,
        flush,
        full_house,
        four_of_a_kind,
        straight_flush,
    };

    const static std::map<HandRank, std::string> rankMap;

    HandRank rankHand(const Hand& hand);

    bool rankGreaterThanEqual(const Hand& left, const Hand& right);

    bool hasStraightFlush(const Hand& hand);
    bool hasFourOfAKind(const Hand& hand);
    bool hasFullHouse(const Hand& hand);
    bool hasFlush(const Hand& hand);
    bool hasStraight(const Hand& hand);
    bool hasThreeOfAKind(const Hand& hand);
    bool hasTwoPairs(const Hand& hand);
    bool hasOnePair(const Hand& hand);

}





#endif //POKERHANDSCORER_H
