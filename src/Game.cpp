#include "Game.h"
#include <iostream>
#include <limits>

Game::Game(std::shared_ptr<History> historyManager)
    : history(historyManager) {}

Game::~Game() {}

void Game::initialDeal(Player& player, Dealer& dealer, Deck& deck) {
    player.clearHand();
    dealer.clearHand();

    // Dos cartas iniciales a jugador y dealer alternadamente
    player.receiveCard(deck.dealCard());
    dealer.receiveCard(deck.dealCard());
    player.receiveCard(deck.dealCard());
    dealer.receiveCard(deck.dealCard());
}

void Game::playerTurn(Player& player, Deck& deck) {
    while (true) {
        std::cout << "\nTu mano: " << player.showHand(false) << "\n";
        if (player.isBlackjack()) {
            std::cout << "¡Blackjack! Ya tienes 21 con 2 cartas.\n";
            break;
        }
        if (player.isBust()) {
            std::cout << "Te has pasado con " << player.getHandValue() << ".\n";
            break;
        }
        std::cout << "¿Deseas (h)it o (s)tand? ";
        char choice;
        std::cin >> choice;
        // Limpiar resto de línea
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (choice == 'h' || choice == 'H') {
            Card c = deck.dealCard();
            std::cout << "Recibes carta: " << c.toString() << "\n";
            player.receiveCard(c);
        } else if (choice == 's' || choice == 'S') {
            std::cout << "Te plantas con " << player.getHandValue() << ".\n";
            break;
        } else {
            std::cout << "Opción no válida. Elige 'h' o 's'.\n";
        }
    }
}

void Game::dealerTurn(Dealer& dealer, Deck& deck) {
    std::cout << "\nTurno del crupier...\n";
    std::cout << "Mano del crupier: " << dealer.showHand(false) << "\n";
    // Si el crupier tiene blackjack con las dos primeras cartas, se detecta abajo en determineWinner
    while (dealer.shouldHit()) {
        Card c = deck.dealCard();
        std::cout << "Crupier pide carta: " << c.toString() << "\n";
        dealer.receiveCard(c);
        std::cout << "Mano del crupier: " << dealer.showHand(false) << "\n";
        if (dealer.isBust()) {
            std::cout << "El crupier se ha pasado con " << dealer.getHandValue() << ".\n";
            break;
        }
    }
    if (!dealer.isBust()) {
        std::cout << "Crupier se planta con " << dealer.getHandValue() << ".\n";
    }
}

void Game::showPartialHands(const Player& player, const Dealer& dealer) const {
    std::cout << "\n=== Estado Actual ===\n";
    std::cout << "Tu mano:    " << player.showHand(false) << "\n";
    std::cout << "Mano crupier: " << dealer.showHand(true)
              << "  (una carta oculta)\n";
}

bool Game::determineWinner(Player& player, Dealer& dealer) const {
    int playerVal = player.getHandValue();
    int dealerVal = dealer.getHandValue();

    std::cout << "\n=== Resultado Final ===\n";
    std::cout << "Tu mano:    " << player.showHand(false) << "\n";
    std::cout << "Mano crupier: " << dealer.showHand(false) << "\n";

    // Chequeos de Blackjack:
    bool playerBJ = player.isBlackjack();
    bool dealerBJ = dealer.isBlackjack();

    if (playerBJ && !dealerBJ) {
        std::cout << "¡Tienes Blackjack y el crupier no! Ganas.\n";
        return true;
    } else if (!playerBJ && dealerBJ) {
        std::cout << "El crupier tiene Blackjack. Pierdes.\n";
        return false;
    } else if (playerBJ && dealerBJ) {
        std::cout << "Ambos tienen Blackjack. Empate (pero por reglas estándar, se considera empate y nadie gana).\n";
        // Para simplificar, tratamos empate de BJ como derrota del jugador (podría adaptarse).
        return false;
    }

    // Si alguno se pasa:
    if (player.isBust()) {
        std::cout << "Te pasaste. Pierdes.\n";
        return false;
    }
    if (dealer.isBust()) {
        std::cout << "Crupier se pasó. Ganas.\n";
        return true;
    }

    // Comparar valores
    if (playerVal > dealerVal) {
        std::cout << "Tu " << playerVal << " vs " << dealerVal << ". Ganas.\n";
        return true;
    } else if (playerVal < dealerVal) {
        std::cout << "Tu " << playerVal << " vs " << dealerVal << ". Pierdes.\n";
        return false;
    } else {
        std::cout << "Empate a " << playerVal << ". Se considera empate y por defecto el jugador no gana.\n";
        return false;
    }
}

bool Game::playRound(const std::string& playerName) {
    Player player(playerName);
    Dealer dealer;
    Deck deck;

    initialDeal(player, dealer, deck);
    showPartialHands(player, dealer);

    // Turno jugador
    playerTurn(player, deck);

    // Si no está bust y no tiene Blackjack, turno crupier
    if (!player.isBust() && !player.isBlackjack()) {
        dealerTurn(dealer, deck);
    }

    // Determinar ganador final
    bool playerWon = determineWinner(player, dealer);

    // Actualizar histórico
    history->updatePlayer(playerName, playerWon);

    return playerWon;
}
