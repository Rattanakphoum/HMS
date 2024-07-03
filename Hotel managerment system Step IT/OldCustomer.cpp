#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Customer.cpp"

class OldCustomer : public Customer {
    public:
    OldCustomer(const std::string& name, int id,int type){
        this->name=name;
        this->id=id;
    }
    std::string getType() const override{
        return "Old Customer";
    }
};