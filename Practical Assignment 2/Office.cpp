///*** Serkan Ertas ***///

#include "Office.h"

#include <iostream>

// Constructor
Office::Office(): Room() {
    offType = None;
    peopleNumber = 0;
}

// Custom Constructor
Office::Office(const char *cRoom, int cFloorNo, officeType cOffType, int cPeopleNumber): Room(cRoom, cFloorNo) {
    offType = cOffType;
    peopleNumber = cPeopleNumber;
}

// Getters
officeType Office::getOffType() const {
    return offType;
}

int Office::getPeopleNumber() const {
    return peopleNumber;
}

// Setters
void Office::setOffType(officeType otherOffType) {
    offType = otherOffType;
}

void Office::setPeopleNumber(int otherPeopleNumber) {
    peopleNumber = otherPeopleNumber;
}

// isFull function
bool Office::isFull() const {
    // used >= since it will be more solid than ==
    if (offType == None) {
        return true;
    } else if (offType == CoordinatorOffice && peopleNumber >= 1) {
        return true;
    } else if (offType == StandardOffice && peopleNumber >= 1) {
        return true;
    } else if (offType == SharedOfficeFor2People && peopleNumber >= 2) {
        return true;
    } else if (offType == SharedOfficeFor3People && peopleNumber >= 3) {
        return true;
    } else if (offType == SharedOfficeFor10People && peopleNumber >= 10) {
        return true;
    } else {
        return false;
    }
}

// getCapacity function
int Office::getCapacity() const {
    if (offType == None) {
        return 0;
    } else if (offType == CoordinatorOffice) {
        return 1;
    } else if (offType == StandardOffice) {
        return 1;
    } else if (offType == SharedOfficeFor2People) {
        return 2;
    } else if (offType == SharedOfficeFor3People) {
        return 3;
    } else if (offType == SharedOfficeFor10People) {
        return 10;
    } else {
        return 0;
    }
}

// printRoom function
void Office::printRoom() const {
    std::cout << "Office name = " << room << std::endl;
    std::cout << "Office floor number = " << floorNo << std::endl;
    std::cout << "Office type = ";
    this->printOffType();
    std::cout << std::endl;
    std::cout << "Number of people in office = " << peopleNumber << std::endl;
    std::cout << "Office capacity = " << this->getCapacity() << std::endl;

    if (this->isFull()) {
        std::cout << "Office is full" << std::endl;
    } else {
        std::cout << "Office is not full" << std::endl;
    }
}

// Helpers

// To check if it is office or another subclass
char Office::getType() const {
    return 'o';
}

// Availability based on empty spaces in office
bool Office::isAvailable() const {
    return this->getCapacity() > peopleNumber;
}

// To print the officeType of the object
void Office::printOffType() const {
    if (offType == None) {
        std::cout << "None";
    } else if (offType == CoordinatorOffice) {
        std::cout << "Coordinator Office";
    } else if (offType == StandardOffice) {
        std::cout << "Standard office";
    } else if (offType == SharedOfficeFor2People) {
        std::cout << "Shared office for 2 people";
    } else if (offType == SharedOfficeFor3People) {
        std::cout << "Shared office for 3 people";
    } else if (offType == SharedOfficeFor10People) {
        std::cout << "Shared office for 10 people";
    }
}
