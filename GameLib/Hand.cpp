#include "Hand.h"

#include <iostream>
#include <sstream>

size_t Hand::size() const {
    return cards.size();
}

bool Hand::operator==(const Hand &other) const {
    return cards == other.cards;
}

bool Hand::operator!=(const Hand &other) const {
    return !(*this == other);
}

bool Hand::operator<(const Hand &other) const {
    const auto n = std::min(cards.size(), other.cards.size());
    for (int i = 0; i < n; ++i) {
        if (cards[i] < other.cards[i]) return true;
        if (cards[i] == other.cards[i]) continue;
        return false;
    }
    return cards.size() <= other.cards.size();
}

std::string Hand::asString() const {
    const auto n = cards.size();
    if (n == 0) return "";

    std::stringstream ss;
    for (int i = 0; i < n - 1; ++i) {
        ss << cards[i] << " ";
    }
    ss << cards[n-1];
    return ss.str();
}

std::ostream& operator<<(std::ostream& stream, const Hand& hand) {
    stream << hand.asString();
    return stream;
}

void Hand::checkPosn(size_t posn) const {
    if (posn >= cards.size())
        throw std::out_of_range(std::to_string(posn) + " is out of range");
}

const Card& Hand::operator[](size_t posn) const {
    checkPosn(posn);
    return cards[posn];
}

void Hand::removeCard(size_t posn)  {
    checkPosn(posn);
    cards.erase(cards.begin() + (long) posn);
}



