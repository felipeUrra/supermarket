// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "customFunctions/customVector.h"
#include "workers/worker.h"
#include "giftCards/giftCard.h"
#include "products/product.h"

class Supermarket {
private:
    CustomVector<Worker*> workersList;
    Worker* loggedUser;
    
    CustomVector<Category*> categoriesList;
    CustomVector<Product*> productsLIst;
    CustomVector<GiftCard*> giftCardsList;
};