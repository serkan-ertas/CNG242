///*** Serkan Ertas ***///

#include "Game.h"

#include "elementsubclasses.h"
#include "wildanimals.h"

// Game Constructor with parameters
Game::Game(int playerNumber, int gridSize) : gameGrid(Grid(gridSize)) {
    // INITIALIZE YOUR ELEMENTS HERE
    Bear bear;
    Wolf wolf;
    Food food;
    Wood wood;
    MedSup med_sup;
    Gold gold;

    // DEPLOY THOSE ELEMENTS HERE
    // true for normal number of Elements
    // false for half number of Elements
    gameGrid.deploy_elements(&bear, false);
    gameGrid.deploy_elements(&wolf, true);
    gameGrid.deploy_elements(&food, true);
    gameGrid.deploy_elements(&wood, true);
    gameGrid.deploy_elements(&med_sup, true);
    gameGrid.deploy_elements(&gold, true);

    // get Players' informations
    for (int i = 1; i < playerNumber + 1; i++) {
        std::string name;
        std::cout << "Enter " << i << "th player's name:";
        std::cin >> name;
        playerList.push_back(Player(name, gridSize));
    }
}

// Start the game
void Game::Play() {
    std::cout << "Welcome to GOLD RUSH ALASKA!!" << std::endl;

    // if one player alive, continue to play
    while (!everyPlayerDead()) {
        // for every player, check if the Gold in the Grid is finished
        // if finished, stop
        for (Player &player: playerList) {
            if (!player.playerDead() && !gameGrid.goldFinish()) {
                gameGrid.printGrid();
            }
            player.visitElement(gameGrid);
            std::cout << std::endl;
        }
    }

    // print the winners!
    theWinner();
}

// Check if every player dead
bool Game::everyPlayerDead() {
    // if every player is dead, check remains true
    // if one of players is alive, check becomes false
    bool check = true;
    for (Player &player: playerList) {
        check = check && player.playerDead();
    }
    return check;
}

// Find the winners and print
void Game::theWinner() {
    // find the max score of all Players
    int maxscore = 0;
    std::vector<Player *> winners;
    for (Player &player: playerList) {
        if (player.getScore() > maxscore) {
            maxscore = player.getScore();
        }
    }

    // find the Players with max score
    // add those Players to <winners>
    for (Player &player: playerList) {
        if (player.getScore() == maxscore) {
            winners.push_back(&player);
        }
    }

    // print the winners
    std::cout << "CONGRATULATIONS!!" << std::endl;
    std::cout << "THE WINNER LIST:" << std::endl;
    int count = 1;
    for (Player *player: winners) {
        std::cout << "[" << count++ << "] " << player->getPlayerName() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "The game is finished." << std::endl;
}
