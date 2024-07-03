#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Room.cpp"
#include "DataValidInput.cpp"
#include "RoomRepository.cpp"
#include "SmallRoom.cpp"
#include "BigRoom.cpp"
#include "display.cpp"



class RoomManager : public RoomRepository{
private:
    std::vector<Room*> Rooms;

    Room* findRoombyID(int id){
        auto it = std::find_if(Rooms.begin(), Rooms.end(),[id](Room* Rooms){
            return Rooms->getId() == id;
        });
        return (it != Rooms.end()) ? *it : nullptr;
    }
public:
    ~RoomManager(){
        for (auto Room : Rooms) {
            delete Room;
        }
    }
    void addRoom(int id, std::string name,int Date, int type) {
        if (type == 1) {
                    Rooms.push_back(new SmallRoom(id, name,Date, type));
                } else if (type == 2) {
                    Rooms.push_back(new BigRoom(id, name,Date, type));
                } else {
                    throw std::invalid_argument("Invalid Room type.");
                }
    std::cout << "\nAdded Successfully.\n";
    }
    void updateRoom(int id){
        Room* Room = findRoombyID(id);
        if(Room == nullptr){
            throw std::invalid_argument("Room not found\n\n");
            return;
        }
        std::string newName;
        newName = DataValidInput::getStringInput("Enter name: ");

        Room->setName(newName);
        std::cout << "\nUpdated successfully.\n";
    }
    void deleteRoom(int id){
        auto it = std::remove_if(Rooms.begin(), Rooms.end(),[id](Room* Room){
            if(Room->getId() == id){
                delete Room;
                return true;
            }
            return false;
        });
        if(it != Rooms.end()){
            Rooms.erase(it, Rooms.end());
            std::cout << "\nDeleted successfully.\n";
        } else {
            throw std::invalid_argument("Room not found\n");
        }
    }
    void viewRoom(){
        if (Rooms.empty()) {
            throw std::invalid_argument("No Room available\n");
            return;
        }
         displayRoom();
        for(const auto& Room :Rooms){
            Room->displayname();
        }
    }
};