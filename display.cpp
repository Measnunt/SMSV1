#pragma once
#include <iostream>
#include <iomanip>
#include "staff.cpp"
using namespace std;

void displayStaff()  {
        std::cout << std::left << setw(20) <<"|Type"
                  << std::setw(20) << "ID"
                  << std::setw(15) << "Name"
                  << std::setw(20) << "phone   |" << std::endl;
        std::cout << "------------------------------------------------------------------" <<endl;
};
void displayProduct() {
        std::cout << "=============VIEW=============\n";
        std::cout << std::left << setw(20) <<"|Type"
                  << std::setw(20) << "ID"
                  << std::setw(15) << "Name"
                  << std::setw(15) << "Price" 
                  << std::setw(15) << "Quantity |" << endl;
        std::cout << "--------------------------------------------------------------------------------" <<endl;
};
void displayMain(){
    std::cout <<"\n==============Welcome==============\n";
    std::cout <<"\n        1. Product Management\n";
    std::cout <<"        2. Staff Management\n";
    std::cout <<"        3. EXIT\n";
    std::cout <<"\n===================================\n";
};
void displayMenu(){
        std::cout << "======== Product Management =======\n";
        std::cout << "\n       1. Add Product\n";
        std::cout << "       2. Update Product\n";
        std::cout << "       3. View Product\n";
        std::cout << "       4. Delete Product\n";
        std::cout << "       5. Search Product\n";
        std::cout << "       6. Sort Product\n";
        std::cout << "       7. Save file\n";
        std::cout << "       8. Load file\n";
        std::cout << "       9. Back to Main Menu\n";
        std::cout << "\n===================================\n";
};
void displayMenuStaff(){
        std::cout << "========= Staff Management ========\n";
        std::cout << "\n         1. Add Staff\n";
        std::cout << "         2. Update Staff\n";
        std::cout << "         3. View Staff\n";
        std::cout << "         4. Delete Staff\n";
        std::cout << "         5. Search Product\n";
        std::cout << "         6. Sort Product\n";
        std::cout << "         7. Save file\n";
        std::cout << "         8. Load file\n";
        std::cout << "         9. Back to Main Menu\n";
        std::cout << "\n===================================\n";
};
void LoginDisplay(){
        std::cout <<"\n==============Welcome==============\n";
        std::cout <<"\n             1. LOGIN\n";
        std::cout <<"\n             2. REGISTER\n";
        std::cout <<"\n             3. EXIT\n";
        std::cout <<"\n===================================\n";
};


