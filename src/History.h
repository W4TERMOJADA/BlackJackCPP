#ifndef HISTORY_H
#define HISTORY_H
#include <string>
#include <map>

class History {
public:
    History(const std::string& filename);
    ~History();
    void load();
    void save() const;
    void updatePlayer(const std::string& playerName, bool didWin);
    void printAll() const;

private:
    std::string filename;
    std::map<std::string, std::pair<int,int>> records;
};
#endif // HISTORY_H