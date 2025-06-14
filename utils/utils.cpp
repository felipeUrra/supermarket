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

void Utils::saveSystemState(const System& system, const CustomString& filename) {
    const char* fn = filename.c_str();

    std::ofstream out(fn, std::ios::binary);
    if (!out.is_open()) {
        std::cerr << "Could not open file for writing: " << filename << "\n";
        return;
    }

    system.serialize(out);
    out.close();
}

void Utils::loadSystemState(System& system, const CustomString& filename) {
    const char* fn = filename.c_str();

    std::ifstream in(fn, std::ios::binary);
    if (!in.is_open()) {
        std::cerr << "Could not open file for reading: " << filename << "\n";
        return;
    }

    system.deserialize(in);
    in.close();
}