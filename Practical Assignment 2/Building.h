///*** Serkan Ertas ***///

#ifndef BUILDING_H
#define BUILDING_H

#include "Room.h"

class Building {
private:
    char *name;
    int size;
    Room *RoomList[100];
    int roomNumber;

    // Helper variables
    int classNumber;
    int officeNumber;
    int capacityNumber;
    int officeCapacity;

public:
    Building();

    Building(const char *, int);

    Building(const Building &);

    Building &operator=(const Building &);

    ~Building();

    const char *getName() const;

    int getSize() const;

    int getRoomNumber() const;

    void setName(const char *);

    void setSize(int);

    void addRoom();

    void printBuilding() const;

    void printRooms() const;

    void printRoomsByType(int) const;

    void printOffices() const;

    void printClassrooms() const;

    int getNumberOfClassrooms() const;

    int getTotalCapacity() const;

    int getNumberOfOffices() const;

    void printAvailableOffices() const;

    void printSuitableClassrooms(int) const;

    int getOfficeCapacity() const;
};


#endif //BUILDING_H
