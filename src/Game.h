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
    Game(std::shared_ptr<History> historyManager);
    ~Game();

    /// Iniciar una partida para el jugador cuyo nombre se pasa como parámetro.
    /// Devuelve true si el jugador ganó, false si perdió.
    bool playRound(const std::string& playerName);

private:
    std::shared_ptr<History> history;

    /// Reparte dos cartas iniciales a jugador y crupier
    void initialDeal(Player& player, Dealer& dealer, Deck& deck);

    /// Turno del jugador (hit/stand via stdin)
    void playerTurn(Player& player, Deck& deck);

    /// Turno del dealer, siguiendo reglas fijas
    void dealerTurn(Dealer& dealer, Deck& deck);

    /// Mostrar estado parcial: manos, puntuaciones (dealer oculta 1 carta)
    void showPartialHands(const Player& player, const Dealer& dealer) const;

    /// Mostrar manos finales de ambos y anunciar resultado
    bool determineWinner(Player& player, Dealer& dealer) const;
};

#endif // GAME_H
