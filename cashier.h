#pragma once
#include "worker.h"
#include "warning.h"

class Cashier : public Worker{
private:    
    uint8_t transactionsPerformedCount;
    Warning* warnigs;

    void copyFrom(const Cashier&);
    void free();

public:
    Cashier();
    Cashier(uint8_t, const Warning*);
    Cashier(const Cashier&);
    Cashier& operator=(const Cashier&);
    ~Cashier();

    // Getters and setters
    uint8_t getTransactionsPerformedCount();
    void setTransactionsPerformedCount(uint8_t);

    Warning* getWarnings();
    void setWarnings(const Warning*);
};