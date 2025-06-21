#include "Game.h"
#include "History.h"
#include <iostream>
#include <limits>

int main() {
    History* history = new History("history.txt");
    Game* game = new Game(history);
    while (true) {
        std::cout << " 1) Jugar  2) Historial  3) Salir: \n";
        int opt;
        std::cin >> opt;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (opt == 1) {
            std::cout << "Nombre: ";
            std::string name;
            std::getline(std::cin, name);
            game->playRound(name);
        } else if (opt == 2) {
            history->printAll();
        } else break;
    }
    delete game;
    delete history;
    return 0;
}