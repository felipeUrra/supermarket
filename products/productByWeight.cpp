// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "productByWeight.h"

ProductByWeight::ProductByWeight() : Product(), availableKg(0) {}

ProductByWeight::ProductByWeight(const CustomString& name, const CustomString& categoryName, double price, double availableKg) :
    Product(name, categoryName, price),
    availableKg(availableKg) {}

double ProductByWeight::getAvailableKg() const {return this->availableKg;}
void ProductByWeight::setAvailableKg(double availableKg) {this->availableKg = availableKg;}