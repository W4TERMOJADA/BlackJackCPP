#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <vector>
#include <random>

class Deck {
public:
    Deck();
    ~Deck();
    void shuffle();
    Card dealCard();
    int cardsRemaining() const;
private:
    std::vector<Card>* cards;
    std::mt19937* rng;
};
#endif // DECK_H