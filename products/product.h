// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "category.h"

class Product {
private:
    CustomString name;
    CustomString categoryName; // TODO cambiarlo a category name
    double price;

public:
    Product();
    Product(const CustomString& name, const CustomString& categoryName, double price);
    virtual ~Product() = 0;

    //getters and setters
    const CustomString& getName() const;
    const CustomString& getCategoryName() const;
    double getPrice() const;

    void setName(const CustomString& name);
    void setCategoryName(const CustomString& category);
    void setPrice(double);
};

