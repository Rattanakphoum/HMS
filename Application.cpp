#include <iostream>
#include <fstream>
#include <iomanip>
#include "RoomApp.cpp"
#include "CustomerApp.cpp"
#include "DataValidInput.cpp"
#include "Display.cpp"
using namespace std;

class Application{
private:
    enum MainMenu { Room = 1,EXIT = 3, Customer = 2};  
    int choice;

public:
void run() { 
    do{     
        displayMain();  
        choice = DataValidInput::getIntInput(">>> ");
        // Switch statement to handle the user's choice
        switch(choice){
        case Room: {
            // Run the RoomApplication
            RoomApp RoomApp;
            RoomApp.run();
            break;
            }
        case Customer: {
            // Run the StaffApplication
            CustomerApp CustomerApp;
            CustomerApp.run();
            cout << "Customer Management"<<endl;
            break;
            }
        case EXIT: {
            // Exit the program
            cout << "Exit Program"<<endl;
            break;
            }
        default :{
            // Invalid input
            cout<<"Invalid input"<<endl;
            cout<<"\a"
                <<"Please enter a valid choice.";
            break;
            }
        }
    }while (choice!=EXIT);

 }

};
