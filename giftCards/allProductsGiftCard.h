// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "giftCard.h"

class AllProductsGiftCard : public GiftCard {
public:
    AllProductsGiftCard(RandomNumberGenerator* randomNumberGenerator, IdGenerator* idGenerator, double discount);
    ~AllProductsGiftCard() = default;
};