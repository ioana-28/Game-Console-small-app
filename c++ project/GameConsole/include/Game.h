#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>

class Game {
public:
    std::string name;
    double size;

    Game();
    Game(std::string n, double s);

    void display() const;
};

#endif

