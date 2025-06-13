// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "manager.h"

Manager::Manager(IdGenerator& idGenerator, RandomNumberGenerator& randomNumberGenerator) :
    Worker(idGenerator, Role::Manager)
    {
        generateSpecialCode(randomNumberGenerator);
    }

Manager::Manager(IdGenerator& idGenerator, RandomNumberGenerator& randomNumberGenerator, const CustomString& name, const CustomString& lastName, int age, CustomString& phoneNumber, const CustomString& password) :
    Worker(idGenerator, Role::Manager, name, lastName, age, phoneNumber, password),
    specialCode("")
    {
        generateSpecialCode(randomNumberGenerator);
    }


//getters and setters
const CustomString& Manager::getSpecialCode() const{return this->specialCode;}


void Manager::generateSpecialCode(RandomNumberGenerator& randomNumberGenerator) {
    int codeSize = 7;
    char str[codeSize];

    for (int i = 0; i < codeSize; i++) {
        if (i == 0 || (i >= 3 && i <= 5)) {
            str[i] = randomNumberGenerator.getNum() + '0';
            continue;
        }
        if (i >= 1 && i <= 2) {
            str[i] = randomNumberGenerator.getCapitalLetter();
            continue;
        }
        str[i] = randomNumberGenerator.getLowerCaseLetter();
    }

    this->specialCode = str;
}

void Manager::serialize(std::ofstream& out) const {
    this->serializeCommon(out);

    this->specialCode.serialize(out);
}

void Manager::deserialize(std::ifstream& in) {
    this->deserializeCommon(in);

    this->specialCode.deserialize(in);
}