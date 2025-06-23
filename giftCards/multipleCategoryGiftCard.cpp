// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "multipleCategoryGiftCard.h"

MultipleCategoryGiftCard::MultipleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator) :
    GiftCard(randomNumberGenerator, idGenerator) {}

MultipleCategoryGiftCard::MultipleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator, double discount, CustomVector<CustomString>& categoriesNames) :
    GiftCard(randomNumberGenerator, idGenerator, GiftCardType::MultipleCategories, discount),
    categoriesNames(categoriesNames) {}


//getters and setters
CustomVector<CustomString>& MultipleCategoryGiftCard::getCategoriesNames() {return this->categoriesNames;}
void MultipleCategoryGiftCard::setCategoriesNames(CustomVector<CustomString>& categoriesNames) {
    this->categoriesNames = categoriesNames;
}

// Serialize-deserialize
void MultipleCategoryGiftCard::serialize(std::ofstream& out) const {
    this->serializeCommon(out);

    int categoriesIdCount = this->categoriesNames.getSize();
    out.write(reinterpret_cast<const char*>(&categoriesIdCount), sizeof(categoriesIdCount));

    for (int i = 0; i < categoriesIdCount; i++) {
        out.write(reinterpret_cast<const char*>(&this->categoriesNames[i]), sizeof(this->categoriesNames[i]));
    }
}

void MultipleCategoryGiftCard::deserialize(std::ifstream& in) {
    this->deserializeCommon(in);
    
    int categoriesIdCount;
    in.read(reinterpret_cast<char*>(&categoriesIdCount), sizeof(categoriesIdCount));

    for (int i = 0; i < categoriesIdCount; i++) {
        in.read(reinterpret_cast<char*>(&categoriesIdCount), sizeof(categoriesIdCount));
    }
}