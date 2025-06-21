#include "Card.h"
#include <map>

Card::Card(Rank r, Suit s) : rank(r), suit(s) {}
Rank Card::getRank() const { return rank; }
Suit Card::getSuit() const { return suit; }
std::string Card::toString() const {
    static const std::map<Rank, std::string> rankStrings = {{Rank::Two,"2"},{Rank::Three,"3"},{Rank::Four,"4"},{Rank::Five,"5"},{Rank::Six,"6"},{Rank::Seven,"7"},{Rank::Eight,"8"},{Rank::Nine,"9"},{Rank::Ten,"10"},{Rank::Jack,"J"},{Rank::Queen,"Q"},{Rank::King,"K"},{Rank::Ace,"A"}};
    static const std::map<Suit, std::string> suitStrings = {
    {Suit::Hearts, "H"},
    {Suit::Diamonds, "D"},
    {Suit::Clubs, "C"},
    {Suit::Spades, "S"}
};
    return rankStrings.at(rank) + suitStrings.at(suit);
}