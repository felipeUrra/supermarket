// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "giftCard.h"

GiftCard::GiftCard(GiftCardType type, double discount) : type(type), discount(discount) {
    setCode();
}

void GiftCard::setCode() {

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