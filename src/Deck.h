#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "History.h"
#include <memory>
#include <string>

public class Deck {
    private:
    std::vector<Card> cards; 
    int currentCardIndex; 
    public:
    Deck() : currentCardIndex(0) {
        // Initialize the deck with 52 cards
        for (int suit = 0; suit < 4; ++suit) {
            for (int rank = 1; rank <= 13; ++rank) {
                cards.emplace_back(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
            }
        }
        shuffle(); // Shuffle the deck upon creation
    }
}