#include "History.h"
#include <fstream>
#include <iostream>
#include <sstream>

History::History(const std::string& filename)
    : filename(filename) {
    load();
}

History::~History() {
    save();
}

void History::load() {
    records.clear();
    std::ifstream file(filename);
    if (!file.is_open()) return;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        int w, l;
        if (iss >> name >> w >> l) {
            records[name] = {w, l};
        }
    }
}

void History::save() const {
    std::ofstream file(filename, std::ofstream::trunc);
    if (!file.is_open()) {
        std::cerr << "No se pudo guardar histórico en " << filename << "";
        return;
    }
    for (const auto& kv : records) {
        file << kv.first << " " << kv.second.first << " " << kv.second.second << "";
    }
}

void History::updatePlayer(const std::string& playerName, bool didWin) {
    auto it = records.find(playerName);
    if (it == records.end()) {
        records[playerName] = didWin ? std::make_pair(1, 0) : std::make_pair(0, 1);
    } else {
        if (didWin) it->second.first++;
        else it->second.second++;
    }
    save();
}

void History::printAll() const {
    if (records.empty()) {
        std::cout << "No hay registros de juego.";
        return;
    }
    std::cout << "Jugador      Victorias  Derrotas";
    std::cout << "------------------------------";
    for (const auto& kv : records) {
        std::cout << kv.first << "      " << kv.second.first << "         " << kv.second.second << " ";
    }
}