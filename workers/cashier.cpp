// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "cashier.h"

Cashier::Cashier(IdGenerator& idGenerator) : Worker(idGenerator, Role::Cashier), transactionsCount(0) {}

Cashier::Cashier(IdGenerator& idGenerator, const CustomString& name, const CustomString& lastName, int age, const CustomString& phoneNumber, const CustomString& password) :
    Worker(idGenerator, Role::Cashier, name, lastName, age, phoneNumber, password),
    transactionsCount(0) {}

Cashier::~Cashier() {
    for (int i = 0; i < this->warnings.getSize(); i++) {
        delete this->warnings[i];
    }
}

// Getters and setters
int Cashier::getTransactionsCount() const {return transactionsCount;}
CustomVector<Warning*>& Cashier::getWarnings() {return warnings;}

void Cashier::setTransactionsCount(int transactionsCount) {this->transactionsCount = transactionsCount;}
void Cashier::setWarnings(CustomVector<Warning*>& warnings) {this->warnings = warnings;}

// Serialize-deserialize
void Cashier::serialize(std::ofstream& out) const {
    this->serializeCommon(out);

    out.write(reinterpret_cast<const char*>(&this->transactionsCount), sizeof(this->transactionsCount));
    
    int warningsCount = this->warnings.getSize();
    out.write(reinterpret_cast<const char*>(&warningsCount), sizeof(warningsCount));
    for (int i = 0; i < warningsCount; i++) {
        this->warnings[i]->serialize(out);
    }
}

void Cashier::deserialize(std::ifstream& in) {
    this->deserializeCommon(in);

    in.read(reinterpret_cast<char*>(&this->transactionsCount), sizeof(this->transactionsCount));

    int warningsCount;
    in.read(reinterpret_cast<char*>(&warningsCount), sizeof(warningsCount));
    //this->warnings.clear();
    for (int i = 0; i < warningsCount; i++) {
        Warning* w = new Warning();
        w->deserialize(in);
        warnings.push_back(w);
    }
}