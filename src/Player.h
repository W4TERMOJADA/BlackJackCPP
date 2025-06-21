#ifndef PLAYER_H
#define PLAYER_H
#include "Participant.h"
#include <string>
class Player : public Participant {
public:
    Player(const std::string& name);
    ~Player();
    const std::string& getName() const;
    void recordWin();
    void recordLoss();
    int getWins() const;
    int getLosses() const;
private:
    std::string name;
    int wins;
    int losses;
};
#endif // PLAYER_H