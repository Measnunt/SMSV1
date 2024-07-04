#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include "Product.cpp"
#include "DataValidInput.cpp"
#include "ProductRepository.cpp"
#include "PopularProduct.cpp"
#include "NormalProduct.cpp"
#include "display.cpp"

class ProductManager : public ProductRepository {
private:
    std::vector<Product*> products;
    string filename= "product.txt";

    Product* findproductbyID(int id) {
        auto it = std::find_if(products.begin(), products.end(), [id](Product* product) {
            return product->getId() == id;
        });
        return (it != products.end()) ? *it : nullptr;
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
    ProductManager(){
        loadFromFile();
    }

    ~ProductManager() {
        for (auto product : products) {
            delete product;
        }
    }

    void addProduct() {
        int id, type, price, quantity;
                std::string name;
                std::cout <<"=========== ADD Product ===========\n";
                type = DataValidInput::getIntInput("Enter 1 for Popular Product, 2 for Normal product\nChoice: ");
                id = DataValidInput::getIntInput("Enter Product ID \nID: ");
                name = DataValidInput::getStringInput("Enter Product Name\nName: ");
                price = DataValidInput::getIntInput("Enter Product Price\nPrice$: ");
                quantity = DataValidInput::getIntInput("Enter Product Quantity\nQuantity: ");
        if (type == 1) {
            products.push_back(new PopularProduct(name, id, price, quantity));
        } else if (type == 2) {
            products.push_back(new NormalProduct(name, id, price, quantity));
        } else {
            throw std::invalid_argument("Invalid Product type.");
        }
        std::cout << "Product added successfully.\n";
    }

    void updateProduct(int id) {
        id = DataValidInput::getIntInput("Enter Product ID\nID: ");
        DataValidInput::validateId(id);
        Product* product = findproductbyID(id);
        if (product == nullptr) {
            throw std::invalid_argument("Product not found");
            return;
        }

        std::string newName = DataValidInput::getStringInput("Enter new Product Name\nName: ");
        int newPrice = DataValidInput::getIntInput("Enter new Product Price\nPrice: ");
        int newQuantity = DataValidInput::getIntInput("Enter new Product Quantity\nQuantity: ");

        std::cout << "You entered:\n"
                  << "Name: " << newName << "\n"
                  << "Price: " << newPrice << "\n"
                  << "Quantity: " << newQuantity << "\n";


        if (confirmAction("update this product")) {
            product->setName(newName);
            product->setPrice(newPrice);
            product->setQuantity(newQuantity);
            std::cout << "Product updated successfully.\n";
        } else {
            std::cout << "Update canceled.\n";
        }
    }

    void deleteProduct(int id) {
        id = DataValidInput::getIntInput("Enter Product ID\nID: ");
        DataValidInput::validateId(id);
        Product* product = findproductbyID(id);
        if (product == nullptr) {
            throw std::invalid_argument("Product not found");
            return;
        }

        std::cout << "You are about to delete the product with ID: " << id << "\n";
        product->displayname();

        if (confirmAction("delete this product")) {
            auto it = std::remove_if(products.begin(), products.end(), [id](Product* product) {
                if (product->getId() == id) {
                    delete product;
                    return true;
                }
                return false;
            });
            products.erase(it, products.end());
            std::cout << "Product deleted successfully.\n";
        } else {
            std::cout << "Deletion canceled.\n";
        }
    }
    void searchProduct(int id){
        id = DataValidInput::getIntInput("Enter Product ID\nID: ");
        DataValidInput::validateId(id);
        Product* product = findproductbyID(id);
             if (product == nullptr) {
            std::cout << "No products found matching the keyword.\n";
        } else {
            std::cout << "Search results:\n";
            product->displayname();  // Assuming getInfo() prints product details
        }
    }
    void sortProduct(int sortOption){
         if (sortOption == 1) {
            std::sort(products.begin(), products.end(), [](Product* a, Product* b) {
                return a->getName() < b->getName();
            });
        } else if (sortOption == 2) {
            std::sort(products.begin(), products.end(), [](Product* a, Product* b) {
                return a->getId() < b->getId();
            });
        } else {
            std::cout << "Invalid sort option.\n";
            return;
        }
        viewProduct();
    }
    void saveToFile() {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cerr << "Error. Unable to open file for writing." << std::endl;
            return;
        }
        for (Product* product : products) {
            outFile << product->toString() << std::endl;
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
            if (tokens[0] == "Popular") {
                Product* popularProduct = new PopularProduct(tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]), std::stoi(tokens[4]));
                products.push_back(popularProduct);
            } else if (tokens[0] == "Normal") {
                Product* normalProduct = new NormalProduct(tokens[1], std::stoi(tokens[2]), std::stoi(tokens[3]), std::stoi(tokens[4]));
                products.push_back(normalProduct);
            }
        }
        inFile.close();
    }
    void viewProduct() {
        if (products.empty()) {
            throw std::invalid_argument("No product available");
            return;
        }
        displayProduct();
        for (const auto& product : products) {
            product->displayname();
        }
    }
};
