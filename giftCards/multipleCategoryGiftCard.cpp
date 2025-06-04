// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "multipleCategoryGiftCard.h"

MultipleCategoryGiftCard::MultipleCategoryGiftCard(double discount, CustomVector<Category*>& categories) :
    GiftCard(GiftCardType::MultipleCategories, discount),
    categories(categories) {}


//getters and setters
CustomVector<Category*>& MultipleCategoryGiftCard::getCategories() {return this->categories;}
void MultipleCategoryGiftCard::setCategories(CustomVector<Category*>& categories) {
    this->categories = categories;
}