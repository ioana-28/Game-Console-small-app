#include "Console.h"
#include <iostream>

int main(int argc, char* argv[]) {
    Console console;

    if (argc != 3) {
        std::cout << "Usage: ./main1 <install/uninstall> <game_name>\n";
        return 1;
    }

    std::string command = argv[1];
    std::string name = argv[2];

    if (command == "install") {
        console.install(name);
    } else if (command == "uninstall") {
        console.uninstall(name);
    } else {
        std::cout << "Invalid command. Use 'install' or 'uninstall'.\n";
        return 1;
    }

    return 0;
}

