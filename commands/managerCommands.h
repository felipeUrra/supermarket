// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once

#include "../supermarket.h"

class ManagerCommands {
public:
    ManagerCommands() = delete;
    virtual ~ManagerCommands() = 0;

    static void approveCashier(Supermarket* supermarket, Worker* loggedUser);
    static void declineCashier(Supermarket* supermarket, Worker* loggedUser);
    
    static void listPending(Supermarket* supermarket, Worker* loggedUser);
    static void listWarnedCashier(Supermarket* supermarket, Worker* loggedUser);

    static void warnCashier(Supermarket* supermarket, Worker* loggedUser);
    static void fireCashier(Supermarket* supermarket, Worker* loggedUser);
    static void promoteCashier(Supermarket* supermarket, Worker* loggedUser);

    static void loadGiftCards(Supermarket* supermarket, Worker* loggedUser);
    static void loadProducts(Supermarket* supermarket, Worker* loggedUser);
    static bool getProductCommonData(Supermarket* supermarket, Product* product);
    
    static void addCategory(Supermarket* supermarket, Worker* loggedUser);
    static void addProductByUnit(Supermarket* supermarket, Worker* loggedUser);
    static void addProductByWeight(Supermarket* supermarket, Worker* loggedUser);
    static void addProduct(Supermarket* supermarket, Worker* loggedUser);

    static void deleteCategory(Supermarket* supermarket, Worker* loggedUser);
    static void deleteProduct(Supermarket* supermarket, Worker* loggedUser);
};