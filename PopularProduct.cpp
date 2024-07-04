#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include "Product.cpp"

class PopularProduct : public Product {
    public:
    PopularProduct() : Product(){}
    PopularProduct(const std::string& name, int id,int price,int quantity){
        this->name=name;
        this->id=id;
        this->price=price;
        this->quantity=quantity;
    }
    std::string getType() const override{
        return "Popular";
    }
    virtual std::string toString() {
        return getType() + "," + Product::toString();
    }
};