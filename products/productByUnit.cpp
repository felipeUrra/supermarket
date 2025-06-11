// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "productByUnit.h"

ProductByUnit::ProductByUnit() : Product(), availableAmount(0) {}

ProductByUnit::ProductByUnit(const CustomString& name, Category* category, double price, int availableAmount) :
    Product(name, category, price),
    availableAmount(availableAmount) {}

int ProductByUnit::getAvailableAmount() const {return this->availableAmount;}
void ProductByUnit::setAvailableAmount(int availableAmount) {this->availableAmount = availableAmount;}