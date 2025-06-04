// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "singleCategoryGiftCard.h"

SingleCategoryGiftCard::SingleCategoryGiftCard(double discount, Category* category) :
    GiftCard(GiftCardType::SingleCategory, discount),
    category(category) {}


//getters and setters
Category* SingleCategoryGiftCard::getCategory() {return this->category;}
void SingleCategoryGiftCard::setCategory(Category* category) {this->category = category;}