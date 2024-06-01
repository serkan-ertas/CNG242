///*** Serkan Ertas ***///

#include "wildanimals.h"

// CONSTRUCTORS
Wolf::Wolf() {
    size = 1;
}

Bear::Bear() {
    size = 3;
}

// getRepresentation
char Wolf::getRepresentation() const {
    return isVisited ? 'W' : ' ';
}

char Bear::getRepresentation() const {
    return isVisited ? 'B' : ' ';
}

// getName
std::string Wolf::getName() const {
    return "Wolf";
}

std::string Bear::getName() const {
    return "Bear";
}

// CLONE
Wolf *Wolf::clone() const {
    return new Wolf(*this);
}

Bear *Bear::clone() const {
    return new Bear(*this);
}

// getHpEffect
int Wolf::getHpEffect(int n) const {
    return -n / 4;
}

int Bear::getHpEffect(int n) const {
    return -n / 2;
}
