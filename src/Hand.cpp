#include "Hand.h"
#include "Card.h"
#include <string>
#include <sstream>

Hand::Hand() { cards = new std::vector<Card>(); }
Hand::~Hand() { delete cards; }

void Hand::clear() { cards->clear(); }
void Hand::addCard(const Card& c) { cards->push_back(c); }

int Hand::getBestValue() const {
    int total = 0, numAces = 0;
    for (auto& c : *cards) {
        auto r = c.getRank();
        if (r >= Rank::Two && r <= Rank::Ten) total += static_cast<int>(r);
        else if (r==Rank::Jack||r==Rank::Queen||r==Rank::King) total +=10;
        else { total+=1; numAces++; }
    }
    while(numAces>0 && total+10<=21){ total+=10; numAces--; }
    return total;
}

bool Hand::isBust() const { return getBestValue()>21; }
bool Hand::isBlackjack() const { return cards->size()==2 && getBestValue()==21; }

std::string Hand::toString() const {
    std::ostringstream oss; oss<<"[";
    for(size_t i=0;i<cards->size();++i){ oss<<(*cards)[i].toString(); if(i+1<cards->size())oss<<", "; }
    oss<<"]"; 
    return oss.str();
}