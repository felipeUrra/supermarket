// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "giftCard.h"
#include "../customFunctions/customVector.h"

class MultipleCategoryGiftCard : public GiftCard {
private:
    CustomVector<CustomString> categoriesNames;

public:
    MultipleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator);
    MultipleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator, double discount, CustomVector<CustomString>& categoriesNames);
    ~MultipleCategoryGiftCard() = default;

    //getters and setters
    CustomVector<CustomString>& getCategoriesNames();
    void setCategoriesNames(CustomVector<CustomString>& categoriesNames);

    // Serialize-deserialize
    void serialize(std::ofstream& out) const override;
    void deserialize(std::ifstream& in);
};