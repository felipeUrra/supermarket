#pragma once
#include "worker.h"
#include "warning.h"
#include "customFunctions/customVector.h"

class Cashier : public Worker{
private:    
    uint8_t transactionsPerformedCount;
    CustomVector<Warning> warnings;

public:
    Cashier();
    Cashier(uint8_t, const CustomString&, const CustomString&, uint8_t, uint8_t, const CustomString&, uint8_t, CustomVector<Warning>);
    ~Cashier() override = default;

    // Getters and setters
    void setWarnings(CustomVector<Warning>);
    void setTransactionsPerformedCount(uint8_t);

    CustomVector<Warning> getWarnings();
    uint8_t getTransactionsPerformedCount();
};