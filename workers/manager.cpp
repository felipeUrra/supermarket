// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "manager.h"

Manager::Manager(IdGenerator* idGenerator, RandomNumberGenerator* randomNumberGenerator) :
    Worker(idGenerator)
    {
        generateSpecialCode(randomNumberGenerator);
    }

Manager::Manager(IdGenerator* idGenerator, RandomNumberGenerator* randomNumberGenerator, const CustomString& name, const CustomString& lastName, int age, int telephoneNumber, const CustomString& password) :
    Worker(idGenerator, name, lastName, age, telephoneNumber, password),
    specialCode(specialCode)
    {
        generateSpecialCode(randomNumberGenerator);
    }


//getters and setters
const CustomString& Manager::getSpecialCode() const{return this->specialCode;}


void Manager::generateSpecialCode(RandomNumberGenerator* randomNumberGenerator) {
    int codeSize = 7;
    char str[codeSize];

    for (int i = 0; i < codeSize; i++) {
        if (i == 0 || (i >= 3 && i <= 5)) {
            str[i] = randomNumberGenerator->getNum();
            continue;
        }
        if (i >= 1 && i <= 2) {
            str[i] = randomNumberGenerator->getCapitalLetter();
            continue;
        }
        str[i] = randomNumberGenerator->getLowerCaseLetter();
    }

    this->specialCode = str;
}