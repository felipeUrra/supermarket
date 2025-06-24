// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "productByUnit.h"

ProductByUnit::ProductByUnit() : Product(ProductType::ByUnit), availableAmount(0) {}

ProductByUnit::ProductByUnit(const CustomString& name, const CustomString& categoryName, double price, int availableAmount) :
    Product(ProductType::ByUnit, name, categoryName, price),
    availableAmount(availableAmount) {}

int ProductByUnit::getAvailableAmount() const {return this->availableAmount;}
void ProductByUnit::setAvailableAmount(int availableAmount) {this->availableAmount = availableAmount;}

// Serialize-deserialize
void ProductByUnit::serialize(std::ofstream& out) const {
    this->serializeCommon(out);

    out.write(reinterpret_cast<const char*>(&this->availableAmount), sizeof(this->availableAmount));
}

void ProductByUnit::deserialize(std::ifstream& in) {
    this->deserializeCommon(in);

    in.read(reinterpret_cast<char*>(&this->availableAmount), sizeof(this->availableAmount));
}