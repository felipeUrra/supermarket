// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "giftCard.h"

class SingleCategoryGiftCard : public GiftCard {
private:
    CustomString categoryName;

public:
    SingleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerato);
    SingleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator, double discount, const CustomString& categoryName);
    ~SingleCategoryGiftCard() = default;

    // Getters and setters
    const CustomString& getCategoryName() const;
    void setCategoryName(const CustomString& categoryName);

    // Serialize-deserialize
    void serialize(std::ofstream& out) const override;
    void deserialize(std::ifstream& in);
};