#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <regex>
#include "Room.cpp"
#include "Customer.cpp"

class DataValidInput {
public:
    static void validateId(int id) {
        if (id <= 0) {
            throw std::invalid_argument("ID must be a positive integer.");
        }
    }

    static bool validateName(const std::string& name) {
        std::regex pattern(R"([A-Za-z]{4,})");
        return std::regex_match(name, pattern);
      return true;

    }

    static std::string getStringInput(const std::string& prompt) {
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        while (!validateName(input)) {
            std::cout << "Invalid input! Please enter a valid name: ";
            std::getline(std::cin, input);
        }
        return input;
    }

    static int getIntInput(const std::string& prompt) {
        int input;
        std::cout << prompt;
        while (!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer: ";
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return input;
    }
};
