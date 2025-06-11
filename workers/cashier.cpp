// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "cashier.h"

Cashier::Cashier(IdGenerator& idGenerator) : Worker(idGenerator, Role::Cashier), transactionsCount(0) {}

Cashier::Cashier(IdGenerator& idGenerator, const CustomString& name, const CustomString& lastName, int age, const CustomString& phoneNumber, const CustomString& password) :
    Worker(idGenerator, Role::Cashier, name, lastName, age, phoneNumber, password),
    transactionsCount(0) {}


//Getters and setters
int Cashier::getTransactionsCount() const {return transactionsCount;}
CustomVector<Warning>& Cashier::getWarnings() {return warnings;}

void Cashier::setTransactionsCount(int transactionsCount) {this->transactionsCount = transactionsCount;}
void Cashier::setWarnings(CustomVector<Warning>& warnings) {this->warnings = warnings;}