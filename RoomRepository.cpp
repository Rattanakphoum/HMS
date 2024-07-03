#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include "SmallRoom.cpp"
#include "BigRoom.cpp"
#include "DataValidInput.cpp"
#include "Room.cpp"

class RoomRepository{
    virtual void addRoom(int id, std::string name,int Date, int type) = 0;
    virtual void viewRoom()=0;
    virtual void updateRoom(int id) = 0;
    virtual void deleteRoom(int id) = 0;

};