// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "productByWeight.h"

ProductByWeight::ProductByWeight() : Product(ProductType::ByWeight), availableKg(0) {}

ProductByWeight::ProductByWeight(const CustomString& name, const CustomString& categoryName, double price, double availableKg) :
    Product(ProductType::ByWeight, name, categoryName, price),
    availableKg(availableKg) {}

double ProductByWeight::getAvailableKg() const {return this->availableKg;}
void ProductByWeight::setAvailableKg(double availableKg) {this->availableKg = availableKg;}

// Serialize-deserialize
void ProductByWeight::serialize(std::ofstream& out) const {
    this->serializeCommon(out);

    out.write(reinterpret_cast<const char*>(&this->availableKg), sizeof(this->availableKg));
}

void ProductByWeight::deserialize(std::ifstream& in) {
    this->deserializeCommon(in);

    in.read(reinterpret_cast<char*>(&this->availableKg), sizeof(this->availableKg));
}