#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include "Staff.cpp"
#include "DataValidInput.cpp"
#include "StaffRepository.cpp"
#include "FullTimeStaff.cpp"
#include "PartTimeStaff.cpp"
#include "display.cpp"

class StaffManager : public StaffRepository {
private:
    std::vector<Staff*> staffs;
    string filename= "staff.txt";

    Staff* findstaffbyID(int id) {
        auto it = std::find_if(staffs.begin(), staffs.end(), [id](Staff* staff) {
            return staff->getId() == id;
        });
        return (it != staffs.end()) ? *it : nullptr;
    }

    bool confirmAction(const std::string& action) {
        std::string input;
        std::cout << "Are you sure you want to " << action << "? (y/n): ";
        std::cin >> input;
        return input == "y" || input == "Y";
    }

    vector<string> split(const string& str, char delimiter) {
        // empty vector to store the tokens
        vector<string> tokens;
        // empty string to store the token
        string token;
        // istringstream object to read the input string
        istringstream tokenStream(str);
        while (getline(tokenStream, token, delimiter)) {
            // Add the token to the vector of tokens
            tokens.push_back(token);
        }
        // Return the vector of tokens
        return tokens;
    }

public:
    StaffManager() {
        loadFromFile();
    }

    ~StaffManager() {
        for (auto staff : staffs) {
            delete staff;
        }
    }

    void saveToFile() {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error. Unable to open file for writing." << std::endl;
            return;
        }
        for (Staff* staff : staffs) {
            outFile << staff->toString() << std::endl;
        }
        outFile.close();
    }


    // Load from file from text
    void loadFromFile() {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error. Unable to open file for reading." << endl;
            return;
        }
        string line;
        while (getline(inFile, line)) {
            vector<string> tokens = split(line, ',');
            if (tokens[0] == "Full Time Staff") {
                Staff* staff = new FullTimeStaff(tokens[1], std::stoi(tokens[2]), tokens[3]);
                staffs.push_back(staff);
            } else if (tokens[0] == "Part Time Staff") {
                Staff* staff = new PartTimeStaff(tokens[1], std::stoi(tokens[2]), tokens[3]);
                staffs.push_back(staff);
            }
        }
        inFile.close();
    }

    void addStaff(int id, std::string name, int type, std::string phone) {
            std::cout <<"=========== ADD STAFF ===========\n";
            type= DataValidInput::getIntInput("Enter 1 for Full Time Staff, 2 for Part Time Staff\nChoice: ");
            id= DataValidInput::getIntInput("Enter Staff ID\nID: ");
            name= DataValidInput::getStringInput("Enter Staff Name\nName:");
            DataValidInput::validateId(id);
            phone= DataValidInput::getPhoneInput("Enter Staff Phone\nPhone: ");
        if (type == 1) {
            staffs.push_back(new FullTimeStaff(name, id, phone));
        } else if (type == 2) {
            staffs.push_back(new PartTimeStaff(name, id, phone));
        } else {
            throw std::invalid_argument("Invalid Staff Type.");
        }
        std::cout << "Staff added successfully.\n";
    }

    void updateStaff(int id) {
        id= DataValidInput::getIntInput("Enter Staff ID\nID:");
        DataValidInput::validateId(id);
        Staff* staff = findstaffbyID(id);
        if (staff == nullptr) {
            throw std::invalid_argument("Staff not found");
            return;
        }

        std::string newPhone = DataValidInput::getPhoneInput("Enter staff number: ");
        std::string newName = DataValidInput::getStringInput("Enter Staff Name: ");

        std::cout << "You entered:\n"
                  << "Name: " << newName << "\n"
                  << "Phone: " << newPhone << "\n";

        if (confirmAction("update this staff with the new information")) {
            staff->setPhone(newPhone);
            staff->setName(newName);
            std::cout << "Staff updated successfully.\n";
        } else {
            std::cout << "Update canceled.\n";
        }
    }

    void deleteStaff(int id) {
        id= DataValidInput::getIntInput("Enter Staff ID\nID: ");
        DataValidInput::validateId(id);
        Staff* staff = findstaffbyID(id);
        if (staff == nullptr) {
            throw std::invalid_argument("Staff not found");
            return;
        }

        std::cout << "You are about to delete the following staff:\n";
        staff->displayname();

        if (confirmAction("delete this staff")) {
            auto it = std::remove_if(staffs.begin(), staffs.end(), [id](Staff* staff) {
                if (staff->getId() == id) {
                    delete staff;
                    return true;
                }
                return false;
            });
            staffs.erase(it, staffs.end());
            std::cout << "Staff deleted successfully.\n";
        } else {
            std::cout << "Deletion canceled.\n";
        }
    }

    void viewStaff() {
        if (staffs.empty()) {
            throw std::invalid_argument("No staff available");
            return;
        }
        displayStaff();
        for (const auto& staff : staffs) {
            staff->displayname();
        }
    }

    void searchStaff(int id){
        id = DataValidInput::getIntInput("Enter Product ID\nID: ");
        DataValidInput::validateId(id);
        Staff* staff = findstaffbyID(id);
             if (staff == nullptr) {
            std::cout << "No staffs found matching the keyword.\n";
        } else {
            std::cout << "Search results:\n";
            staff->displayname();  // Assuming getInfo() prints staff details
        }
    }

    void sortStaff(int sortOption){
         if (sortOption == 1) {
            std::sort(staffs.begin(), staffs.end(), [](Staff* a, Staff* b) {
                return a->getName() < b->getName();
            });
        } else if (sortOption == 2) {
            std::sort(staffs.begin(), staffs.end(), [](Staff* a, Staff* b) {
                return a->getId() < b->getId();
            });
        } else {
            std::cout << "Invalid sort option.\n";
            return;
        }
        viewStaff();
    }
};
