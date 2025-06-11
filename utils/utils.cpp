// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "utils.h"
#include <iostream>
#include <limits>

CustomString Utils::intToStr(int num) {
    CustomString str;
    bool isNegative = false;

    if (num == 0) {
        str = "0";
    }
    
    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    while (num > 0) {
        char digit = '0' + (num % 10);
        str = digit + str;  // Prepend digit
        num /= 10;
    }

    if (isNegative) {
        str = '-' + str;
    }

    return str;
}

bool Utils::isAllGoodWithDataEntry(int var) {
    if (std::cin.fail() || var < 0) {
        std::cout << "Invalid ID! Please enter a positive integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool Utils::isAllGoodWithDataEntry(double var) {
    if (std::cin.fail()) {
        std::cout << "Invalid grade! Please enter a positive rational number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool Utils::isValidPhoneNumber(const CustomString& phoneNumber) {
    // TODO implement
    return true;
}