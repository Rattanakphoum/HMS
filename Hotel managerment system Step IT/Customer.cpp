#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>

class Customer{
protected:
    std::string name;
    int id;
    int phone;
public:
    Customer(){}
    Customer(std::string name,int id) :id(id),name(name){}
    //getter
    int getId(){
        return id;
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
    virtual std::string getType() const = 0;

 virtual void displayname() const {
        
        std::cout << std::left << std::setw(20) << getType()
                  << std::setw(20) << id
                  << std::setw(15) << name << std::endl;
    }

    virtual ~Customer() = default;

};
