// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "product.h"

class ProductByUnit : public Product {
private:
    int availableAmount;

public:
    ProductByUnit();
    ProductByUnit(const CustomString& name, const CustomString& categoryName, double price, int availableAmount);
    ~ProductByUnit() = default;

    //getters and setters
    int getAvailableAmount() const;
    void setAvailableAmount(int availableKg);

    // Serialize-deserialize
    void serialize(std::ofstream& out) const override;
    void deserialize(std::ifstream& in);
};