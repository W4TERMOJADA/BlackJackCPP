#include "Game.h"
#include <iostream>
#include <limits>

Game::Game(History* historyManager)
    : history(historyManager) {}
Game::~Game() {}

void Game::initialDeal(Player* player, Dealer* dealer, Deck* deck) {
    player->clearHand();
    dealer->clearHand();
    player->receiveCard(deck->dealCard());
    dealer->receiveCard(deck->dealCard());
    player->receiveCard(deck->dealCard());
    dealer->receiveCard(deck->dealCard());
}

void Game::playerTurn(Player* player, Deck* deck) {
    while (true) {
        std::cout << "Tu mano: " << player->showHand(false) << "";
        if (player->isBlackjack() || player->isBust()) break;
        std::cout << "¿Hit (h) o Stand (s)? ";
        char c;
        std::cin >> c;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '');
        if (c=='h' || c=='H') {
            Card card = deck->dealCard();
            std::cout << "Recibes: " << card.toString() << "";
            player->receiveCard(card);
        } else if (c=='s' || c=='S') break;
    }
}

void Game::dealerTurn(Dealer* dealer, Deck* deck) {
    std::cout << "Turno Dealer...";
    std::cout << "Dealer mano: " << dealer->showHand(false) << " ";
    while (dealer->shouldHit()) {
        Card card = deck->dealCard();
        std::cout << "Dealer pide: " << card.toString() << "";
        dealer->receiveCard(card);
        std::cout << "Dealer mano: " << dealer->showHand(false) << "";
    }
}

bool Game::determineWinner(Player* player, Dealer* dealer) const {
    std::cout << "=== Resultado ===";
    std::cout << "Tu: " << player->showHand(false) << "";
    std::cout << "Dealer: " << dealer->showHand(false) << "";
    if (player->isBlackjack() && !dealer->isBlackjack()) return true;
    if (!player->isBust() && dealer->isBust()) return true;
    if (player->isBust()) return false;
    if (player->getHandValue() > dealer->getHandValue()) return true;
    return false;
}

bool Game::playRound(const std::string& playerName) {
    Player* player = new Player(playerName);
    Dealer* dealer = new Dealer();
    Deck* deck = new Deck();
    initialDeal(player, dealer, deck);
    showPartialHands(player, dealer);
    playerTurn(player, deck);
    if (!player->isBust() && !player->isBlackjack()) dealerTurn(dealer, deck);
    bool win = determineWinner(player, dealer);
    history->updatePlayer(playerName, win);
    delete player;
    delete dealer;
    delete deck;
    return win;
}