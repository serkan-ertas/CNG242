///*** Serkan Ertas ***///

/***************************************
 IMPORTANT NOTE IN University.cpp FILE!!
***************************************/

#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Building.h"


class University {
private:
    char *name;
    Building *BuildingList[20];
    int buildingNumber;

public:
    University();

    University(const char *);

    University(const University &);

    University &operator=(const University &);

    ~University();

    char *getName() const;

    void setName(const char *);

    int getBuildingNumber() const;

    void addBuilding();

    void printBuildings() const;

    void printRooms() const;

    void printRoomsByType() const;

    void printRoomTypeStatistics() const;

    void printAvailableOffices() const;

    void printTotalCapacityOfOffices() const;

    void printSuitableClassrooms(int) const;

    void addRoomToBuilding(int);
};


#endif //UNIVERSITY_H
