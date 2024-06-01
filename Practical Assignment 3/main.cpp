///*** Serkan Ertas ***///

#include <algorithm>
#include <ctime>

#include "Game.h"

int main() {
    srand(time(nullptr));
    int playerNumber = 0;
    while (playerNumber < 2) {
        // Valid Player Number input (min 2)
        std::cout << "How many players will be playing in this game (min 2):";
        std::cin >> playerNumber;
    }

    int gridSize = 0;
    while (gridSize < 5) {
        // Valid Grid Size input (min 5)
        std::cout << "What do you want the grid size(nxn) to be (min 5):";
        std::cin >> gridSize;
    }

    // let the game begin
    Game theGame(playerNumber, gridSize);
    theGame.Play();

    return 0;
}
