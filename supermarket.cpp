// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "supermarket.h"

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
    return this->productsLIst;
}
CustomVector<GiftCard*>& Supermarket::getGiftCardsList() {
    return this->giftCardsList;
}
void Supermarket::addCategory(Category* category) {
    this->categoriesList.push_back(category);
}