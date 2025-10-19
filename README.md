# Game-Console-small-app
This is a game console management system


The Game Console application is a console-based program designed to manage a collection of video games. It allows users to view available games, install new games, uninstall existing ones, and sort the installed games either by name or by size. The app keeps track of the total storage used and ensures that games can only be installed if there is enough available memory. All the data about available and installed games is saved and loaded from files, making the game library persistent across sessions.

The main idea behind this project was to collaborate with someone else, working together to design, implement, and test the features. This teamwork helped to divide responsibilities, share ideas, and create a more robust and polished application.

To run the application, I used MinGW64. First, open your terminal and navigate to the GameConsole folder. Then, compile the programs by running the following commands to build main1.cpp and main2.cpp:
      g++ main1.cpp src/Console.cpp src/Game.cpp -Iinclude -o main1.exe
      g++ main2.cpp src/Console.cpp src/Game.cpp -Iinclude -o main2.exe


Once compiled, the app is ready to use. The file available_games.txt contains the number of games available for installation, along with each game's name and size.

You can run the following commands to interact with the application:
    Console Management Application (main1.exe):
          To install a game (if there is enough free space):./main1 install <game_name>
          To uninstall a game (which will free up its used memory):./main1 uninstall <game_name>
    Installed Games Management Application (main2.exe):
          To display all currently installed games:./main2 view
          To sort installed games alphabetically by name (A-Z):./main2 sortname
          To sort installed games by size (smallest to largest):./main2 sortsize

The application also provides clear error messages for common issues, such as attempting to install a game not listed in available_games.txt or trying to install a game that is already installed.
