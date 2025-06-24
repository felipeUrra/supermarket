// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "idGenerator.h"

IdGenerator::IdGenerator() : workerId(100), transactionId(1), categoryId(0), giftCardCounter(0) {}

IdGenerator& IdGenerator::getInstance() {
    static IdGenerator instance; // Se crea una vez, la primera vez que se llama
    return instance;
}

int IdGenerator::getWorkerId() {return workerId++;}
int IdGenerator::getTransactionId() {return transactionId++;}
int IdGenerator::getCategoryId() {return categoryId++;}
int IdGenerator::getGiftCardCounter() {return giftCardCounter++;}

void IdGenerator::setWorkerId(int workerId) {this->workerId = workerId;}
void IdGenerator::setTransactionId(int transactionId) {this->transactionId = transactionId;}
void IdGenerator::setCategoryId(int categoryId) {this->categoryId = categoryId;}
void IdGenerator::setGiftCardCounter(int giftCardCounter) {this->giftCardCounter = giftCardCounter;}

// Serialize-deserialize
void IdGenerator::serialize(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&this->workerId), sizeof(this->workerId));
    out.write(reinterpret_cast<const char*>(&this->transactionId), sizeof(this->transactionId));
    out.write(reinterpret_cast<const char*>(&this->categoryId), sizeof(this->categoryId));
    out.write(reinterpret_cast<const char*>(&this->giftCardCounter), sizeof(this->giftCardCounter));
}

void IdGenerator::deserialize(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&this->workerId), sizeof(this->workerId));
    in.read(reinterpret_cast<char*>(&this->transactionId), sizeof(this->transactionId));
    in.read(reinterpret_cast<char*>(&this->categoryId), sizeof(this->categoryId));
    in.read(reinterpret_cast<char*>(&this->giftCardCounter), sizeof(this->giftCardCounter));
}