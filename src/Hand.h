#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include <vector>
#include <string>

class Hand {
public:
    Hand();
    ~Hand();
    void clear();
    void addCard(const Card& c);
    int getBestValue() const;
    bool isBust() const;
    bool isBlackjack() const;
    std::string toString() const;
private:
    std::vector<Card>* cards;
};
#endif // HAND_H