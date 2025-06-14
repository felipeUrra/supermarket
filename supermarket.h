// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "customFunctions/customVector.h"
#include "workers/worker.h"
#include "giftCards/giftCard.h"
#include "products/product.h"
#include "workers/cashier.h"

class Supermarket {
private:
    CustomVector<Worker*> workersList;
    CustomVector<Cashier*> pendingList;
    
    CustomVector<Category*> categoriesList;
    CustomVector<Product*> productsList;
    CustomVector<GiftCard*> giftCardsList;
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
    void addCategory(Category* category);

    // Serialize-deserialize
    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);
};