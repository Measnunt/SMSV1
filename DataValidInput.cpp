#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <regex>
#include <limits>
#include "Product.cpp"
#include "Staff.cpp"

class DataValidInput {
public:
    static void validateId(int id) {
        if (id <= 0) {
            throw std::invalid_argument("ID must be a positive integer.");
        }
    }
    static bool validateName(std::string name) {
    if (name.length() <= 2) {
    
        return false;
    }

    for (int i = 0; i < name.length(); i++) {
        if (!(name[i] >= 65 && name[i] <= 122)) {
            return false;
        }
    }
    return true;
}
static bool validatePhone(const std::string& phone) {
    // Check if the length is exactly 9
    if (phone.length() != 8) {
        return false;
    }

    // Check if the first character is '0'
    if (phone[0] != '0') {
        return false;
    }

    // Check if all characters are digits
    for (char c : phone) {
        if (!std::isdigit(c)) {
            return false;
        }
    }

    return true;
}
    static std::string getStringInput(const std::string& prompt) {
        std::string input;
        while (true){
            
        std::cout << prompt;
        std::getline(std::cin, input);
        if (validateName(input)) {break;}
        std::cout <<"Invalideinput!! ";
        }
            return input;

    }
static std::string getPhoneInput(const std::string& prompt) {
        std::string input;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, input);
            if (validatePhone(input)) {
                break;
            }
            std::cout << "Invalid input! Please enter a valid 8-digit phone number." << std::endl;
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
