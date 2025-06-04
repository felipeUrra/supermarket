// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "workers/cashier.h"
#include "products/product.h"
#include "customFunctions/customVector.h"

class Transaction {
private:
    Cashier* cashier;
    double total;
    CustomString date;
    CustomString time;
    int id;
    CustomVector<Product*> products;


    void setActualDateAndTime(); // maybe put it in a class for Utils

public:
    Transaction(IdGenerator* idGenerator);
    Transaction(IdGenerator* idGenerator, Cashier* cashier, double total);
    ~Transaction() = default;

    //getters and setters
    Cashier* getCashier();
    double getTotal() const;
    const CustomString& getDate() const;
    const CustomString& getTime() const;
    int getId() const;
    CustomVector<Product*>& getProducts();

    void setCashier(Cashier* cashier);
    void setTotal(double total);
};