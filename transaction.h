// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "workers/cashier.h"
#include "products/product.h"
#include "customFunctions/customVector.h"
#include "supermarket.h"
#include "giftCards/giftCard.h"

class Transaction {
private:
    int cashierId;
    double total;
    CustomString date;
    CustomString time;
    int id;
    CustomVector<CustomString> productsName;
    CustomVector<double> prices;
    CustomVector<double> quantities;
    // TODO vector que tenga las cantidades de un producto


    void setActualDateAndTime(); // maybe put it in a class for Utils

public:
    Transaction(IdGenerator& idGenerator);
    Transaction(IdGenerator& idGenerator, int cashierId, double total);
    ~Transaction() = default;

    //getters and setters
    int getCashierId();
    double getTotal() const;
    const CustomString& getDate() const;
    const CustomString& getTime() const;
    int getId() const;
    CustomVector<CustomString>& getProductsName();
    CustomVector<double>& getPrices();
    CustomVector<double>& getQuantities();

    void setCashierId(int cashierId);
    void setTotal(double total);

    void applyGiftCard(GiftCard* gc, Supermarket* supermarket);
};