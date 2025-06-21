#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include "Hand.h"
#include "Card.h"
#include <string>
class Participant {
public:
    Participant();
    virtual ~Participant();
    void clearHand();
    void receiveCard(const Card& c);
    int getHandValue() const;
    bool isBust() const;
    bool isBlackjack() const;
    std::string showHand(bool hideFirst=false) const;
protected:
    Hand* hand;
};
#endif // PARTICIPANT_H