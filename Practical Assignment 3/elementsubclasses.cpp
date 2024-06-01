///*** Serkan Ertas ***///

#include "elementsubclasses.h"

#include "Player.h"

// CONSTRUCTORS
Food::Food() {
    size = 1;
}

Wood::Wood() {
    size = 2;
}

MedSup::MedSup() {
    size = 1;
}

Gold::Gold() {
    size = 1;
}

Empty::Empty() {
    size = 1;
}

// getRepresentation
char Food::getRepresentation() const {
    return isVisited ? 'F' : ' ';
}

char Wood::getRepresentation() const {
    return isVisited ? 'I' : ' ';
}

char MedSup::getRepresentation() const {
    return isVisited ? 'S' : ' ';
}

char Gold::getRepresentation() const {
    return isVisited ? 'G' : ' ';
}

char Empty::getRepresentation() const {
    return isVisited ? 'E' : ' ';
}

// getName
std::string Food::getName() const {
    return "Food";
}

std::string Wood::getName() const {
    return "Wood";
}

std::string MedSup::getName() const {
    return "Medical Supply";
}

std::string Gold::getName() const {
    return "Gold";
}

std::string Empty::getName() const {
    return "Empty";
}

// CLONE
Food *Food::clone() const {
    return new Food(*this);
}

Wood *Wood::clone() const {
    return new Wood(*this);
}

MedSup *MedSup::clone() const {
    return new MedSup(*this);
}

Gold *Gold::clone() const {
    return new Gold(*this);
}

Empty *Empty::clone() const {
    return new Empty(*this);
}

// getHpEffect
int Food::getHpEffect(int n) const {
    return n / 6;
}

int Wood::getHpEffect(int n) const {
    return n / 8;
}

int MedSup::getHpEffect(int n) const {
    return n / 4;
}

int Gold::getHpEffect(int n) const {
    return 0;
}

int Empty::getHpEffect(int n) const {
    return 0;
}

// is<subclass_name> functions
bool Food::isFood() const {
    return true;
}

bool Wood::isWood() const {
    return true;
}

bool MedSup::isMedSup() const {
    return true;
}

bool Empty::isEmpty() const {
    return true;
}

bool Gold::isGold() const {
    return true;
}

bool WildAnimal::isWild() const {
    return true;
}
