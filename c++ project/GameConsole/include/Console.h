#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>
#include <vector>
#include "Game.h"

class Console {
private:
    std::vector<Game> availableGames;
    std::vector<Game> installedGames;
    int usedMemory;

public:
    Console();

    void loadAvailable();
    void loadInstalled();
    void saveInstalled();

    void showAvailable() const;
    void showInstalled() const;

    void install(const std::string& gameName);
    void uninstall(const std::string& gameName);

    void sortByName();
    void sortBySize();
};

#endif

