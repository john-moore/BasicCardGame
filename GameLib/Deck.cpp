#include "Deck.h"

#include <random>
#include <chrono>       // std::chrono::system_clock
#include <fstream>
#include <iostream>
#include <sstream>

Deck::Deck(std::istream& deckStream) {
    load(deckStream);
}

void Deck::load(std::istream& deckStream) {
    cards.clear();
    std::string line;
    while(getline(deckStream, line)) {
        std::string buf;                 // Have a buffer string
        std::stringstream ss(line);       // Insert the string into a stream
        while (ss >> buf) {
            cards.emplace_back(parseCard(buf));
        }
    }
}

void Deck::addCard(const Card &c) {
    if (std::find(cards.begin(), cards.end(), c) != cards.end()) return;
    cards.push_back(c);
}


void Deck::shuffle() {
    const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

size_t Deck::size() const {
    return cards.size();
}

std::ostream& operator<<(std::ostream& os, const Deck& deck) {
    for (auto& card: deck.cards) {
        os << card << std::endl;
    }

    return os;
}

Hand& operator<<(Hand& hand, Deck& deck) {
    // std::cout << "before: " << deck << std::endl;
    hand.cards.push_back(deck.cards.back());
    deck.cards.pop_back();
    std::sort(hand.cards.begin(), hand.cards.end());
    // std::cout << "after: " << deck << std::endl;
    return hand;
}