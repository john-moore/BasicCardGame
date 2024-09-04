#ifndef PLAYER_H
#define PLAYER_H

#include <Hand.h>
#include <ostream>

struct Player {
    explicit Player(const std::string& name);

    std::string name;
    Hand hand;
    int wins;
    int losses;

    friend std::ostream & operator<<(std::ostream &os, const Player &obj) {
        return os
               << "name: " << obj.name
               << " hand: " << obj.hand
               << " wins: " << obj.wins
               << " losses: " << obj.losses;
    }

private:
    void loadPlayer(const std::string& name);
};

#endif //PLAYER_H
