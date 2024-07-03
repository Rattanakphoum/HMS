#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "RoomManager.cpp"
#include "DataValidInput.cpp"
#include "Room.cpp"

class RoomApp {
private:
    // Declare private attributes
    RoomManager manager;
public:
    // Declare public methods
    void run(){

        int choice;
        bool done = false;
        do {
            // Display the Room management options
         displayRoomManagement();
            // Get the user's choice
            choice = DataValidInput::getIntInput(">>> ");
            try {
                // Based on the user's choice, perform the corresponding action
                switch (choice)
                {
                case 1: {
                    // Input the Room details
                    int id;
                    std::string name;
                    int Date;
                    int type;
                    id = DataValidInput::getIntInput("Enter ID: ");
                    name = DataValidInput::getStringInput("Enter Name: ");
                    Date = DataValidInput::getIntInput("Enter Date checkin: ");
                    type = DataValidInput::getIntInput("Enter 1 for SmallRoom singel bed, 2 for BigRoom Double Bed: ");
                    // Validate the Room type
                    if (type != 1 && type != 2) {
                        throw std::invalid_argument(" Invalid Room Type!");
                    }
                    // Add the Room to the inventory
                    manager.addRoom(id, name,Date, type);
                    break;
                }
                case 2: {
                    // Input the Room ID
                    int id;
                    id = DataValidInput::getIntInput("Enter ID: ");
                    // Validate the ID
                    DataValidInput::validateId(id);

                    // Update the Room details
                    manager.updateRoom(id);
                    break;
                }
                case 3:
                    // View the Room details
                    manager.viewRoom();
                    break;
                    
                case 4: {
                    // Input the Room ID
                    int id;
                    id = DataValidInput::getIntInput("Enter ID: ");
                    // Validate the ID
                    DataValidInput::validateId(id);
                    // Delete the Room
                    manager.deleteRoom(id);
                    break;
                }
                case 5:
                    // Exit the program
                    done = true;
                    break;
                default:
                    // Invalid choice
                    std::cout << "Invalide choice. Please try again.\n";
                }
            } catch (const std::exception& e) {
                // Print the error message
                std::cout << "Error!" << e.what() << std::endl;
            }
        } while (choice != 5);
    }
};