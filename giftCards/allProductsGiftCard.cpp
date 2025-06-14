// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "allProductsGiftCard.h"

AllProductsGiftCard::AllProductsGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator) :
    GiftCard(randomNumberGenerator, idGenerator) {}

AllProductsGiftCard::AllProductsGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator, double discount) :
    GiftCard(randomNumberGenerator, idGenerator, GiftCardType::AllProducts, discount) {}

// Serialize-deserialize
void AllProductsGiftCard::serialize(std::ofstream& out) const {
    this->serializeCommon(out);
}

void AllProductsGiftCard::deserialize(std::ifstream& in) {
    this->deserializeCommon(in);
}