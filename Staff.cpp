#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <stdexcept>
using namespace std;

class Staff {
protected:
    std::string name;
    int id;
    std::string phone;

public:
    Staff() {}

    Staff(int id, std::string phone, std::string name)
        : id(id), phone(phone), name(name) {}

    // Getter methods
    int getId() const {
        return id;
    }

    std::string getPhone() const {
        return phone;
    }

    std::string getName() const {
        return name;
    }

    // Setter methods
    void setId(int id) {
        this->id = id;
    }

    void setPhone(const std::string& phone) {
        this->phone = phone;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    // Virtual methods
    virtual std::string getType() const = 0;

    virtual void displayname() const {
        
        std::cout << std::left << std::setw(20) << getType()
                  << std::setw(20) << id
                  << std::setw(15) << name
                  << std::setw(15) << phone << std::endl;
    }

    virtual std::string toString() {
        return name + "," + std::to_string(id) + "," + phone;
    }

    virtual ~Staff() = default;
};
