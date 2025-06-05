// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once

class RandomNumberGenerator {
private:
    int num;
    char capitalLetter;
    char lowerCaseLetter;

    RandomNumberGenerator();

    RandomNumberGenerator(const RandomNumberGenerator&) = delete;
    RandomNumberGenerator& operator=(const RandomNumberGenerator&) = delete;

public:
    static RandomNumberGenerator& getInstance();

    int getNum();
    char getCapitalLetter();
    char getLowerCaseLetter();
};