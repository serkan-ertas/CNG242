///*** Serkan Ertas ***///

#ifndef GRID_H
#define GRID_H
#include <vector>

#include "Element.h"

class Grid {
private:
    int n;
    std::vector<std::vector<Element *> > grid;
    int goldNumber;

public:
    // Grid Constructor, parameterized
    Grid(int);

    // Grid Copy Constructor
    Grid(const Grid &);

    // Grid Assignment Operator
    Grid &operator=(const Grid &);

    // Grid Destructor
    ~Grid();

    // Get N
    int getN() const;

    // Deploy an Element to the Grid (multiple times)
    void deploy_elements(Element *element, bool fullorhalf);

    // Print the Grid
    void printGrid() const;

    // Check if the Gold is finished
    bool goldFinish() const;

    // Decrement Gold Number by 1 when found
    void decreseGold();

    // Check if (x,y) Element is visited or not
    bool isCellVisited(int, int) const;

    // Make (x,y) Element visited
    void setCellVisited(int, int) const;

    // Get the name of (x,y) Element
    std::string getCellName(int, int) const;

    // Get the HP Effect of (x,y) Element
    int getCellHpEffect(int, int) const;

    // Check if (x,y) is Food or not
    bool isCellFood(int, int) const;

    // Check if (x,y) is Wood or not
    bool isCellWood(int, int) const;

    // Check if (x,y) is Medical Supply or not
    bool isCellMedSup(int, int) const;

    // Check if (x,y) is Empty or not
    bool isCellEmpty(int, int) const;

    // Check if (x,y) is Gold or not
    bool isCellGold(int, int) const;

    // Check if (x,y) is a Wild Animal or not
    bool isCellWild(int, int) const;

    // HEAP HERE : Be Cautious
    // When called, create an Element same with (x,y) Element
    // Then return its pointer
    Element *newElementOfXY(int, int);

private:
    // Delete (x,y), put Empty to (x,y)
    void deleteElementPutEmpty(int, int);

    // Delete (x,y) put the input Element to (x,y)
    void deleteElementPutElement(Element *, int, int);

    // Check if it is even
    static bool isEven(int);

    // Vertical Check: if coordinate and size is suitable
    bool isSuitableVertical(int, float) const;

    // Horizontal Check: if coordinate and size is suitable
    bool isSuitableHorizontal(int, float) const;

    // Main Diagonal Check: if coordinate and size is suitable
    bool isSuitableMainDiagonal(int, int, float) const;

    // Anti Diagonal Check: if coordinate and size is suitable
    bool isSuitableAntiDiagonal(int, int, float) const;

    // Vertical Check: if possible cells are Empty
    bool isEmptyVertical(int, int, float) const;

    // Horizontal Check: if possible cells are Empty
    bool isEmptyHorizontal(int, int, float) const;

    // Main Diagonal Check: if possible cells are Empty
    bool isEmptyMainDiagonal(int, int, float) const;

    // Anti Diagonal Check: if possible cells are Empty
    bool isEmptyAntiDiagonal(int, int, float) const;

    // Deploy an Element to the Grid
    void deploy_element(Element *element, float size);

    // Random Number Generator
    static int GridRNG(int, int);
};


#endif //GRID_H
