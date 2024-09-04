#include "Player.h"

Player::Player(const std::string&  name) :
    name(name), wins(0), losses(0) {

    loadPlayer(name);
}

void Player::loadPlayer(const std::string &name) {

}

