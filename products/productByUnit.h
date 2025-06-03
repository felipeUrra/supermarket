// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "product.h"

class ProductByUnit : public Product {
private:
    int availableAmount;

public:
    ProductByUnit();
    ProductByUnit(const CustomString& name, Category* category, double price, int availableAmount);
    ~ProductByUnit() = default;

    //getters and setters
    int getAvailableAmount() const;
    void setAvailableAmount(int availableKg);
};