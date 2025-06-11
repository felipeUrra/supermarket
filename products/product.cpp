// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "product.h"

Product::Product() : name(""), price(0) {}

Product::Product(const CustomString& name, Category* category, double price) :
    name(name),
    category(category),
    price(price) {}

Product::~Product() {};

//getters and setters
const CustomString& Product::getName() const {return this->name;}
Category* Product::getCategory() {return this->category;}
double Product::getPrice() const {return this->price;}

void Product::setName(const CustomString& name) {this->name = name;}
void Product::setCategory(Category* category) {this->category = category;}
void Product::setPrice(double) {this->price = price;}