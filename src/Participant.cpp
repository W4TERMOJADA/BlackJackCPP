#include "Participant.h"
#include <sstream>
Participant::Participant(){ hand=new Hand(); }
Participant::~Participant(){ delete hand; }
void Participant::clearHand(){ hand->clear(); }
void Participant::receiveCard(const Card& c){ hand->addCard(c); }
int Participant::getHandValue() const{ return hand->getBestValue(); }
bool Participant::isBust() const{ return hand->isBust(); }
bool Participant::isBlackjack() const{ return hand->isBlackjack(); }
std::string Participant::showHand(bool hideFirst) const {
    return hand->toString() + " (" + std::to_string(getHandValue()) + ")";
}