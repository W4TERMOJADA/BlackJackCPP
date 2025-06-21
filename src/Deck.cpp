#include "Deck.h"
#include <algorithm>
#include <chrono>

Deck::Deck() {
    cards = new std::vector<Card>();
    rng = new std::mt19937(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));
    for (int s = static_cast<int>(Suit::Hearts); s <= static_cast<int>(Suit::Spades); ++s)
        for (int r = static_cast<int>(Rank::Two); r <= static_cast<int>(Rank::Ace); ++r)
            cards->emplace_back(static_cast<Rank>(r), static_cast<Suit>(s));
    shuffle();
}
Deck::~Deck() {
    delete cards;
    delete rng;
}
void Deck::shuffle() {
    std::shuffle(cards->begin(), cards->end(), *rng);
}
Card Deck::dealCard() {
    Card c = cards->back();
    cards->pop_back();
    return c;
}
int Deck::cardsRemaining() const {
    return static_cast<int>(cards->size());
}