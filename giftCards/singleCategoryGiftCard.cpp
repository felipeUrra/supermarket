// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "singleCategoryGiftCard.h"

SingleCategoryGiftCard::SingleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator) :
    GiftCard(randomNumberGenerator, idGenerator) {}

SingleCategoryGiftCard::SingleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator, double discount, int categoryId) :
    GiftCard(randomNumberGenerator, idGenerator , GiftCardType::SingleCategory, discount),
    categoryId(categoryId) {}


//getters and setters
int SingleCategoryGiftCard::getCategoryId() const {return this->categoryId;}
void SingleCategoryGiftCard::setCategoryId(int categoryId) {this->categoryId = categoryId;}

// Serialize-deserialize
void SingleCategoryGiftCard::serialize(std::ofstream& out) const {
    this->serializeCommon(out);

    out.write(reinterpret_cast<const char*>(&this->categoryId), sizeof(this->categoryId));
}

void SingleCategoryGiftCard::deserialize(std::ifstream& in) {
    this->deserializeCommon(in);

    in.read(reinterpret_cast<char*>(&this->categoryId), sizeof(this->categoryId));
}