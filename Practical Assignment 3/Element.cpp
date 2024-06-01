///*** Serkan Ertas ***///

#include "Element.h"

// Element Constructor
Element::Element() {
    isVisited = false;
}

// Get Element's size
int Element::getSize() const {
    return size;
}

// Get if the Element is visited or not
bool Element::getIsVisited() const {
    return isVisited;
}

// Make the Element visited
void Element::setVisited() {
    this->isVisited = true;
}

//** THOSE is<subclass_name> functions return false by default
//** Subclasses make the return value <true> in their class only

bool Element::isFood() const {
    return false;
}

bool Element::isWood() const {
    return false;
}

bool Element::isMedSup() const {
    return false;
}


bool Element::isEmpty() const {
    return false;
}

bool Element::isGold() const {
    return false;
}

bool Element::isWild() const {
    return false;
}
