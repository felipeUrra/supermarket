// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "customFunctions/customVector.h"
#include "workers/worker.h"
#include "workers/cashier.h"
#include "feed.h"
#include "giftCards/giftCard.h"
#include "products/product.h"

class Transaction;

class Supermarket {
private:
    CustomVector<Worker*> workersList;
    CustomVector<Cashier*> pendingList;
    
    CustomVector<Category*> categoriesList;
    CustomVector<Product*> productsList;
    CustomVector<GiftCard*> giftCardsList;
    CustomVector<Transaction*> transactionsList;
    CustomVector<Feed*> feedList;
    
public:
    Supermarket() = default;
    ~Supermarket() = default; // TODO hacer la implementacion

    CustomVector<Cashier*>& getPendingList();
    void addCashier(Cashier* cashier);
    void addWorker(Worker* worker);
    CustomVector<Worker*>& getWorkersList();
    CustomVector<Category*>& getCategoriesList();
    CustomVector<Product*>& getProductsList();
    CustomVector<GiftCard*>& getGiftCardsList();
    CustomVector<Transaction*>& getTransactionsList();
    CustomVector<Feed*>& getFeedList();

    void addCategory(Category* category);

    Worker* getWorkerById(int id);
    Category* getCategoryByName(const CustomString& name);
    Category* getCategoryById(int id);
    GiftCard* getGiftCarByCode(const CustomString& code);
    Product* getProductByName(const CustomString& name);
    
    // Serialize-deserialize
    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);
};