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
    void setTransactionsPerformedCount(uint8_t);
    void setWarnings(CustomVector<Warning>);

    uint8_t getTransactionsPerformedCount() const;
    CustomVector<Warning> getWarnings() const;
};