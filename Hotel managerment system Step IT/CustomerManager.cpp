#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Customer.cpp"
#include "DataValidInput.cpp"
#include "CustomerRepository.cpp"
#include "NewCustomer.cpp"
#include "OldCustomer.cpp"
#include "display.cpp"


class CustomerManager : public CustomerRepository{
    private:
        std::vector<Customer*> Customers;

        Customer* findCustomerbyID(int id){
            auto it = std::find_if(Customers.begin(),Customers.end(),[id](Customer* Customers){
                return Customers->getId() == id;
            });
            return (it != Customers.end()) ? *it : nullptr;
        }
        public:
            ~CustomerManager(){
                for(auto Customer : Customers){
                    delete Customer;
                }
            }
            void addCustomer(int id,std::string name,int type){
                if(type==1){
                        Customers.push_back(new NewCustomer(name,id,type));
                } else if (type==2){
                        Customers.push_back(new OldCustomer(name,id,type));
                } else{
                    throw std::invalid_argument("Invalide Customer Type.");
                }
                std::cout << "Customer added successfully.\n";
                }
                void updateCustomer(int id){
                    Customer* Customer = findCustomerbyID(id);
                    if(Customer == nullptr){
                        throw std::invalid_argument("Customer not found");
                        return;
                    }
                    std::string newName;
                    newName = DataValidInput::getStringInput("Enter Customer Name: ");
                    Customer->setName(newName);
                    std::cout <<"Customer update successfully.\n";
                }
                void deleteCustomer(int id){
                    auto it = std::remove_if(Customers.begin(),Customers.end(),[id](Customer* Customer){
                    if (Customer->getId() == id){
                        delete Customer;
                        return true;
                    }
                    return false;
                });
                if(it != Customers.end()){
                    Customers.erase(it,Customers.end());
                    std::cout <<"Customer delete successfully.\n";
                } else {
                    throw std::invalid_argument("Customer not found");
                }
            }
            void viewCustomer(){
                if (Customers.empty()){
                    throw std::invalid_argument("No Customer available");
                    return;
                }
                displayCustomer();
                for(const auto& Customer : Customers){
                    Customer->displayname();
                }
            }
        };