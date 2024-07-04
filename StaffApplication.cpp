#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "StaffManager.cpp"
#include "DataValidInput.cpp"

class StaffApplication {
private:
enum choiceMenu{ADD=1, UPDATE, VIEW, DELETE, SEARCH, SORT, SAVE, LOAD, RETURN};
    public:
    void run(){
        StaffManager manager;
        int choice;

        bool done = false;
    while ( !done ){
        displayMenuStaff();
        choice = DataValidInput::getIntInput("Enter your choice\nChoice: ");
        try{
            switch (choice)
            {
            case ADD:{
               
                int id,type;
                std::string name,phone;
                manager.addStaff(id,name,type,phone);
            break;
            }
            case UPDATE:{
               
                int id;
                manager.updateStaff(id);
                break;
            }
            case VIEW:
               
                manager.viewStaff();
                break;
            case DELETE:{
              
                int id;
                manager.deleteStaff(id);
                break;
            }
            case RETURN:
                done = true;
                break;
            case SEARCH: 
                int id;
                manager.searchStaff(id);
                break;
            case SORT: {
                    int sortOption = DataValidInput::getIntInput("Sort by: 1. Name 2. ID: ");
                    manager.sortStaff(sortOption);
                    break;
                }
            case SAVE:{
                    manager.saveToFile();
                    break;
            }
            case LOAD:{
                    manager.loadFromFile();
                    break;
            }
            default:
                std::cout<< "Invalide choice. Please try again.\n";
            }
        } catch (const std::exception& e){
            std::cout <<"Error!"<< e.what() <<std::endl;
        }
    }
    }
};