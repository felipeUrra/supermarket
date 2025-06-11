// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "giftCard.h"
#include "../products/category.h"
#include "../customFunctions/customVector.h"

class MultipleCategoryGiftCard : public GiftCard {
private:
    CustomVector<Category*> categories;

public:
    MultipleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator, double discount, CustomVector<Category*>& categories);
    ~MultipleCategoryGiftCard() = default;

    //getters and setters
    CustomVector<Category*>& getCategories();
    void setCategories(CustomVector<Category*>& categories);
};