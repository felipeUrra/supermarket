// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "giftCard.h"
#include "../customFunctions/customVector.h"

class MultipleCategoryGiftCard : public GiftCard {
private:
    CustomVector<CustomString> categories;

public:
    MultipleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator);
    MultipleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator, double discount, CustomVector<CustomString>& categories);
    ~MultipleCategoryGiftCard() = default;

    //getters and setters
    CustomVector<CustomString>& getCategories();
    void setCategories(CustomVector<CustomString>& categories);

    // Serialize-deserialize
    void serialize(std::ofstream& out) const override;
    void deserialize(std::ifstream& in);
};