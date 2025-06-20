// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "singleCategoryGiftCard.h"

SingleCategoryGiftCard::SingleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator) :
    GiftCard(randomNumberGenerator, idGenerator) {}

SingleCategoryGiftCard::SingleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator, double discount, CustomString category) :
    GiftCard(randomNumberGenerator, idGenerator , GiftCardType::SingleCategory, discount),
    category(category) {}


//getters and setters
CustomString SingleCategoryGiftCard::getCategory() const {return this->category;}
void SingleCategoryGiftCard::setCategory(CustomString category) {this->category = category;}

// Serialize-deserialize
void SingleCategoryGiftCard::serialize(std::ofstream& out) const {
    this->serializeCommon(out);

    out.write(reinterpret_cast<const char*>(&this->category), sizeof(this->category));
}

void SingleCategoryGiftCard::deserialize(std::ifstream& in) {
    this->deserializeCommon(in);

    in.read(reinterpret_cast<char*>(&this->category), sizeof(this->category));
}