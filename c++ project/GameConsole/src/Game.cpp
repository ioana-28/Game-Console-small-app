#include "Game.h"
#include <iostream>
#include <iomanip>
Game::Game() : name("Unknown"), size(0.0) {}

Game::Game(std::string n, double s) : name(std::move(n)), size(s) {}

void Game::display() const {
std::cout << std::left << std::setw(20) << name << size<<std::endl;
}

