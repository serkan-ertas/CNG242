///*** Serkan Ertas ***///

#include "Grid.h"
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

#include "elementsubclasses.h"

// Grid Constructor, parameterized
Grid::Grid(const int n) {
    this->n = n;
    grid.resize(n);

    goldNumber = 0;

    for (int i = 0; i < n; ++i) {
        grid[i].resize(n);

        for (int j = 0; j < n; ++j) {
            grid[i][j] = new Empty();
        }
    }
}

// Grid Copy Constructor
Grid::Grid(const Grid &rhs) {
    this->n = rhs.n;
    grid.resize(rhs.n);
    this->goldNumber = rhs.goldNumber;

    for (int i = 0; i < n; i++) {
        grid[i].resize(rhs.n);

        for (int j = 0; j < n; j++) {
            grid[i][j] = rhs.grid[i][j]->clone();
        }
    }
}

// Grid Assignment Operator
Grid &Grid::operator=(const Grid &rhs) {
    if (this == &rhs) {
        return *this;
    }

    for (std::vector<Element *> &row: grid) {
        for (Element * &elementPointer: row) {
            delete elementPointer;
            elementPointer = nullptr;
        }
    }

    this->n = rhs.n;
    grid.resize(rhs.n);
    this->goldNumber = rhs.goldNumber;

    for (int i = 0; i < n; i++) {
        grid[i].resize(rhs.n);

        for (int j = 0; j < n; j++) {
            grid[i][j] = rhs.grid[i][j]->clone();
        }
    }

    return *this;
}

// Grid Destructor
Grid::~Grid() {
    for (std::vector<Element *> &row: grid) {
        for (Element * &elementPointer: row) {
            delete elementPointer;
            elementPointer = nullptr;
        }
    }
}

// to check if vertical positioning possible
// float size for ceil function to work properly
bool Grid::isSuitableVertical(const int x, const float size) const {
    int lowerbound = x - std::ceil((size - 1) / 2);
    int upperbound = x + std::ceil((size - 1) / 2);

    if (lowerbound < 0) {
        return false;
    }
    if (upperbound + 1 > n) {
        return false;
    }

    return true;
}

// to check if horizontal positioning possible
// float size for ceil function to work properly
bool Grid::isSuitableHorizontal(const int y, const float size) const {
    int lowerbound = y - std::ceil((size - 1) / 2);
    int upperbound = y + std::ceil((size - 1) / 2);

    if (lowerbound < 0) {
        return false;
    }
    if (upperbound + 1 > n) {
        return false;
    }

    return true;
}

// to check if main diagonal positioning possible
// float size for ceil function to work properly
bool Grid::isSuitableMainDiagonal(const int x, const int y, const float size) const {
    int leftUpperX = x - std::ceil((size - 1) / 2);
    int leftUpperY = y - std::ceil((size - 1) / 2);

    int rightLowerX = x + std::ceil((size - 1) / 2);
    int rightLowerY = y + std::ceil((size - 1) / 2);

    if (leftUpperX < 0 || leftUpperY < 0) {
        return false;
    }
    if (rightLowerX + 1 > n || rightLowerY + 1 > n) {
        return false;
    }

    return true;
}

// to check if anti diagonal positioning possible
// float size for ceil function to work properly
bool Grid::isSuitableAntiDiagonal(const int x, const int y, const float size) const {
    int leftLowerX = x + std::ceil((size - 1) / 2);
    int leftLowerY = y - std::ceil((size - 1) / 2);

    int rightUpperX = x - std::ceil((size - 1) / 2);
    int rightUpperY = y + std::ceil((size - 1) / 2);

    if (leftLowerX + 1 > n || leftLowerY < 0) {
        return false;
    }
    if (rightUpperX < 0 || rightUpperY + 1 > n) {
        return false;
    }

    return true;
}

// Vertical Check: if possible cells are Empty
bool Grid::isEmptyVertical(const int x, const int y, const float size) const {
    int offset = std::ceil((size - 1) / 2);

    for (int i = 0; i < offset + 1; i++) {
        if (!grid[x - i][y]->isEmpty()) {
            return false;
        }
        if (!grid[x + i][y]->isEmpty()) {
            return false;
        }
    }

    return true;
}

// Horizontal Check: if possible cells are Empty
bool Grid::isEmptyHorizontal(const int x, const int y, const float size) const {
    int offset = std::ceil((size - 1) / 2);

    for (int i = 0; i < offset + 1; i++) {
        if (!grid[x][y - i]->isEmpty()) {
            return false;
        }
        if (!grid[x][y + i]->isEmpty()) {
            return false;
        }
    }

    return true;
}

// Main Diagonal Check: if possible cells are Empty
bool Grid::isEmptyMainDiagonal(const int x, const int y, const float size) const {
    int offset = std::ceil((size - 1) / 2);

    for (int i = 0; i < offset + 1; i++) {
        if (!grid[x - i][y - i]->isEmpty()) {
            return false;
        }
        if (!grid[x + i][y + i]->isEmpty()) {
            return false;
        }
    }

    return true;
}

// Anti Diagonal Check: if possible cells are Empty
bool Grid::isEmptyAntiDiagonal(const int x, const int y, const float size) const {
    int offset = std::ceil((size - 1) / 2);

    for (int i = 0; i < offset + 1; i++) {
        if (!grid[x - i][y + i]->isEmpty()) {
            return false;
        }
        if (!grid[x + i][y - i]->isEmpty()) {
            return false;
        }
    }

    return true;
}

// fullorhalf --> true for 2xfloor(n*n/25)
//                false  for   floor(n*n/25)
void Grid::deploy_elements(Element *element, bool fullorhalf) {
    int numberOfElement = floor(n * n / 25) * 2;

    if (fullorhalf) {
        // <numberOfElement> times
        for (int i = 0; i < numberOfElement; i++) {
            deploy_element(element, element->getSize());
        }
    } else {
        // < numberOfElement / 2 > times
        for (int i = 0; i < numberOfElement / 2; i++) {
            deploy_element(element, element->getSize());
        }
    }
}

// Check if the Gold is finished
bool Grid::goldFinish() const {
    return !goldNumber;
}

// Decrement Gold Number by 1 when found
void Grid::decreseGold() {
    goldNumber--;
}

// Deploy an Element to the Grid
void Grid::deploy_element(Element *element, float size) {
    int x, y;

    if (element->isGold()) {
        goldNumber += int(size);
    }

    // when found a place for Element, check = 0
    int check = 1;

    // 0 = horizontal       // 1 = vertical
    // 2 = main diagonal    // 3 = anti diagonal
    int positioning;

    // calculate the length from the middle
    int lengthFromMid = std::ceil((size - 1) / 2);
    if (size < 0 || int(size) > n) {
        return;
    }

    // iterate until finding a position for the Element
    while (check) {
        // random coordinates
        x = GridRNG(0, n - 1);
        y = GridRNG(0, n - 1);

        // random positioning
        positioning = GridRNG(0, 3);

        if (positioning == 0) {
            // HORIZONTAL CASE
            if (isSuitableHorizontal(y, size)) {
                // HORIZONTAL SUITABLE BOUNDARY
                if (isEmptyHorizontal(x, y, size)) {
                    // HORIZONTAL EMPTY ELEMENTS

                    check = 0; // found a place

                    // delete Empty elements, put new Element
                    for (int i = 0; i < lengthFromMid + 1; i++) {
                        deleteElementPutElement(element, x, y - i);
                        deleteElementPutElement(element, x, y + i);
                    }
                    // if size is even, it puts one more Element there,
                    // so delete it, put Empty again
                    if (isEven(int(size))) {
                        deleteElementPutEmpty(x, y - lengthFromMid);
                    }
                }
            }
        } else if (positioning == 1) {
            // VERTICAL CASE
            if (isSuitableVertical(x, size)) {
                // VERTICAL SUITABLE BOUNDARY
                if (isEmptyVertical(x, y, size)) {
                    // VERTICAL EMPTY ELEMENTS

                    check = 0; // found a place

                    // delete Empty elements, put new Element
                    for (int i = 0; i < lengthFromMid + 1; i++) {
                        deleteElementPutElement(element, x - i, y);
                        deleteElementPutElement(element, x + i, y);
                    }

                    // if size is even, it puts one more Element there,
                    // so delete it, put Empty again
                    if (isEven(int(size))) {
                        deleteElementPutEmpty(x - lengthFromMid, y);
                    }
                }
            }
        } else if (positioning == 2) {
            // MAIN DIAGONAL CASE
            if (isSuitableMainDiagonal(x, y, size)) {
                // MAIN DIAGONAL SUITABLE BOUNDARY
                if (isEmptyMainDiagonal(x, y, size)) {
                    // MAIN DIAGONAL EMPTY ELEMENTS

                    check = 0; // found a place

                    // delete Empty elements, put new Element
                    for (int i = 0; i < lengthFromMid + 1; i++) {
                        deleteElementPutElement(element, x - i, y - i);
                        deleteElementPutElement(element, x + i, y + i);
                    }

                    // if size is even, it puts one more Element there,
                    // so delete it, put Empty again
                    if (isEven(int(size))) {
                        deleteElementPutEmpty(x - lengthFromMid, y - lengthFromMid);
                    }
                }
            }
        } else if (positioning == 3) {
            // ANTI DIAGONAL CASE
            if (isSuitableAntiDiagonal(x, y, size)) {
                // ANTI DIAGONAL SUITABLE BOUNDARY
                if (isEmptyAntiDiagonal(x, y, size)) {
                    // ANTI DIAGONAL EMPTY ELEMENTS

                    check = 0; // found a place

                    // delete Empty elements, put new Element
                    for (int i = 0; i < lengthFromMid + 1; i++) {
                        deleteElementPutElement(element, x-i, y+i);
                        deleteElementPutElement(element,x+i, y-i);
                    }
                    if (isEven(int(size))) {
                        deleteElementPutEmpty(x+lengthFromMid, y-lengthFromMid);
                    }
                }
            }
        }
    }
}

// Print the Grid
void Grid::printGrid() const {
    std::cout << "   ";
    for (int k = 0; k < n; k++) {
        std::cout << k << " ";
        if(k<10) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;


    for (int i = 0; i < n; i++) {
        std::cout << i << " |";
        for (int j = 0; j < n; j++) {
            std::cout << grid[i][j]->getRepresentation() << " |";
        }
        std::cout << std::endl;
        std::cout << "   ";
        for (int k = 0; k < n; k++) {
            std::cout << "---";
        }
        std::cout << std::endl;
    }
    std::cout << "Number of Golds Left: " << goldNumber << std::endl;
}


// Random Number Generator
int Grid::GridRNG(const int min, const int max) {
    if (min < 0 || max < 0 || max < min) {
        return -1;
    }
    return (rand() % (max - min + 1)) + min;
}

// Check if (x,y) Element is visited or not
bool Grid::isCellVisited(int x, int y) const {
    return grid[x][y]->getIsVisited();
}

// Make (x,y) Element visited
void Grid::setCellVisited(int x, int y) const {
    grid[x][y]->setVisited();
}

// Get the name of (x,y) Element
std::string Grid::getCellName(int x, int y) const {
    return grid[x][y]->getName();
}

// Get the HP Effect of (x,y) Element
int Grid::getCellHpEffect(int x, int y) const {
    return grid[x][y]->getHpEffect(this->n);
}

// Check if (x,y) is Food or not
bool Grid::isCellFood(int x, int y) const {
    return grid[x][y]->isFood();
}

// Check if (x,y) is Wood or not
bool Grid::isCellWood(int x, int y) const {
    return grid[x][y]->isWood();
}

// Check if (x,y) is Medical Supply or not
bool Grid::isCellMedSup(int x, int y) const {
    return grid[x][y]->isMedSup();
}

// Check if (x,y) is Empty or not
bool Grid::isCellEmpty(int x, int y) const {
    return grid[x][y]->isEmpty();
}

// Check if (x,y) is Gold or not
bool Grid::isCellGold(int x, int y) const {
    return grid[x][y]->isGold();
}

// Check if (x,y) is a Wild Animal or not
bool Grid::isCellWild(int x, int y) const {
    return grid[x][y]->isWild();
}

// Get N
int Grid::getN() const {
    return this->n;
}

// HEAP HERE : Be Cautious
// When called, create an Element same with (x,y) Element
// Then return its pointer
Element *Grid::newElementOfXY(int x, int y) {
    return grid[x][y]->clone();
}

// Delete (x,y), put Empty to (x,y)
void Grid::deleteElementPutEmpty(int x, int y) {
    delete grid[x][y];
    grid[x][y] = new Empty();
}

// Delete (x,y) put the input Element to (x,y)
void Grid::deleteElementPutElement(Element *element, int x, int y) {
    delete grid[x][y];
    grid[x][y] = element->clone();
}

// Check if it is even
bool Grid::isEven(int x) {
    return !(x % 2);
}
