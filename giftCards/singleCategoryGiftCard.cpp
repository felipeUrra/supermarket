// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "singleCategoryGiftCard.h"

SingleCategoryGiftCard::SingleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator) :
    GiftCard(randomNumberGenerator, idGenerator) {}

SingleCategoryGiftCard::SingleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator, double discount, const CustomString& categoryName) :
    GiftCard(randomNumberGenerator, idGenerator , GiftCardType::SingleCategory, discount),
    categoryName(categoryName) {}


//getters and setters
const CustomString& SingleCategoryGiftCard::getCategoryName() const {return this->categoryName;}
void SingleCategoryGiftCard::setCategoryName(const CustomString& categoryName) {this->categoryName = categoryName;}

// Serialize-deserialize
void SingleCategoryGiftCard::serialize(std::ofstream& out) const {
    this->serializeCommon(out);

    out.write(reinterpret_cast<const char*>(&this->categoryName), sizeof(this->categoryName));
}

void SingleCategoryGiftCard::deserialize(std::ifstream& in) {
    this->deserializeCommon(in);

    in.read(reinterpret_cast<char*>(&this->categoryName), sizeof(this->categoryName));
}