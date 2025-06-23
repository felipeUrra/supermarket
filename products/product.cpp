// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "product.h"

Product::Product() : name(""), price(0) {}

Product::Product(const CustomString& name, const CustomString& categoryName, double price) :
    name(name),
    categoryName(categoryName),
    price(price) {}

Product::~Product() {};

//getters and setters
const CustomString& Product::getName() const {return this->name;}
const CustomString& Product::getCategoryName() const{return this->categoryName;}
double Product::getPrice() const {return this->price;}

void Product::setName(const CustomString& name) {this->name = name;}
void Product::setCategoryName(const CustomString& categoryName) {this->categoryName = categoryName;}
void Product::setPrice(double price) {this->price = price;}