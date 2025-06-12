#include "Card.h"

 Card::Card(Suit s, Rank r) {
    this->suit = s;
    this->rank = r;
}

int Card::getValue() const {
    return static_cast<int>(rank); // returns the int value of the card
}

bool Card::isAce() const {
    return rank == Rank::Ace;
}