///*** Serkan Ertas ***///

#include <iostream>
#include <cstring>

#include "Building.h"
#include "Classroom.h"
#include "Office.h"


/*****************************************************************************************
In some functions, you may see this format:                     // Just for identation purposes!

for(..;i < roomNumber-1;..){
    ..
    std::cout << std::endl;
}
if(roomNumber>0){                                               // This part is for safety!
    if(RoomList[roomNumber-1]){                                 // This part is for safety!
        same function used in for loop with roomNumber-1        // No new lines here!
    }
}
*****************************************************************************************/

// Constructor
Building::Building() {
    name = new char[50];
    strcpy(name, "Undefined");

    size = -1;

    // For safety
    for (int i = 0; i < 100; i++) {
        RoomList[i] == nullptr;
    }

    roomNumber = 0;

    // Helper variables:
    classNumber = 0;
    officeNumber = 0;
    capacityNumber = 0;
    officeCapacity = 0;
}

// Custom Constructor
Building::Building(const char *Name, int Size): size(Size), roomNumber(0) {
    name = new char[50];
    strcpy(name, Name);

    // For safety
    for (int i = 0; i < 100; i++) {
        RoomList[i] = nullptr;
    }

    // Helper variables:
    classNumber = 0;
    officeNumber = 0;
    capacityNumber = 0;
    officeCapacity = 0;
}

// Copy Constructor
Building::Building(const Building &rhs) {
    name = new char[50];
    strcpy(name, rhs.name);

    size = rhs.size;

    // Assign new rooms same with rhs rooms
    for (int i = 0; i < rhs.roomNumber; i++) {
        if (rhs.RoomList[i]->getType() == 'c') {
            RoomList[i] = new Classroom(rhs.RoomList[i]->getRoom(), rhs.RoomList[i]->getFloorNo(),
                                        rhs.RoomList[i]->getCapacity());
        } else if (rhs.RoomList[i]->getType() == 'o') {
            RoomList[i] = new Office(rhs.RoomList[i]->getRoom(), rhs.RoomList[i]->getFloorNo(),
                                     rhs.RoomList[i]->getOffType(), rhs.RoomList[i]->getPeopleNumber());
        }
    }
    // For safety
    for (int i = rhs.roomNumber; i < 100; i++) {
        RoomList[i] = nullptr;
    }

    roomNumber = rhs.roomNumber;

    // Helper variables:
    classNumber = rhs.classNumber;
    officeNumber = rhs.officeNumber;
    capacityNumber = rhs.capacityNumber;
    officeCapacity = rhs.officeCapacity;
}

// Assignment Operator
Building &Building::operator=(const Building &rhs) {
    if (this == &rhs) {
        return *this;
    }

    delete [] name;
    name = new char[50];
    strcpy(name, rhs.name);

    size = rhs.size;

    // Delete old rooms
    for (int i = 0; i < roomNumber; i++) {
        delete RoomList[i];
        RoomList[i] = nullptr;
    }
    // Assign new rooms same with rhs rooms
    for (int i = 0; i < rhs.roomNumber; i++) {
        if (rhs.RoomList[i]->getType() == 'c') {
            RoomList[i] = new Classroom(rhs.RoomList[i]->getRoom(), rhs.RoomList[i]->getFloorNo(),
                                        rhs.RoomList[i]->getCapacity());
        } else if (rhs.RoomList[i]->getType() == 'o') {
            RoomList[i] = new Office(rhs.RoomList[i]->getRoom(), rhs.RoomList[i]->getFloorNo(),
                                     rhs.RoomList[i]->getOffType(), rhs.RoomList[i]->getPeopleNumber());
        }
    }
    // For safety
    for (int i = rhs.roomNumber; i < 100; i++) {
        RoomList[i] = nullptr;
    }

    roomNumber = rhs.roomNumber;

    // Helper variables:
    classNumber = rhs.classNumber;
    officeNumber = rhs.officeNumber;
    capacityNumber = rhs.capacityNumber;
    officeCapacity = rhs.officeCapacity;
    return *this;
}

// Destructor
Building::~Building() {
    delete [] name;
    name = nullptr;

    // Delete every Room one by one
    for (int i = 0; i < roomNumber; i++) {
        delete RoomList[i];
        RoomList[i] = nullptr;
    }
}

// Getters
const char *Building::getName() const {
    return name;
}

int Building::getSize() const {
    return size;
}

int Building::getRoomNumber() const {
    return roomNumber;
}

int Building::getNumberOfClassrooms() const {
    return classNumber;
}

int Building::getTotalCapacity() const {
    return capacityNumber;
}

int Building::getNumberOfOffices() const {
    return officeNumber;
}

int Building::getOfficeCapacity() const {
    return officeCapacity;
}

// Setters
void Building::setName(const char *Name) {
    delete [] name;
    name = new char[50];
    strcpy(name, Name);
}

void Building::setSize(const int Size) {
    size = Size;
}

// addRoom function
void Building::addRoom() {
    if (roomNumber >= 100) {
        std::cout << "Not enough space for adding room to the building!" << std::endl;
        return;
    }

    char roomName[50];
    int roomType, roomFloorNo;
    std::cout << "Please enter the type of room(1: Classroom/ 2: Office):";
    std::cin >> roomType;

    std::cout << "Please enter the name of the new room:";
    std::cin >> roomName;

    std::cout << "Please enter the floor number of the new room:";
    std::cin >> roomFloorNo;

    if (roomType == 1) {
        // Classroom
        int roomCapacity;
        std::cout << "Please enter capacity of classroom:";
        std::cin >> roomCapacity;

        RoomList[roomNumber] = new Classroom(roomName, roomFloorNo, roomCapacity);
        roomNumber++;

        // Helper Variables:
        classNumber++;
        capacityNumber += roomCapacity;
    } else if (roomType == 2) {
        // Office
        int roomOffType;
        std::cout << "[1] Coordinator Office" << std::endl;
        std::cout << "[2] Standard Office" << std::endl;
        std::cout << "[3] Shared Office for 2 people" << std::endl;
        std::cout << "[4] Shared Office for 3 people" << std::endl;
        std::cout << "[5] Shared Office for 10 people" << std::endl;
        std::cout << "Please enter type of office:";
        std::cin >> roomOffType;

        int roomPeopleNumber;
        std::cout << "Please enter number of people in the office:";
        std::cin >> roomPeopleNumber;

        if (roomOffType == 1) {
            // Coordinator Office
            if (roomPeopleNumber > 1) {
                std::cout << "Coordinator Office cannot be more than 1 people!" << std::endl;
            } else {
                RoomList[roomNumber] = new Office(roomName, roomFloorNo, CoordinatorOffice, roomPeopleNumber);
                roomNumber++;

                // Helper Variables:
                officeNumber++;
                capacityNumber++;
                officeCapacity++;
            }
        } else if (roomOffType == 2) {
            // Standard Office
            if (roomPeopleNumber > 1) {
                std::cout << "Standard Office cannot be more than 1 people!" << std::endl;
            } else {
                RoomList[roomNumber] = new Office(roomName, roomFloorNo, StandardOffice, roomPeopleNumber);
                roomNumber++;

                // Helper Variables:
                officeNumber++;
                capacityNumber++;
                officeCapacity++;
            }
        } else if (roomOffType == 3) {
            // SharedOfficeFor2People
            if (roomPeopleNumber > 2) {
                std::cout << "2-People Shared Office cannot be more than 2 people!" << std::endl;
            } else {
                RoomList[roomNumber] = new Office(roomName, roomFloorNo, SharedOfficeFor2People, roomPeopleNumber);
                roomNumber++;

                // Helper Variables:
                officeNumber++;
                capacityNumber += 2;
                officeCapacity += 2;
            }
        } else if (roomOffType == 4) {
            // SharedOfficeFor3People
            if (roomPeopleNumber > 3) {
                std::cout << "3-People Shared Office cannot be more than 3 people!" << std::endl;
            } else {
                RoomList[roomNumber] = new Office(roomName, roomFloorNo, SharedOfficeFor3People, roomPeopleNumber);
                roomNumber++;

                // Helper Variables:
                officeNumber++;
                capacityNumber += 3;
                officeCapacity += 3;
            }
        } else if (roomOffType == 5) {
            // SharedOfficeFor10People
            if (roomPeopleNumber > 10) {
                std::cout << "10-People Shared Office cannot be more than 10 people!" << std::endl;
            } else {
                RoomList[roomNumber] = new Office(roomName, roomFloorNo, SharedOfficeFor10People, roomPeopleNumber);
                roomNumber++;

                // Helper Variables:
                officeNumber++;
                capacityNumber += 10;
                officeCapacity += 10;
            }
        } else {
            std::cout << "Invalid Office Type!" << std::endl;
        }
    }
}

//Printers
void Building::printBuilding() const {
    std::cout << "Building name = " << name << std::endl;
    std::cout << "Building size = " << size << std::endl;
    std::cout << "Building number of rooms = " << roomNumber << std::endl;
}

void Building::printRooms() const {
    std::cout << "All rooms in " << name << " Building:" << std::endl;

    for (int i = 0; i < roomNumber - 1; i++) {
        RoomList[i]->printRoom();
        std::cout << std::endl;
    }
    if (roomNumber > 0) {
        if (RoomList[roomNumber - 1]) {
            RoomList[roomNumber - 1]->printRoom();
        }
    }
}

void Building::printRoomsByType(int option) const {
    if (option == 1) {
        this->printClassrooms();
    } else if (option == 2) {
        this->printOffices();
    } else {
        std::cout << "Invalid Option!" << std::endl;
    }
}

// Helper
void Building::printOffices() const {
    std::cout << "All Offices in " << name << " building:" << std::endl;
    for (int i = 0; i < roomNumber - 1; i++) {
        if (RoomList[i]->getType() == 'o') {
            RoomList[i]->printRoom();
            std::cout << std::endl;
        }
    }
    if (roomNumber > 0) {
        if (RoomList[roomNumber - 1]) {
            if (RoomList[roomNumber - 1]->getType() == 'o') {
                RoomList[roomNumber - 1]->printRoom();
            }
        }
    }
}

void Building::printAvailableOffices() const {
    std::cout << "Available Offices in " << name << " building: " << std::endl;
    for (int i = 0; i < roomNumber - 1; i++) {
        if (RoomList[i]->getType() == 'o' && RoomList[i]->isAvailable()) {
            RoomList[i]->printRoom();
            std::cout << std::endl;
        }
    }
    if (roomNumber > 0) {
        if (RoomList[roomNumber - 1]) {
            if (RoomList[roomNumber - 1]->getType() == 'o' && RoomList[roomNumber - 1]->isAvailable()) {
                RoomList[roomNumber - 1]->printRoom();
            }
        }
    }
}

void Building::printSuitableClassrooms(int studentNumber) const {
    std::cout << "Available Classrooms in " << name << " building:" << std::endl << std::endl;
    for (int i = 0; i < roomNumber - 1; i++) {
        if (RoomList[i]->getType() == 'c' && RoomList[i]->isAvailable(studentNumber)) {
            RoomList[i]->printRoom();
            std::cout << std::endl;
        }
    }
    if (roomNumber > 0) {
        if (RoomList[roomNumber - 1]) {
            if (RoomList[roomNumber - 1]->getType() == 'c' && RoomList[roomNumber - 1]->isAvailable(studentNumber)) {
                RoomList[roomNumber - 1]->printRoom();
            }
        }
    }
}

// Helper
void Building::printClassrooms() const {
    std::cout << "All Classrooms in " << name << " building:" << std::endl;
    for (int i = 0; i < roomNumber - 1; i++) {
        if (RoomList[i]->getType() == 'c') {
            RoomList[i]->printRoom();
            std::cout << std::endl;
        }
    }
    if (roomNumber > 0) {
        if (RoomList[roomNumber - 1]) {
            if (RoomList[roomNumber - 1]->getType() == 'c') {
                RoomList[roomNumber - 1]->printRoom();
            }
        }
    }
}
