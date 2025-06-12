#include <string>
#include <vector>
#include <iostream>

#pragma once

enum class Suit { Hearts, Diamonds, Clubs, Spades};
enum class Rank {
    Two = 2, Three, Four, Five, Six, Seven,
    Eight, Nine, Ten, Jack = 10, Queen = 10, King = 10, Ace = 1
};

class Card {
private:
    Suit suit;
    Rank rank;

    std::string suitToString() const;
    std::string rankToString() const;

public:

    Card(Suit s, Rank r);

    std::string toString() const {
        return rankToString() + " of " + suitToString();
    }

    int getValue() const;
    bool isAce() const;


}