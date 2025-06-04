// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "../customFunctions/customString.h"
#include "../utils/idGenerator.h"

class Category {
private:
    CustomString name;
    CustomString description;
    int id;

public:
    Category(IdGenerator* idGenerator);
    Category(IdGenerator* idGenerator, const CustomString& name, const CustomString& description);
    ~Category() = default;

    //getters and setters
    const CustomString& getName() const;
    const CustomString& getDescription() const;
    int getId() const;

    void setName(const CustomString& name);
    void setDescription(const CustomString& description);
};