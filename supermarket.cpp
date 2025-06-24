// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "supermarket.h"
#include "utils/idGenerator.h"
#include "utils/randomNumberGenerator.h"
#include "products/productByUnit.h"
#include "products/productByWeight.h"
#include "giftCards/singleCategoryGiftCard.h"
#include "giftCards/multipleCategoryGiftCard.h"
#include "giftCards/allProductsGiftCard.h"
#include "transaction.h"
#include <iostream>

void Supermarket::addCashier(Cashier* cashier) {
    this->pendingList.push_back(cashier);
}

void Supermarket::addWorker(Worker* worker) {
    this->workersList.push_back(worker);
}

CustomVector<Cashier*>& Supermarket::getPendingList() {return this->pendingList;}
CustomVector<Worker*>& Supermarket::getWorkersList() {return this->workersList;}
CustomVector<Category*>& Supermarket::getCategoriesList() {return this->categoriesList;}
CustomVector<Product*>& Supermarket::getProductsList() {return this->productsList;}
CustomVector<GiftCard*>& Supermarket::getGiftCardsList() {return this->giftCardsList;}
CustomVector<Transaction*>& Supermarket::getTransactionsList() {return this->transactionsList;}
CustomVector<Feed*>& Supermarket::getFeedList() {return this->feedList;}

void Supermarket::addCategory(Category* category) {
    this->categoriesList.push_back(category);
}

Worker* Supermarket::getWorkerById(int id) {
    for (int  i = 0; i < this->workersList.getSize(); i++) {
        if (this->workersList[i]->getId() == id) return this->workersList[i];
    }
    return nullptr;
}

Category* Supermarket::getCategoryByName(const CustomString& name) {
    for (int i = 0; i < this->categoriesList.getSize(); i++) {
        if (this->categoriesList[i]->getName() == name) return this->categoriesList[i];
    }
    return nullptr;
}

Category* Supermarket::getCategoryById(int id) {
    for (int i = 0; i < this->categoriesList.getSize(); i++) {
        if (this->categoriesList[i]->getId() == id) return this->categoriesList[i];
    }
    return nullptr;
}

GiftCard* Supermarket::getGiftCarByCode(const CustomString& code) {
    for (int i = 0; i < this->giftCardsList.getSize(); i++) {
        if (this->giftCardsList[i]->getCode() == code) {
            return this->giftCardsList[i];
        }
    }
    return nullptr;
}

Product* Supermarket::getProductByName(const CustomString& name) {
    for (int i = 0; i < this->productsList.getSize(); i++) {
        if (this->productsList[i]->getName() == name) {
            return this->productsList[i];
        }
    }
    return nullptr;
}

// Serialize-deserialize
void Supermarket::serialize(std::ofstream& out) const {
    // serializing workerList
    int workerListCount = this->workersList.getSize();
    out.write(reinterpret_cast<const char*>(&workerListCount), sizeof(workerListCount));
    for (int i = 0; i < workerListCount; i++) {
        if (this->workersList[i]->getRole() == Role::Manager) {
            Manager* m = (Manager*)this->workersList[i];
            m->serialize(out);
            continue;
        }

        Cashier* c = (Cashier*)this->workersList[i];
        c->serialize(out);
    }
    
    // serializing pendingList
    int pendingListCount = this->pendingList.getSize();
    out.write(reinterpret_cast<const char*>(&pendingListCount), sizeof(pendingListCount));
    for (int i = 0; i < pendingListCount; i++) {
        Cashier* c = this->pendingList[i];
        c->serialize(out);
    }


    // serializing categoriesList
    int categoriesListCount = this->categoriesList.getSize();
    out.write(reinterpret_cast<const char*>(&categoriesListCount), sizeof(categoriesListCount));
    for (int i = 0; i < categoriesListCount; i++) {
        Category* c = this->categoriesList[i];
        c->serialize(out);
    }
    
    // serializing productsList
    int productsListCount = this->productsList.getSize();
    out.write(reinterpret_cast<const char*>(&productsListCount), sizeof(productsListCount));

    for (int i = 0; i < productsListCount; i++) {
        if (this->productsList[i]->getType() == ProductType::ByWeight) {
            ProductByWeight* bw = (ProductByWeight*)this->productsList[i];
            bw->serialize(out);
            continue;
        }

        ProductByUnit* bu = (ProductByUnit*)this->productsList[i];
        bu->serialize(out);
    }

    // serializing giftCardsList
    int giftCardsListCount = this->giftCardsList.getSize();
    out.write(reinterpret_cast<const char*>(&giftCardsListCount), sizeof(giftCardsListCount));

    for (int i = 0; i < giftCardsListCount; i++) {
        if (this->giftCardsList[i]->getType() == GiftCardType::SingleCategory) {
            SingleCategoryGiftCard* sc = (SingleCategoryGiftCard*)this->giftCardsList[i];
            sc->serialize(out);
            continue;
        } else if(this->giftCardsList[i]->getType() == GiftCardType::MultipleCategories) {
            MultipleCategoryGiftCard* mc = (MultipleCategoryGiftCard*)this->giftCardsList[i];
            mc->serialize(out);
            continue;
        }

        AllProductsGiftCard* ap = (AllProductsGiftCard*)this->giftCardsList[i];
        ap->serialize(out);
    }

    // serializing transactionList
    int transactionListCount = this->transactionsList.getSize();
    out.write(reinterpret_cast<const char*>(&transactionListCount), sizeof(transactionListCount));
    for (int i = 0; i < transactionListCount; i++) {
        this->transactionsList[i]->serialize(out);
    }

    // serializin feedList
    int feedListCount = this->feedList.getSize();
    out.write(reinterpret_cast<const char*>(&feedListCount), sizeof(feedListCount));
    for (int i = 0; i < feedListCount; i++) {
        this->feedList[i]->serialize(out);
    }
    

    // serializing IdGeneratorValues;
    IdGenerator::getInstance().serialize(out);
}

void Supermarket::deserialize(std::ifstream& in) {
    // deserializing workerList
    int workerListCount;
    in.read(reinterpret_cast<char*>(&workerListCount), sizeof(workerListCount));
    for (int i = 0; i < workerListCount; i++) {
        int valueRole;
        in.read(reinterpret_cast<char*>(&valueRole), sizeof(valueRole));

        if (valueRole == 1) {
            Manager* m = new Manager(IdGenerator::getInstance(), RandomNumberGenerator::getInstance());
            m->deserialize(in);
            this->workersList.push_back(m);
            continue;
        }

        Cashier* c = new Cashier(IdGenerator::getInstance());
        c->deserialize(in);
        this->workersList.push_back(c);
    }

    // deserializing pendingList
    int pendingListCount;
    in.read(reinterpret_cast<char*>(&pendingListCount), sizeof(pendingListCount));
    for (int i = 0; i < pendingListCount; i++) {
        int residualRole;
        in.read(reinterpret_cast<char*>(&residualRole), sizeof(residualRole));
        
        Cashier* c = new Cashier(IdGenerator::getInstance());
        c->deserialize(in);
        this->pendingList.push_back(c);
    }

    // deserializing categoriesList
    int categoriesListCount;
    in.read(reinterpret_cast<char*>(&categoriesListCount), sizeof(categoriesListCount));
    for (int i = 0; i < categoriesListCount; i++) {
        Category* c = new Category(IdGenerator::getInstance());
        c->deserialize(in);
        this->categoriesList.push_back(c);
    }

    // deserializing productList
    int productsListCount;
    in.read(reinterpret_cast<char*>(&productsListCount), sizeof(productsListCount));

    for (int i = 0; i < productsListCount; i++) {
        int valueProductType;
        in.read(reinterpret_cast<char*>(&valueProductType), sizeof(valueProductType));

        if (valueProductType == static_cast<int>(ProductType::ByWeight)) {
            ProductByWeight* bw = new ProductByWeight();
            bw->deserialize(in);
            this->productsList.push_back(bw);
            continue;
        }
        
        ProductByUnit* bu = new ProductByUnit();
        bu->deserialize(in);
        this->productsList.push_back(bu);
    }

    // deserializing giftCardsList
    int giftCardsListCount;
    in.read(reinterpret_cast<char*>(&giftCardsListCount), sizeof(giftCardsListCount));

    for (int i = 0; i < giftCardsListCount; i++) {
        int valueGiftCardType;
        in.read(reinterpret_cast<char*>(&valueGiftCardType), sizeof(valueGiftCardType));

        if (valueGiftCardType == static_cast<int>(GiftCardType::SingleCategory)) {
            SingleCategoryGiftCard* sc = new SingleCategoryGiftCard(RandomNumberGenerator::getInstance(), IdGenerator::getInstance());
            sc->deserialize(in);
            this->giftCardsList.push_back(sc);
            continue;
        } else if(valueGiftCardType == static_cast<int>(GiftCardType::MultipleCategories)) {
            MultipleCategoryGiftCard* mc = new MultipleCategoryGiftCard(RandomNumberGenerator::getInstance(), IdGenerator::getInstance());
            mc->deserialize(in);
            this->giftCardsList.push_back(mc);
            continue;
        }
        
        AllProductsGiftCard* ap = new AllProductsGiftCard(RandomNumberGenerator::getInstance(), IdGenerator::getInstance());
        ap->deserialize(in);
        this->giftCardsList.push_back(ap);
    }

    // deserializing transactionsList
    int transactionsListCount;
    in.read(reinterpret_cast<char*>(&transactionsListCount), sizeof(transactionsListCount));
    for (int i = 0; i < transactionsListCount; i++) {
        this->transactionsList[i]->deserialize(in);
    }
    
    // deserializing feedList
    int feedListCount;
    in.read(reinterpret_cast<char*>(&feedListCount), sizeof(feedListCount));
    for (int i = 0; i < feedListCount; i++) {
        this->feedList[i]->deserialize(in);
    }

    // deserializing IdGenerator
    IdGenerator::getInstance().deserialize(in);
}