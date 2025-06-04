// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "worker.h"
#include "../warning.h"
#include "../customFunctions/customVector.h"

class Cashier : public Worker{
private:    
    int transactionsCount;
    CustomVector<Warning> warnings;

public:
    Cashier(IdGenerator* idGenerator);
    Cashier(IdGenerator* idGenerator, const CustomString& name, const CustomString& lastName,
        int age,int telephoneNumber,
        const CustomString& password,
        int transactionsCount, CustomVector<Warning> warnings);
    
    ~Cashier() = default;

    // Getters and setters
    void setTransactionsCount(int);
    void setWarnings(CustomVector<Warning>&);

    int getTransactionsCount() const;
    CustomVector<Warning>& getWarnings();
};