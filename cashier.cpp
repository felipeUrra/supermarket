// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "cashier.h"

Cashier::Cashier() : Worker(), transactionsPerformedCount(0) {}

Cashier::Cashier(uint8_t workerId, const CustomString& name, const CustomString& lastName, uint8_t age,
                uint8_t telephoneNumber, const CustomString& password, 
                uint8_t transactionsPerformedCount, CustomVector<Warning> warnings)
    : Worker(workerId, name, lastName, age, telephoneNumber, password),
      transactionsPerformedCount(transactionsPerformedCount),
      warnings(warnings)

{

}

uint8_t Cashier::getTransactionsPerformedCount() const {return transactionsPerformedCount;}

CustomVector<Warning> Cashier::getWarnings() const {return warnings;}

void Cashier::setTransactionsPerformedCount(uint8_t transcationPerformedCount) {
    this->transactionsPerformedCount = transactionsPerformedCount;
}

void Cashier::setWarnings(CustomVector<Warning> warnings) {this->warnings = warnings;}
