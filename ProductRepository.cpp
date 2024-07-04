#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <string>
#include "PopularProduct.cpp"
#include "NormalProduct.cpp"
#include "DataValidInput.cpp"
#include "Product.cpp"

class ProductRepository{
    virtual void addProduct() = 0;
    virtual void viewProduct()=0;
    virtual void updateProduct(int id) = 0;
    virtual void deleteProduct(int id) = 0;
    virtual void sortProduct(int sortOption) = 0;
    virtual void saveToFile() = 0;
    virtual void loadFromFile() = 0;

};