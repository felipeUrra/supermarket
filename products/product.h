// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "category.h"

enum class ProductType{ByWeight = 1, ByUnit = 2};

class Product {
private:
    ProductType type;
    CustomString name;
    CustomString categoryName;
    double price;

public:
    Product(ProductType type);
    Product(ProductType type, const CustomString& name, const CustomString& categoryName, double price);
    virtual ~Product() = 0;

    //getters and setters
    ProductType getType() const;
    const CustomString& getName() const;
    const CustomString& getCategoryName() const;
    double getPrice() const;

    void setName(const CustomString& name);
    void setCategoryName(const CustomString& category);
    void setPrice(double);

    // Serialize-deserialize
    virtual void serialize(std::ofstream& out) const = 0;
    void serializeCommon(std::ofstream& out) const;
    void deserializeCommon(std::ifstream& in);
};

