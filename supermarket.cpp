// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "supermarket.h"
#include <iostream>

void Supermarket::addCashier(Cashier* cashier) {
    this->pendingList.push_back(cashier);
}

void Supermarket::addWorker(Worker* worker) {
    this->workersList.push_back(worker);
}

CustomVector<Cashier*>& Supermarket::getPendingList() {
    return this->pendingList;
}
CustomVector<Worker*>& Supermarket::getWorkersList() {
    return this->workersList;
}
CustomVector<Category*>& Supermarket::getCategoriesList() {
    return this->categoriesList;
}
CustomVector<Product*>& Supermarket::getProductsList() {
    return this->productsList;
}
CustomVector<GiftCard*>& Supermarket::getGiftCardsList() {
    return this->giftCardsList;
}
void Supermarket::addCategory(Category* category) {
    this->categoriesList.push_back(category);
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
    out.write(reinterpret_cast<const char*>(&pendingListCount), sizeof(pendingList));
    for (int i = 0; i < pendingListCount; i++) {
        Cashier* c = this->pendingList[i];
        c->serialize(out);
    }
}

void Supermarket::deserialize(std::ifstream& in) {
    // deserializing workerList
    int workerListCount;
    in.read(reinterpret_cast<char*>(&workerListCount), sizeof(workerListCount));
    for (int i = 0; i < workerListCount; i++) {
        if (this->workersList[i]->getRole() == Role::Manager) {
            Manager* m = (Manager*)this->workersList[i];
            m->deserialize(in);
            continue;
        }

        Cashier* c = (Cashier*)this->workersList[i];
        c->deserialize(in);
    }

    int pendingListCount;
    in.read(reinterpret_cast<char*>(&pendingListCount), sizeof(pendingList));
    for (int i = 0; i < pendingListCount; i++) {
        Cashier* c = this->pendingList[i];
        c->deserialize(in);
    }
}