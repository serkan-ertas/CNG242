///*** Serkan Ertas ***///

#include <iostream>
#include "University.h"

// CLI main function
void UniversityCampusManagementSystem();

// Want option and return
int takeOption();

int main() {
    UniversityCampusManagementSystem();
    return 0;
}

void UniversityCampusManagementSystem() {
    University university("METU NCC");
    int option = takeOption();

    // main while loop
    while (option) {
        if (option == 1) {
            // Add a new building to the university
            university.addBuilding();
        } else if (option == 2) {
            // Add a new room to a selected building
            int buildingNumber;
            university.printBuildings();
            std::cout << "Please enter the number of building to which the room should be added:";
            std::cin >> buildingNumber;
            university.addRoomToBuilding(buildingNumber - 1);
        } else if (option == 3) {
            // Print the buildings in the university
            university.printBuildings();
        } else if (option == 4) {
            // Print the rooms in each building in the university
            university.printRooms();
        } else if (option == 5) {
            // Print the rooms in each building in the university based on type
            university.printRoomsByType();
        } else if (option == 6) {
            // Print the total number of classrooms and offices in the university
            university.printRoomTypeStatistics();
        } else if (option == 7) {
            // Print the available offices in each building in the university
            university.printAvailableOffices();
        } else if (option == 8) {
            // Print the total capacity of all the offices
            university.printTotalCapacityOfOffices();
        } else if (option == 9) {
            // Print the suitable classrooms in the university
            // based on the given number of students
            int student;
            std::cout << "Please enter number of students:";
            std::cin >> student;
            university.printSuitableClassrooms(student);
        } else if (option < 0 || option > 9) {
            // Invalid Option
            std::cout << "Invalid option!" << std::endl;
        }
        std::cout << std::endl;
        option = takeOption();
    }
    std::cout << "Thank you for using the university campus management system";
}

int takeOption() {
    int option;
    std::cout << "[1] Add a new building to the university" << std::endl;
    std::cout << "[2] Add a new room to a selected building" << std::endl;
    std::cout << "[3] Print the buildings in the university" << std::endl;
    std::cout << "[4] Print the rooms in each building in the university" << std::endl;
    std::cout << "[5] Print the rooms in each building in the university based on type" << std::endl;
    std::cout << "[6] Print the total number of classrooms and offices in the university" << std::endl;
    std::cout << "[7] Print the available offices in each building in the university" << std::endl;
    std::cout << "[8] Print the total capacity of all the offices" << std::endl;
    std::cout << "[9] Print the suitable classrooms in the university based on the given number of students" <<
            std::endl;
    std::cout << "[0] Exit" << std::endl;
    std::cout << "Please enter your choice:";
    std::cin >> option;
    return option;
}
