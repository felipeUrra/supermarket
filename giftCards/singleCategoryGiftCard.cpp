// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "singleCategoryGiftCard.h"

SingleCategoryGiftCard::SingleCategoryGiftCard(GiftCardType type, Category* category) :
    GiftCard(type),
    category(category) {}

