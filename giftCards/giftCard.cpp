// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "giftCard.h"
#include "../utils/utils.h"

GiftCard::GiftCard(RandomNumberGenerator* randomNumberGenerator, IdGenerator* idGenerator, GiftCardType type, double discount) : type(type), discount(discount) {
    generateCode(randomNumberGenerator, idGenerator);
}

void GiftCard::generateCode(RandomNumberGenerator* randomNumberGenerator, IdGenerator* idGenerator) {
    int codeSize = 5;
    CustomString part1 = "12";
    CustomString part2;
    CustomString part3 = "12";

    part1[0] = randomNumberGenerator->getNum() + '0';
    part1[1] = randomNumberGenerator->getCapitalLetter();
    part2 = Utils::intToStr(idGenerator->getGiftCardCounter());
    part3[0] = randomNumberGenerator->getCapitalLetter();
    part3[1] = randomNumberGenerator->getNum() + '0';

    this->code = part1 + part2 + part3;
}

//getters and setters
const CustomString& GiftCard::getCode() const {return this->code;}
GiftCardType GiftCard::getType() const {return this->type;}
double GiftCard::getDiscount() const {return this->discount;}

void GiftCard::setDiscount(double discount) {this->discount = discount;}


const char* GiftCard::getTypeAsString() const {
    if (this->type == GiftCardType::SingleCategory) {return "SingleCategory";}
    if (this->type == GiftCardType::MultipleCategories) {return "MultipleCategories";}
    return "AllProducts";
}