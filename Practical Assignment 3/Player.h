///*** Serkan Ertas ***///

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include <iostream>

#include "Grid.h"

class Player {
private:
    std::string name;
    int hp;
    int score;
    std::vector<Element *> logElement;

public:
    // number of players playing the game
    static int numberOfPlayers;

    // Player Constructor, default
    Player();

    // Player Constructor, parameterized
    Player(std::string name, int n);

    // Player Copy Constructor
    Player(const Player &);

    // Player Assignment Operator
    Player &operator=(const Player &);

    // Player Destructor
    ~Player();

    // Visit an Element in the given Grid
    void visitElement(Grid &);

    // Check if the Player is dead
    bool playerDead() const;

    // Get Player's score
    int getScore() const;

    // Get Player's name
    std::string getPlayerName();

private:
    // Check if it is the time for Gold bonus
    bool goldBonus();

    // Check if it is the time for Wood bonus
    bool woodBonus();

    // Random Number Generator
    static int PlayerRNG(const int, const int);

    // Throw a dice, get an input (odd | even)
    bool diceRoll();
};


#endif //PLAYER_H
