// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include <iostream>
#include "giftCards/giftCard.h"

int main() {

    IdGenerator& i = IdGenerator::getInstance();
    RandomNumberGenerator& r = RandomNumberGenerator::getInstance();

    GiftCard gfc1(&r, &i, GiftCardType::AllProducts, 10);
    GiftCard gfc2(&r, &i, GiftCardType::AllProducts, 10);

    std::cout << gfc1.getCode() << '\n';
    std::cout << gfc2.getCode() << '\n';

    return 0;
}