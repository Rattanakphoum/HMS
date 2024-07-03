#pragma once
#include <iostream>
#include <iomanip>
#include "Customer.cpp"
using namespace std;

 void displayCustomer()  {
        std::cout << std::left << setw(20) <<"|Type"
                  << std::setw(20) << "ID"
                  << std::setw(15) << "Name" << std::endl;
        std::cout << "------------------------------------------------------------------" <<endl;
};
 void displayRoom() {
        std::cout << std::left << setw(20) <<"|Type"
                  << std::setw(20) << "ID"
                  << std::setw(15) << "Date-CheckIn"
                  << std::setw(15) << "Name"<< endl;
        std::cout << "--------------------------------------------------------------------------------" <<endl;
};

void displayMain(){
    std::cout <<"\n<============== (Hotel Management System) ==============>\n\n"
              <<"1. Room Management\n"
              <<"2. Customer Management\n"
              <<"3. EXIT\n\n";
};
void displayRoomManagement(){
    std::cout <<"\n<============== (Room Management) ==============>\n\n"
              <<"1. Add Room\n"
              <<"2. Update Room\n"
              <<"3. View Room\n"
              <<"4. Delete Room\n"
              <<"5. Return to Main Menu\n\n";
};
void displayCustomerManagement(){
    std::cout <<"\n<============== (Customer Management) ==============>\n\n"
              <<"1. Add Customer\n"
              <<"2. Update Customer\n"
              <<"3. View Customer\n"
              <<"4. Delete Customer\n"
              <<"5. Return to Main Menu\n\n";
};

