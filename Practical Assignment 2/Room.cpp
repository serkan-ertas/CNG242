///*** Serkan Ertas ***///

#include "Room.h"
#include <cstring>
#include <iostream>

// Constructor
Room::Room() {
    room = new char[50];
    strcpy(room, "Undefined");
    floorNo = -1;
}

// Custom Constructor
Room::Room(const char *cRoom, int cFloorNo) {
    room = new char[50];
    strcpy(room, cRoom);
    floorNo = cFloorNo;
}

// Copy Constructor
Room::Room(const Room &rhs) {
    this->room = new char[50];
    strcpy(room, rhs.room);

    this->floorNo = rhs.floorNo;
};

// Assignment Operator
Room &Room::operator=(const Room &rhs) {
    if (this == &rhs) {
        return *this;
    }

    delete [] room;
    room = new char[50];
    strcpy(room, rhs.room);

    floorNo = rhs.floorNo;

    return *this;
}

// Destructor
Room::~Room() {
    delete [] room;
}

// Getters
char *Room::getRoom() const {
    return room;
}

int Room::getFloorNo() const {
    return floorNo;
}

int Room::getCapacity() const {
    return 0;
}

officeType Room::getOffType() const {
    return None;
}

int Room::getPeopleNumber() const {
    return 0;
}


char Room::getType() const {
    return 'r';
}

// Setters
void Room::setRoom(const char *otherRoom) {
    delete [] room;
    room = new char[50];
    strcpy(room, otherRoom);
}

void Room::setFloorNo(int otherFloorNo) {
    floorNo = otherFloorNo;
}

// Printers
void Room::printRoom() const {
    std::cout << "Room name: " << room << std::endl;
    std::cout << "Room floor no: " << floorNo << std::endl;
}

// Helpers
bool Room::isAvailable() const {
    return false;
}

bool Room::isAvailable(int temp) const {
    return false;
}
