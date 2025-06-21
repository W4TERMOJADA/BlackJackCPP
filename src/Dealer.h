#ifndef DEALER_H
#define DEALER_H
#include "Participant.h"

class Dealer : public Participant {
public:
    Dealer();
    ~Dealer();
    bool shouldHit() const;
};
#endif // DEALER_H