#include "Player.h"

Player::Player(const std::string& name)
    : name(name), wins(0), losses(0) {}

Player::~Player() {}

const std::string& Player::getName() const {
    return name;
}

void Player::recordWin() {
    wins++;
}

void Player::recordLoss() {
    losses++;
}

int Player::getWins() const {
    return wins;
}

int Player::getLosses() const {
    return losses;
}