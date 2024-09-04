//
// Created by John Moore on 8/27/24.
//

#include "Poker.h"

namespace Poker {

    HandRank rankHand(const Hand &hand) {
        if (hasStraightFlush(hand)) {
            return HandRank::straight_flush;
        } else if (hasFourOfAKind(hand)) {
            return HandRank::four_of_a_kind;
        } else if (hasFullHouse(hand)) {
            return HandRank::full_house;
        } else if (hasFlush(hand)) {
            return HandRank::flush;
        } else if (hasStraight(hand)) {
            return HandRank::straight;
        } else if (hasThreeOfAKind(hand)) {
            return HandRank::three_of_a_kind;
        } else if (hasTwoPairs(hand)) {
            return HandRank::two_pairs;
        } else if (hasOnePair(hand)) {
            return HandRank::one_pair;
        } else {
            return HandRank::no_rank;
        }
    }

    bool rankGreaterThanEqual(const Hand& left, const Hand& right) {
        return rankHand(left) >= rankHand(right);
    }

    bool hasStraightFlush(const Hand& hand)  {
        const size_t numCards { hand.size() };
        for (int i = 1; i < numCards; ++i) {
            if (hand[i].suit != hand[i-1].suit) return false;
            if (hand[i].rank != Card::next(hand[i-1].rank)) return false;
        }
        return true;
    }

    bool hasFourOfAKind(const Hand& hand) {
        int maxRun = 0;
        int currRun = 1;

        for (int i = 1; i < hand.size(); ++i) {
            if (hand[i].rank == hand[i-1].rank) currRun++;
            else {
                maxRun = std::max(maxRun, currRun);
                currRun = 1;
            }
        }
        maxRun = std::max(maxRun, currRun);
        return maxRun >= 4;
    }

    bool hasFullHouse(const Hand& hand) {
        int maxRun = 0;
        int minRun = INT_MAX;
        int currRun = 1;

        for (int i = 1; i < hand.size(); ++i) {
            if (hand[i].rank == hand[i-1].rank) currRun++;
            else {
                maxRun = std::max(maxRun, currRun);
                minRun = std::min(minRun, currRun);
                currRun = 1;
            }
        }
        maxRun = std::max(maxRun, currRun);
        minRun = std::min(minRun, currRun);
        return maxRun == 3 && minRun == 2;
    }

    bool hasFlush(const Hand& hand) {
        const Card::Suit suit = hand[0].suit;
        for (int i = 1; i < hand.size(); ++i) {
            if (hand[i].suit != suit) return false;
        }
        return true;
    }

    bool hasStraight(const Hand& hand) {
        for (int i = 1; i < hand.size(); ++i) {
            if (hand[i].rank != Card::next(hand[i-1].rank)) return false;
        }
        return true;
    }

    bool hasThreeOfAKind(const Hand& hand) {
        int maxRun = 0;
        int currRun = 1;

        for (int i = 1; i < hand.size(); ++i) {
            if (hand[i].rank == hand[i-1].rank) currRun++;
            else {
                maxRun = std::max(maxRun, currRun);
                currRun = 1;
            }
        }
        maxRun = std::max(maxRun, currRun);
        return maxRun == 3;
    }

    bool hasTwoPairs(const Hand& hand) {
        int twoRuns = 0;
        int currRun = 1;

        for (int i = 1; i < hand.size(); ++i) {
            if (hand[i].rank == hand[i-1].rank) currRun++;
            else {
                if (currRun == 2) twoRuns++;
                currRun = 1;
            }
        }
        if (currRun == 2) twoRuns++;

        return twoRuns == 2;
    }

    bool hasOnePair(const Hand& hand) {
        int twoRuns = 0;
        int currRun = 1;

        for (int i = 1; i < hand.size(); ++i) {
            if (hand[i].rank == hand[i-1].rank) currRun++;
            else {
                if (currRun > 2) return false;
                if (currRun == 2) twoRuns++;
                currRun = 1;
            }
        }
        if (currRun == 2) twoRuns++;
        if (currRun > 2) return false;
        return twoRuns == 1;
    }
}