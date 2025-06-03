// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "product.h"

class ProductByWeight : public Product {
private:
    double availableKg;

public:
    ProductByWeight();
    ProductByWeight(const CustomString& name, Category* category, double price, double availableKg);
    ~ProductByWeight() = default;

    //getters and setters
    double getAvailableKg() const;
    void setAvailableKg(double availableKg);
};