// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "giftCard.h"
#include "../products/category.h"

class SingleCategoryGiftCard : public GiftCard {
private:
    Category* category;

public:
    SingleCategoryGiftCard(RandomNumberGenerator* randomNumberGenerator, IdGenerator* idGenerator, double discount, Category* category);
    ~SingleCategoryGiftCard() = default;

    //getters and setters
    Category* getCategory();
    void setCategory(Category* category);
};