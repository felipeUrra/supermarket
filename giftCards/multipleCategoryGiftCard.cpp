// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "multipleCategoryGiftCard.h"

MultipleCategoryGiftCard::MultipleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator) :
    GiftCard(randomNumberGenerator, idGenerator) {}

MultipleCategoryGiftCard::MultipleCategoryGiftCard(RandomNumberGenerator& randomNumberGenerator, IdGenerator& idGenerator, double discount, CustomVector<int>& categoriesId) :
    GiftCard(randomNumberGenerator, idGenerator, GiftCardType::MultipleCategories, discount),
    categoriesId(categoriesId) {}


//getters and setters
CustomVector<int>& MultipleCategoryGiftCard::getCategoriesId() {return this->categoriesId;}
void MultipleCategoryGiftCard::setCategoriesId(CustomVector<int>& categoriesId) {
    this->categoriesId = categoriesId;
}

// Serialize-deserialize
void MultipleCategoryGiftCard::serialize(std::ofstream& out) const {
    this->serializeCommon(out);

    int categoriesIdCount = this->categoriesId.getSize();
    out.write(reinterpret_cast<const char*>(&categoriesIdCount), sizeof(categoriesIdCount));

    for (int i = 0; i < categoriesIdCount; i++) {
        out.write(reinterpret_cast<const char*>(&this->categoriesId[i]), sizeof(this->categoriesId[i]));
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