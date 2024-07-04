#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Staff.cpp"

class PartTimeStaff : public Staff {
    public:
    PartTimeStaff(const std::string& name, int id,std::string phone){
        this->name=name;
        this->id=id;
        this->phone=phone;
    }
    std::string getType() const override{
        return "Part Time Staff";
    }

    std::string toString() {
        return getType() + "," + Staff::toString();
    }
};