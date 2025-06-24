// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "product.h"

Product::Product(ProductType type) : type(type), name(""), price(0) {}

Product::Product(ProductType type, const CustomString& name, const CustomString& categoryName, double price) :
    type(type),
    name(name),
    categoryName(categoryName),
    price(price) {}

Product::~Product() {};

//getters and setters
ProductType Product::getType() const {return this->type;}
const CustomString& Product::getName() const {return this->name;}
const CustomString& Product::getCategoryName() const{return this->categoryName;}
double Product::getPrice() const {return this->price;}

void Product::setName(const CustomString& name) {this->name = name;}
void Product::setCategoryName(const CustomString& categoryName) {this->categoryName = categoryName;}
void Product::setPrice(double price) {this->price = price;}

// Serialize-deserialize
void Product::serializeCommon(std::ofstream& out) const {
    int valueType = static_cast<int>(this->type);
    out.write(reinterpret_cast<const char*>(&valueType), sizeof(valueType));

    name.serialize(out);
    categoryName.serialize(out);

    out.write(reinterpret_cast<const char*>(&this->price), sizeof(this->price));
}

void Product::deserializeCommon(std::ifstream& in) {
    name.deserialize(in);
    categoryName.deserialize(in);

    in.read(reinterpret_cast<char*>(&this->price), sizeof(this->price));
}