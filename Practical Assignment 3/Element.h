///*** Serkan Ertas ***///

#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>

class Element {
protected:
    bool isVisited;
    int size;

public:
    // Element Constructor
    Element();

    // Get Element's size
    virtual int getSize() const;

    // Get if the Element is visited or not
    bool getIsVisited() const;

    // Make the Element visited
    void setVisited();

    // Create an Element in HEAP
    // Then return its pointer
    virtual Element *clone() const = 0;

    // Get <char> representation of the Elements
    virtual char getRepresentation() const = 0;

    // Get the name of the Element
    virtual std::string getName() const = 0;

    // Get HP Effect of Element
    virtual int getHpEffect(int) const = 0;


    //** THOSE is<subclass_name> functions return false by default
    //** Subclasses make the return value <true> in their class only

    // Is the Element Food
    virtual bool isFood() const;

    // Is the Element Wood
    virtual bool isWood() const;

    // Is the Element Medical Supply
    virtual bool isMedSup() const;

    // Is the Element Empty
    virtual bool isEmpty() const;

    // Is the Element Gold
    virtual bool isGold() const;

    // Is the Element a Wild Animal
    virtual bool isWild() const;
};

#endif ELEMENT_H
