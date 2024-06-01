///*** Serkan Ertas ***///

#include "Classroom.h"

#include <iostream>

// Constructor
Classroom::Classroom(): Room() {
    Capacity = -1;
}

// Custom Constructor
Classroom::Classroom(const char *name, int floorNo, int Capacity): Room(name, floorNo) {
    this->Capacity = Capacity;
}

// Getters
int Classroom::getCapacity() const {
    return Capacity;
}

// Setters
void Classroom::setCapacity(int capacity) {
    Capacity = capacity;
}

// checkSuitability function
bool Classroom::checkSuitability(int studentNumber) const {
    return !(studentNumber > Capacity);
}

// printRoom function
void Classroom::printRoom() const {
    std::cout << "Classroom name = " << room << std::endl;
    std::cout << "Classroom floor number = " << floorNo << std::endl;
    std::cout << "Classroom capacity = " << Capacity << std::endl;
}

// Helpers

// To check if it is classroom or another subclass
char Classroom::getType() const {
    return 'c';
}

// Availability based on capacity
bool Classroom::isAvailable(int studentNumber) const {
    return checkSuitability(studentNumber);
}
