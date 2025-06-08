// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "../customFunctions/customString.h"
#include "../utils/randomNumberGenerator.h"
#include "../utils/idGenerator.h"

enum class GiftCardType {
    SingleCategory = 1,
    MultipleCategories = 2,
    AllProducts = 3
};

class GiftCard {
private:
    CustomString code;
    GiftCardType type;
    double discount;

    void generateCode(RandomNumberGenerator* randomNumberGenerator, IdGenerator* idGenerator);

public:
    GiftCard(RandomNumberGenerator* randomNumberGenerator, IdGenerator* idGenerator, GiftCardType type, double discount);
    virtual ~GiftCard() = 0;

    //getters and setters
    const CustomString& getCode() const;
    GiftCardType getType() const;
    double getDiscount() const;

    void setDiscount(double discount);


    const CustomString& getTypeAsString() const;
};