#include "Console.h"
#include <iostream>

int main(int argc, char* argv[]) {
    Console console;

    if (argc != 2) {
        std::cout << "Usage: ./main2 <view/sortname/sortsize>\n";
        return 1;
    }

    std::string command = argv[1];

 try {
    if (command == "view") {
        console.showInstalled();
    } else if (command == "sortname") {
        console.sortByName();
    } else if (command == "sortsize") {
        console.sortBySize();
    } else {
        std::cout << "Invalid command.\n";
    }
} catch (const std::runtime_error& e) {
    std::cout << "\033[31m" << e.what() << "\033[0m\n";
}

    return 0;
}


