#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
using namespace std;

class Room {
protected:
    std::string name;
    int id;
    int Date;
    int type;
public:
    Room(){}
    Room(int id, int type,int Date, std::string name):id(id),name(name),Date(Date),type(type){}
    //getter
    int getId(){
        return id;
    }
    int getDate(){
        return Date;
    }
    int gettype(){
        return type;
    }
    std::string getName(){
        return name;
    }

    //setter
    void setId(int id){
        this->id=id;
    }
    void setName(std::string name){
        this->name=name;
    }
    void setDate(int Date){
        this->Date=Date;
    }
    virtual std::string getType() const = 0;
   virtual void displayname() const {
        
        std::cout << std::left << std::setw(20) << getType()
                  << std::setw(20) << id
                  << std::setw(15) << Date
                  << std::setw(15) << name << std::endl;
    }
    virtual ~Room() = default;


};