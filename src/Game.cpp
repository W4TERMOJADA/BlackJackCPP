#include "Game.h"
#include <iostream>
#include <limits>

Game::Game(History* historyManager) : history(historyManager) {}
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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (c=='h' || c=='H') {
            Card card = deck->dealCard();
            std::cout << "Recibes: " << card.toString() << "\n";
            player->receiveCard(card);
        } else if (c=='s' || c=='S') break;
    }
}

void Game::dealerTurn(Dealer* dealer, Deck* deck) {
    std::cout << "Turno Dealer...\n";
    std::cout << "Dealer mano: " << dealer->showHand(false) << " ";
    while (dealer->shouldHit()) {
        Card card = deck->dealCard();
        std::cout << "Dealer pide: " << card.toString() << "\n";
        dealer->receiveCard(card);
        std::cout << "Dealer mano: " << dealer->showHand(false) << "\n";
    }
}

bool Game::determineWinner(Player* player, Dealer* dealer) const {
    std::cout << "\n=== Resultado ===\n";
    std::cout << "Tu: " << player->showHand(false) << "\n";
    std::cout << "Dealer: " << dealer->showHand(false) << "\n";
    if (player->isBlackjack() && !dealer->isBlackjack()) return true;
    if (!player->isBust() && dealer->isBust()) return true;
    if (player->isBust()) return false;
    if (player->getHandValue() > dealer->getHandValue()) return true;
    return false;
}

bool Game::playRound(const std::string& playerName) {           //Blackjack clasico, un turno por jugador, se podria hacer mas variantes con modificaciones pequeñas a esta funcion
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

void Game::showPartialHands(Player* player, Dealer* dealer) const {
    std::cout << "=== Manos Iniciales ===\n";
    std::cout << "Tu mano: " << player->showHand(false) << "\n";
    std::cout << "Dealer mano: " << dealer->showHand(true) << " (oculto)\n";  //podriamos mostrarla, mostrar solo una...
}