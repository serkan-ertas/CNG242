///*** Serkan Ertas ***///

#ifndef GAME_H
#define GAME_H
#include "Player.h"

// This class will be the container class of Grid and Players
class Game {
private:
    std::vector<Player> playerList;
    Grid gameGrid;

public:
    // Game Constructor with parameters
    Game(int playerNumber, int gridSize);

    // Start the game
    void Play();

    // Check if every player dead
    bool everyPlayerDead();

    // Find the winners and print
    void theWinner();
};


#endif //GAME_H
