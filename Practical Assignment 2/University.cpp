///*** Serkan Ertas ***///

/********************************************************
 I think it would be better if University-Building
 is aggregate, but implemented it as composite since
 aggregation can lead to some grade loss because of
 the possible memory leaks.
********************************************************/

/*****************************************************************************************
In some functions, you may see this format:                             // Just for identation purposes!

for(..;i < buildingNumber-1;..){
    ..
    std::cout << std::endl;
}
if(buildingNumber>0){                                                   // This part is for safety!
    if(BuildingList[buildingNumber-1]){                                 // This part is for safety!
        same function used in for loop, but with buildingNumber-1       // No new lines here!
    }
}
*****************************************************************************************/

#include "University.h"

#include <iostream>
#include <cstring>

// Constructor
University::University() {
    name = new char[50];
    strcpy(name, "Undefined");

    // For safety
    for (int i = 0; i < 20; i++) {
        BuildingList[i] = nullptr;
    }

    buildingNumber = 0;
}

// Custom Constructor
University::University(const char *cName) {
    name = new char[50];
    strcpy(name, cName);

    // For safety
    for (int i = 0; i < 20; i++) {
        BuildingList[i] = nullptr;
    }

    buildingNumber = 0;
}

// Copy Constructor
University::University(const University &rhs) {
    name = new char[50];
    strcpy(name, rhs.name);

    // Assign new buildings same with rhs buildings
    for (int i = 0; i < rhs.buildingNumber; i++) {
        BuildingList[i] = new Building();
        *BuildingList[i] = *rhs.BuildingList[i]; // Building class's operator= called here
    }
    // For safety
    for (int i = rhs.buildingNumber; i < 20; i++) {
        BuildingList[i] = nullptr;
    }

    buildingNumber = rhs.buildingNumber;
}

// Assignment Operator
University &University::operator=(const University &rhs) {
    if (this == &rhs) {
        return *this;
    }

    delete [] name;

    // Delete old buildings one by one
    for (int i = 0; i < buildingNumber; i++) {
        delete BuildingList[i];
    }

    name = new char[50];
    strcpy(name, rhs.name);

    // Assign new buildings same with rhs buildings
    for (int i = 0; i < rhs.buildingNumber; i++) {
        BuildingList[i] = new Building();
        *BuildingList[i] = *rhs.BuildingList[i];
    }
    // For safety
    for (int i = rhs.buildingNumber; i < 20; i++) {
        BuildingList[i] = nullptr;
    }

    buildingNumber = rhs.buildingNumber;

    return *this;
}

// Destructor
// Important note on top
University::~University() {
    delete [] name;
    name = nullptr;

    for (int i = 0 ; i < buildingNumber ; i++) {
        delete BuildingList[i];
        BuildingList[i] = nullptr;
    }
}

// Getters
char *University::getName() const {
    return name;
}

int University::getBuildingNumber() const {
    return buildingNumber;
}

// Setters
void University::setName(const char *Name) {
    delete [] name;
    name = new char[50];
    strcpy(name, Name);
}

// addBuilding function
void University::addBuilding() {
    if (buildingNumber >= 20) {
        std::cout << "Not enough space for adding building to the university." << std::endl;
        return;
    }

    char buildingName[50];
    int buildingSize;

    std::cout << "Please enter name of building:";
    std::cin >> buildingName;

    std::cout << "Please enter size of building:";
    std::cin >> buildingSize;

    BuildingList[buildingNumber] = new Building(buildingName, buildingSize);
    buildingNumber++;
}

// Printers
void University::printBuildings() const {
    std::cout << "Buildings in " << name << " university:" << std::endl;
    for (int i = 0; i < buildingNumber - 1; i++) {
        std::cout << "[" << i + 1 << "] ";
        BuildingList[i]->printBuilding();
        std::cout << std::endl;
    }
    if (buildingNumber > 0) {
        if (BuildingList[buildingNumber - 1]) {
            std::cout << "[" << buildingNumber << "] ";
            BuildingList[buildingNumber - 1]->printBuilding();
        }
    }
}

void University::printRooms() const {
    std::cout << "Rooms in " << name << " university:" << std::endl;
    for (int i = 0; i < buildingNumber - 1; i++) {
        BuildingList[i]->printRooms();
        std::cout << std::endl;
    }
    if (buildingNumber > 0) {
        if (BuildingList[buildingNumber - 1]) {
            BuildingList[buildingNumber - 1]->printRooms();
        }
    }
}

void University::printRoomsByType() const {
    int option;
    std::cout << "[1] Classrooms" << std::endl;
    std::cout << "[2] Offices" << std::endl;
    std::cout << "Please enter type of room to display:";
    std::cin >> option;

    if (option == 1) {
        std::cout << "Classrooms in " << name << " university:" << std::endl;

        for (int i = 0; i < buildingNumber - 1; i++) {
            BuildingList[i]->printClassrooms();
            std::cout << std::endl;
        }
        if (buildingNumber > 0) {
            BuildingList[buildingNumber - 1]->printClassrooms();
        }
    } else if (option == 2) {
        std::cout << "Offices in " << name << " university: " << std::endl;
        for (int i = 0; i < buildingNumber - 1; i++) {
            BuildingList[i]->printOffices();
            std::cout << std::endl;
        }
        if (buildingNumber > 0) {
            BuildingList[buildingNumber - 1]->printOffices();
        }
    } else {
        std::cout << "Invalid Option!" << std::endl;
    }
}

void University::printRoomTypeStatistics() const {
    int officeNumber = 0, classNumber = 0;
    for (int i = 0; i < buildingNumber; i++) {
        officeNumber += BuildingList[i]->getNumberOfOffices();
        classNumber += BuildingList[i]->getNumberOfClassrooms();
    }
    std::cout << "Room Type statistics for " << name << " university:" << std::endl;
    std::cout << "Number of offices = " << officeNumber << std::endl;
    std::cout << "Number of classrooms = " << classNumber << std::endl;
}

void University::printAvailableOffices() const {
    std::cout << "Available offices in " << name << " university:" << std::endl;
    for (int i = 0; i < buildingNumber; i++) {
        BuildingList[i]->printAvailableOffices();
    }
}

void University::printTotalCapacityOfOffices() const {
    std::cout << "Office capacity in " << name << " university:" << std::endl;
    for (int i = 0; i < buildingNumber; i++) {
        std::cout << "Office capacity in " << BuildingList[i]->getName() << " building = " <<
                BuildingList[i]->getOfficeCapacity() << std::endl;
    }
}

void University::printSuitableClassrooms(int studentNumber) const {
    std::cout << "Suitable classes in " << name << " university for " << studentNumber << " students:" << std::endl;
    for (int i = 0; i < buildingNumber; i++) {
        BuildingList[i]->printSuitableClassrooms(studentNumber);
    }
}

// Helper
void University::addRoomToBuilding(int building) {
    if (building > buildingNumber || building < 0) {
        std::cout << "Invalid building number!" << std::endl;
        return;
    }

    this->BuildingList[building]->addRoom();
}
