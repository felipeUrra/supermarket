// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "randomNumberGenerator.h"
#include <ctime>
#include <cstdlib>

RandomNumberGenerator& RandomNumberGenerator::getInstance() {
    static RandomNumberGenerator instance;
    return instance;
}

int RandomNumberGenerator::getNum() {
    std::srand(std::time(nullptr));
    this->num = std::rand() % 10;
    return this->num;
}

char RandomNumberGenerator::getCapitalLetter() {
    std::srand(std::time(nullptr));
    this->capitalLetter = (std::rand() % 26) + 'A';
    return this->capitalLetter;
}

char RandomNumberGenerator::getLowerCaseLetter() {
    std::srand(std::time(nullptr));
    this->lowerCaseLetter = (std::rand() % 26) + 'a';
    return this->lowerCaseLetter;
}