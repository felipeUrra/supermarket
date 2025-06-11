// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "category.h"

Category::Category(IdGenerator& idGenerator) : name(""), description(""), id(idGenerator.getCategoryId()) {}

Category::Category(IdGenerator& idGenerator, const CustomString name, const CustomString description) :
    name(name),
    description(description),
    id(idGenerator.getCategoryId()) {}

//getters and setters
    const CustomString& Category::getName() const {return name;}
    const CustomString& Category::getDescription() const {return description;}
    int Category::getId() const {return id;}

    void Category::setName(const CustomString& name) {this->name = name;}
    void Category::setDescription(const CustomString& description) {this->description = description;}