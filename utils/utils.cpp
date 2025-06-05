// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "utils.h"

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