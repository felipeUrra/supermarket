// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "giftCard.h"

class SingleCategoryGiftCard : public GiftCard {
private:
    int categoryId;

public:
    SingleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerato);
    SingleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator, double discount, int categoryId);
    ~SingleCategoryGiftCard() = default;

    // Getters and setters
    int getCategoryId() const;
    void setCategoryId(int category);

    // Serialize-deserialize
    void serialize(std::ofstream& out) const override;
    void deserialize(std::ifstream& in);
};