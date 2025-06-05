// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once

class IdGenerator {
private:
    int workerId;
    int transactionId;
    int categoryId;
    int giftCardCounter;

    IdGenerator();
    
    IdGenerator(const IdGenerator&) = delete;
    IdGenerator& operator=(const IdGenerator&) = delete;

public:
    static IdGenerator& getInstance();

    int getWorkerId();
    int getTransactionId();
    int getCategoryId();
    int getGiftCardCounter();

    void setWorkerId(int workerId);
    void setTransactionId(int transactionId);
    void setCategoryId(int categoryId);
    void setGiftCardCounter(int giftCardCounter);
};