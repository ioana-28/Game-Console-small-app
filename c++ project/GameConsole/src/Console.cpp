#include "Console.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <iomanip>

Console::Console() : usedMemory(0) {
    loadAvailable();
    loadInstalled();
}

void Console::loadAvailable() {
    std::ifstream in("available_games.txt");
    if (!in) {
        std::cerr << "Error: cannot open available_games.txt\n";
        return;
    }

    int n;
    in >> n;
    if (!in) return;

    availableGames.clear();
    for (int i = 0; i < n; ++i) {
        std::string name;
        double size;
        if (!(in >> name >> size)) break;
        availableGames.emplace_back(name, size);
    }
}

void Console::loadInstalled() {
    std::ifstream in("installed_games.txt");
    if (!in) {
        std::cerr << "Error: cannot open installed_games.txt\n";
        return;
    }

    int n;
    in >> n;
    if (!in) return;

    installedGames.clear();
    usedMemory = 0;

    for (int i = 0; i < n; ++i) {
        std::string name;
        double size;
        if (!(in >> name >> size)) break;
        installedGames.emplace_back(name, size);
        usedMemory += static_cast<int>(size);
    }
}

void Console::saveInstalled() {
    std::ofstream out("installed_games.txt");
    if (!out) {
        std::cerr << "Error: cannot open installed_games.txt for writing\n";
        return;
    }

    out << installedGames.size() << "\n";
    for (const auto& game : installedGames) {
        out << game.name << " " << game.size << "\n";
    }
}

void Console::showAvailable() const {
    for (const auto& g : availableGames) {
        g.display();
    }
}

void Console::showInstalled() const {
    if (installedGames.empty()) {
        throw std::runtime_error("No games installed.");
    }

    std::cout << std::left << std::setw(20) << "Name" << "Size (GB)\n";
    std::cout << "------------------------------------\n";


    for (const Game& g : installedGames) {
        g.display();
    }
}



void Console::install(const std::string& gameName) {
    auto it = std::find_if(availableGames.begin(), availableGames.end(),
        [&gameName](const Game& g) { return g.name == gameName; });

    if (it == availableGames.end()) {
        std::cout << "\033[31mGame not found.\033[0m\n";
        return;
    }

    try {
        if (usedMemory + static_cast<int>(it->size) > 1024) {
            throw std::runtime_error("Not enough memory.");
        }

        if (std::any_of(installedGames.begin(), installedGames.end(),
            [&gameName](const Game& g) { return g.name == gameName; })) {
            std::cout << "\033[33mGame already installed.\033[0m\n";
            return;
        }

        installedGames.push_back(*it);
        usedMemory += static_cast<int>(it->size);
        saveInstalled();
        std::cout << "\033[32mGame installed.\033[0m\n";

    } catch (const std::runtime_error& e) {
        std::cout << "\033[31m" << e.what() << "\033[0m\n";
    } catch (const std::exception& e) {
        std::cerr << "Error installing game: " << e.what() << std::endl;
    }
}


void Console::uninstall(const std::string& gameName) {
    auto it = std::find_if(installedGames.begin(), installedGames.end(),
        [&gameName](const Game& g) { return g.name == gameName; });

    if (it != installedGames.end()) {
        usedMemory -= static_cast<int>(it->size);
        installedGames.erase(it);
        saveInstalled();
        std::cout << "\033[33mGame uninstalled.\033[0m\n";
    } else {
        std::cout << "\033[31mGame not installed.\033[0m\n";
    }
}

void Console::sortByName() {
    if (installedGames.empty()) {
        throw std::runtime_error("No games installed to sort.");
    }
    std::sort(installedGames.begin(), installedGames.end(),
        [](const Game& a, const Game& b) { return a.name < b.name; });
    showInstalled();
}


void Console::sortBySize() {
    if (installedGames.empty()) {
        throw std::runtime_error("No games installed to sort.");
    }
    std::sort(installedGames.begin(), installedGames.end(),
        [](const Game& a, const Game& b) { return a.size < b.size; });
    showInstalled();
}



