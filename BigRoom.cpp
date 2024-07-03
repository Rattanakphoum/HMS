#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Room.cpp"

class BigRoom : public Room {
    public:
    BigRoom(int id, std::string name,int Date, int type){
        this->name=name;
        this->id=id;
        this->type=type;
        this->Date=Date;
    }
    std::string getType() const override{
        return "Double Bed ";
    }
};