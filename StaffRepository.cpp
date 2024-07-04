#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include "FullTimeStaff.cpp"
#include "PartTimeStaff.cpp"
#include "DataValidInput.cpp"
#include "Staff.cpp"

class StaffRepository{
    virtual void addStaff(int id, std::string name, int type,std::string phone) = 0;
    virtual void viewStaff()=0;
    virtual void updateStaff(int id) = 0;
    virtual void deleteStaff(int id) = 0;

};