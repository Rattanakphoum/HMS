#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "CustomerManager.cpp"
#include "DataValidInput.cpp"

class CustomerApp {
private:
   

public:
    void run() {
        CustomerManager manager;
        int choice;
        bool done = false;
        while (!done) {
            displayCustomerManagement();
            choice = DataValidInput::getIntInput("Enter your choice: ");
            try {
                switch (choice)
                {
                case 1: {
                    int id;
                    std::string name;
                    int type;
                    id = DataValidInput::getIntInput("Enter Customer ID: ");
                    name = DataValidInput::getStringInput("Enter Customer Name:");
                    DataValidInput::validateId(id);
                    type = DataValidInput::getIntInput("Enter 1 for New Customer, 2 for Old Customer :");
                    if (type != 1 && type != 2) {
                        throw std::invalid_argument("Invalid Product Type!");
                    }
                    manager.addCustomer(id,name,type);
                    break;
                }
                case 2: {
                    int id;
                    id = DataValidInput::getIntInput("Enter Customer ID:");
                    DataValidInput::validateId(id);

                    manager.updateCustomer(id);
                    break;
                }
                case 3:
                    manager.viewCustomer();
                    break;
                case 4: {
                    int id;
                    id = DataValidInput::getIntInput("Enter Customer ID: ");
                    DataValidInput::validateId(id);
                    manager.deleteCustomer(id);
                    break;
                }
                case 5:
                    done = true;
                    break;
                default:
                    std::cout << "Invalide choice. Please try again.\n";
                }
            } catch (const std::exception& e) {
                std::cout << "Error!" << e.what() << std::endl;
            }
        }
    }
};

