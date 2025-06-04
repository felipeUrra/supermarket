// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "giftCard.h"

GiftCard::GiftCard(GiftCardType type) : type(type) {
    setCode();
}

void GiftCard::setCode() {

}

//getters and setters
const CustomString& GiftCard::getCode() const {return this->code;}