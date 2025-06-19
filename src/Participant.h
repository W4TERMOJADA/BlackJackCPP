
#pragma once
#include <string>

class Participant {
private:




public:
    virtual ~Participant() = default;

    // Returns the name of the participant
    virtual std::string getName() const = 0;

    // Returns the total value of the participant's hand
    virtual int getHandValue() const = 0;

    // Checks if the participant has a blackjack
    virtual bool isBlackjack() const = 0;

    // Checks if the participant is bust (over 21)
    virtual bool isBust() const = 0;

    // Clears the participant's hand
    virtual void clearHand() = 0;

    // Receives a card and adds it to the participant's hand
    virtual void receiveCard(const Card& card) = 0;

    // Displays the participant's hand, optionally hiding some cards
    virtual std::string showHand(bool hideFirstCard) const = 0;
}