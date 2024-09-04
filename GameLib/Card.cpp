#include "Card.h"
#include <iostream>
#include <fstream>
#include <sstream>

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

Card::Suit Card::next(const Suit& other) {
    return (Suit)((int)other + 1);
}

Card::Rank Card::next(const Rank& other) {
    return (Rank)((int)other + 1);
}

bool Card::operator<(const Card& other) const {
    return rank < other.rank || (rank == other.rank && suit < other.suit);
}

bool Card::operator==(const Card &other) const {
    return rank == other.rank && suit == other.suit;
}

bool Card::operator!=(const Card &other) const {
    return !(*this == other);
}

bool Card::operator<=(const Card& other) const {
    return (*this < other) || (*this == other);
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << Card::rankMap.find(card.rank)->second
       << Card::suitMap.find(card.suit)->second;
    return os;
}

Card parseCard(const std::string& s) {
    const size_t suitIndex = s.length() - 1;
    Card::Suit suit = parseSuit(s.substr(suitIndex, 1));
    Card::Rank rank = parseRank(s.substr(0, suitIndex));
    return { suit, rank };
}

Card::Suit parseSuit(const std::string& s) {
    if (s == "C" || s == "c")
        return Card::Suit::clubs;
    if (s == "H" || s == "h")
        return Card::Suit::hearts;
    if (s == "D" || s == "d")
        return Card::Suit::diamonds;
    if (s == "S" || s == "s")
        return Card::Suit::spades;
    throw std::runtime_error("Invalid suit: " + s);
}

Card::Rank parseRank(const std::string& r) {
    if (r == "2")
        return Card::Rank::two;
    if (r == "3")
        return Card::Rank::three;
    if (r == "4")
        return Card::Rank::four;
    if (r == "5")
        return Card::Rank::five;
    if (r == "6")
        return Card::Rank::six;
    if (r == "7")
        return Card::Rank::seven;
    if (r == "8")
        return Card::Rank::eight;
    if (r == "9")
        return Card::Rank:: nine;
    if (r == "10")
        return Card::Rank::ten;
    if (r == "J" || r == "j")
        return Card::Rank::jack;
    if (r == "Q" || r == "q")
        return Card::Rank::queen;
    if (r == "K" || r == "k")
        return Card::Rank::king;
    if (r == "A" || r == "a")
        return Card::Rank::ace;
    throw std::runtime_error("invalid rank " + r);
}

const std::map<std::string, Card::Suit> Card::stringSuitMap = {
    { "C", Card::Suit::clubs },
    { "c", Card::Suit::clubs },
    { "D", Card::Suit::diamonds },
    { "d", Card::Suit::diamonds },
    { "H", Card::Suit::hearts },
    { "h", Card::Suit::hearts },
    { "S", Card::Suit::spades },
    { "s", Card::Suit::spades },
};

const std::map<Card::Suit, std::string> Card::suitMap = {
    { Card::Suit::clubs, "C" },
    { Card::Suit::diamonds, "D" },
    { Card::Suit::hearts, "H" },
    { Card::Suit::spades, "S" }
};


const std::map<Card::Rank, std::string> Card::rankMap = {
    { Card::Rank::two, "2" },
    { Card::Rank::three, "3" },
    { Card::Rank::four, "4" },
    { Card::Rank::five, "5" },
    { Card::Rank::six, "6" },
    { Card::Rank::seven, "7" },
    { Card::Rank::eight, "8" },
    { Card::Rank::nine, "9" },
    { Card::Rank::ten, "10" },
    { Card::Rank::jack, "J" },
    { Card::Rank::queen, "Q" },
    { Card::Rank::king, "K" },
    { Card::Rank::ace, "A" }
};

const std::map<std::string, Card::Rank> Card::stringRankMap = {
    { "2", Card::Rank::two },
    { "3", Card::Rank::three },
    { "4", Card::Rank::four },
    { "5", Card::Rank::five },
    { "6", Card::Rank::six },
    { "7", Card::Rank::seven },
    { "8", Card::Rank::eight },
    { "9", Card::Rank::nine },
    { "10", Card::Rank::ten },
    { "J", Card::Rank::jack },
    { "j", Card::Rank::jack },
    { "Q", Card::Rank::queen },
    { "q", Card::Rank::queen },
    { "K", Card::Rank::king },
    { "k", Card::Rank::king },
    { "A", Card::Rank::ace },
    { "a", Card::Rank::ace },
};