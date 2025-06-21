#include "Dealer.h"

Dealer::Dealer() : Participant() {}
Dealer::~Dealer() {}

bool Dealer::shouldHit() const {
    int value = getHandValue();
    return value <= 16;
}