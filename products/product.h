// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "category.h"

class Product {
private:
    CustomString name;
    Category* category;
    double price;

public:
    Product();
    Product(const CustomString& name, Category* category, double price);
    virtual ~Product() = 0;

    //getters and setters
    const CustomString& getName() const;
    Category* getCategory();
    double getPrice() const;

    void setName(const CustomString& name);
    void setCategory(Category* categoty);
    void setPrice(double);
};

