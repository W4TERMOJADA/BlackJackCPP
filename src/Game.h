#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Player.h"
#include "Dealer.h"
#include "History.h"
#include <memory>
#include <string>

class Game {
public:
    Game(History* historyManager);
    ~Game();
    bool playRound(const std::string& playerName);

private:
    History* history;
    void initialDeal(Player* player, Dealer* dealer, Deck* deck);
    void playerTurn(Player* player, Deck* deck);
    void dealerTurn(Dealer* dealer, Deck* deck);
    void showPartialHands(Player* player, Dealer* dealer) const;
    bool determineWinner(Player* player, Dealer* dealer) const;
};
#endif // GAME_H