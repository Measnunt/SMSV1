#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "ProductManager.cpp"
#include "DataValidInput.cpp"

class ProductApplication {
private:
enum choiceMenu{ADD=1, UPDATE, VIEW, DELETE, SEARCH, SORT, SAVE, LOAD, RETURN};
    
public:
    void run(){
        ProductManager manager;
        int choice;

        bool done = false;
    while ( !done ) {
        // system("cls");
        displayMenu();
        choice = DataValidInput::getIntInput("Enter your choice: ");
        try{
            switch (choice)
            {
        case ADD:{
                manager.addProduct();
                break;
        }
        case UPDATE:{
                int id;
                manager.updateProduct(id);
                break;
        }
        case VIEW:
                manager.viewProduct();
                break;
        case DELETE:{
                int id;
                manager.deleteProduct(id);
                break;
        }
        case RETURN:
                done = true;
                break;

        case SEARCH: 
                int id;
                manager.searchProduct(id);
                break;
        case SORT: {
                int sortOption = DataValidInput::getIntInput("Sort by: 1. Name 2. ID: ");
                manager.sortProduct(sortOption);
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
                std::cout << "Invalide choice. Please try again.\n";
            }
        } catch (const std::exception& e){
            std::cout << "Error!" << e.what() << std::endl;
        }
    }
    }
};