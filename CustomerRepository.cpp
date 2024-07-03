#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include "NewCustomer.cpp"
#include "OldCustomer.cpp"
#include "DataValidInput.cpp"
#include "Customer.cpp"

class CustomerRepository{
    virtual void addCustomer(int id,std::string name,int type) = 0;
    virtual void viewCustomer()=0;
    virtual void updateCustomer(int id) = 0;
    virtual void deleteCustomer(int id) = 0;

};