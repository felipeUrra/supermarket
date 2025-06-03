// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "cashier.h"

Cashier::Cashier() : Worker(), transactionsCount(0) {}

Cashier::Cashier(const CustomString& name, const CustomString& lastName, int age, int telephoneNumber, const CustomString& password, int transactionsCount, CustomVector<Warning> warnings) :
    Worker(name, lastName, age, telephoneNumber, password),
    transactionsCount(transactionsCount),
    warnings(warnings) {}


//Getters and setters
int Cashier::getTransactionsCount() const {return transactionsCount;}
CustomVector<Warning>& Cashier::getWarnings() {return warnings;}

void Cashier::setTransactionsCount(int transcationCount) {this->transactionsCount = transactionsCount;}
void Cashier::setWarnings(CustomVector<Warning>& warnings) {this->warnings = warnings;}