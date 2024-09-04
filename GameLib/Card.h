#ifndef CARD_H
#define CARD_H

#include <vector>
#include <map>
#include <string>

struct Card {
    enum class Suit {
        begin = 0,
        clubs = 0, diamonds, hearts, spades,
        end = spades + 1
    };

    static Suit next(const Suit& other);

    enum class Rank {
        begin = 0,
        two = 0, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace,
        end = ace + 1
    };

    static Rank next(const Rank& other);

    const static std::map<Suit, std::string> suitMap;
    const static std::map<std::string, Suit> stringSuitMap;
    const static std::map<Rank, std::string> rankMap;
    const static std::map<std::string, Rank> stringRankMap;


    Card(Suit suit, Rank rank);

    bool operator<(const Card& other) const;
    bool operator<=(const Card& other) const;
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Card& card);

    Rank rank;
    Suit suit;
};

Card::Suit& operator++(const Card::Suit& other);

Card::Suit parseSuit(const std::string& s);
Card::Rank parseRank(const std::string& r);
Card parseCard(const std::string& s);

#endif //CARD_H
