#pragma once

#include "Player.h"
#include "Dealer.h"
#include "History.h"

#include <vector>
#include "Card.h"
#include <random>

class Deck {
    private:
    std::vector<Card>* cards;
    std::mt19937* rng;

    public:
    Deck();
    ~Deck();

    void shufle();
    Card dealCard();
    int getRemainingCards() const;

    
    
}