#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iomanip>

class Product {
protected:
    std::string name;
    int id;
    int price;
    int quantity;
public:
    Product(): name("none"), id(0), price(0), quantity(0){}
    Product(int id, int price, int quantity, std::string name):id(id),name(name),price(price),quantity(quantity){}
    //getter
    int getId(){
        return id;
    }
    int getPrice(){
        return price;
    }
    int getQuantity(){
        return quantity;
    }
    std::string getName(){
        return name;
    }
    //setter
    void setId(int id){
        this->id=id;
    }
    void setPrice(int price){
        this->price=price;
    }
    void setQuantity(int quantity){
        this->quantity=quantity;
    }
    void setName(std::string name){
        this->name=name;
    }
    virtual std::string getType() const = 0;
    virtual void displayname() const {
        
        std::cout << std::left << std::setw(20) << getType()
                  << std::setw(20) << id
                  << std::setw(15) << name<<"$"
                  << std::setw(15) << price
                  << std::setw(15) << quantity << std::endl;
    }
    virtual std::string toString() {
        return name + "," + std::to_string(id) + "," + std::to_string(price) + "," + std::to_string(quantity);
    }
    virtual ~Product() = default;
};