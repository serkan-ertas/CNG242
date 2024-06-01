///*** Serkan Ertas ***///

#include "Player.h"

// initialize the number of players playing the game
int Player::numberOfPlayers = 0;

// Player Constructor, default
Player::Player() {
    name = "Undefined";
    hp = 0;
    score = 0;
    numberOfPlayers++;
}

// Player Constructor, parameterized
Player::Player(std::string name, int n) {
    this->name = name;
    hp = 2 * n;
    score = 0;
    numberOfPlayers++;
}

// Player Copy Constructor
Player::Player(const Player &rhs) {
    this->name = rhs.name;
    this->hp = rhs.hp;
    this->score = rhs.score;
    numberOfPlayers++;

    for (Element *element: rhs.logElement) {
        this->logElement.push_back(element->clone());
    }
}

// Player Assignment Operator
Player &Player::operator=(const Player &rhs) {
    if (this == &rhs) {
        return *this;
    }

    this->name = rhs.name;
    this->hp = rhs.hp;
    this->score = rhs.score;
    numberOfPlayers++;

    for (Element *element: this->logElement) {
        delete element;
        logElement.pop_back();
    }

    for (Element *element: rhs.logElement) {
        this->logElement.push_back(element->clone());
    }

    return *this;
}

// Player Destructor
Player::~Player() {
    for (Element *element: logElement) {
        delete element;
        logElement.pop_back();
    }
    numberOfPlayers--;
}

// Visit an Element in the given Grid
void Player::visitElement(Grid &grid) {
    // if the gold is finished, each player should die
    if (grid.goldFinish()) {
        hp = 0;
        return;
    }

    // get a valid coordinate that is not still visited in the Grid
    bool isVisited = true;
    int x, y;
    while (isVisited) {
        char ch;
        std::cout << "Where do you want to visit, " << this->name << "? (x,y):";
        std::cin >> ch >> x >> ch >> y >> ch;
        // check if it is out of boundaries for safety
        if(0<=x && x<grid.getN() && 0<=y && y<grid.getN()) {
            isVisited = grid.isCellVisited(x, y);
        }
    }

    this->logElement.push_back(grid.newElementOfXY(x, y));
    grid.setCellVisited(x, y);
    this->hp += grid.getCellHpEffect(x, y);

    if (grid.isCellGold(x, y)) { // found element is Gold
        this->score += 100;
        grid.decreseGold();
        std::cout << "YOU FOUND GOLD!! I hope you'll win the game hehe~~" << std::endl;
        std::cout << "Your score is increased to " << this->score << "!" << std::endl;
    } else if (grid.isCellWild(x, y)) { // found element is a Wild Animal
        std::cout << "You encountered a WILD " << grid.getCellName(x, y) << "!!!" << std::endl;
        bool escape = this->diceRoll();
        if (escape) {
            this->hp -= grid.getCellHpEffect(x, y);
            std::cout << "You escaped from the wild " << grid.getCellName(x, y) << "!!!" << std::endl;
        } else {
            std::cout << "YOU HAVE EATEN BY THE " << grid.getCellName(x, y) <<
                    ", but somehow managed to escape.. You lost "
                    << grid.getCellHpEffect(x, y) << " HP." << std::endl;
        }
    } else if (grid.isCellEmpty(x, y)) { // found element is Empty
        std::cout << "This cell is EMPTYYY HAHAHHAHHA!!! You wasted your turn :))" << std::endl;
    } else { // found one of the Other Elements
        std::cout << "You found a " << grid.getCellName(x, y) << "." << std::endl;
    }

    // check if it is the time for Gold Bonus
    if (goldBonus()) {
        hp += grid.getN() / 4;
        std::cout << "You gained " << grid.getN() / 4 << " HP since you found 3 golds! You stay positive please.." <<
                std::endl;
    }

    // check if it is the time for Wood Bonus
    if (woodBonus()) {
        hp += grid.getN() / 8;
        std::cout << "You gained " << grid.getN() / 8 << " HP since you found 2 woods! You stayed warm!!" << std::endl;
    }

    // print attributes of the Player
    std::cout << this->name << "'s Score: " << this->score << std::endl;
    std::cout << this->name << "'s HP   : " << this->hp << std::endl;
}

// Check if it is the time for Gold bonus
bool Player::goldBonus() {
    // check how many Gold is there in logElement
    int goldnumber = 0;
    for (Element *element: logElement) {
        if (element->isGold()) {
            goldnumber++;
        }
    }

    //if:
    //  goldNumber is not 0 and,
    //  goldNumber is a coefficient of 3 and,
    //  the last found Element is Gold
    //then: Gold Bonus!
    if (goldnumber != 0 && !(goldnumber % 3) && logElement[logElement.size() - 1]->isGold()) {
        return true;
    }
    return false;
}

// Check if it is the time for Wood bonus
bool Player::woodBonus() {
    // check how many Wood is there in logElement
    int woodNumber = 0;
    for (Element *element: logElement) {
        if (element->isWood()) {
            woodNumber++;
        }
    }

    //if:
    //  woodNumber is not 0 and,
    //  woodNumber is a coefficient of 2 and,
    //  the last found Element is Wood
    //then: Wood Bonus!
    if (woodNumber != 0 && !(woodNumber % 2) && logElement[logElement.size() - 1]->isWood()) {
        return true;
    }
    return false;
}

// Check if the Player is dead
bool Player::playerDead() const {
    return hp <= 0;
}

// Random Number Generator
int Player::PlayerRNG(const int min, const int max) {
    if ((min < 0) || (max < 0) || (max < min)) {
        return -1;
    }

    return (rand() % (max - min + 1)) + min;
}

// Throw a dice, get an input (odd | even)
bool Player::diceRoll() {
    int option, randnum = PlayerRNG(1, 6);
    std::cout << "A dice will be thrown, choose if it'll be EVEN (0) or ODD (1) :";
    std::cin >> option;

    std::cout << "Dice roll: " << randnum << std::endl;
    return (option == (randnum % 2)) ? true : false;
}

// Get Player's score
int Player::getScore() const {
    return this->score;
}

// Get Player's name
std::string Player::getPlayerName() {
    return this->name;
}
