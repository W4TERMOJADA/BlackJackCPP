#ifndef CARD_H
#define CARD_H
#include <string>

enum class Suit { Hearts, Diamonds, Clubs, Spades };
enum class Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

class Card {
public:
    Card(Rank r, Suit s);
    Rank getRank() const;
    Suit getSuit() const;
    std::string toString() const;
private:
    Rank rank;
    Suit suit;
};
#endif // CARD_H