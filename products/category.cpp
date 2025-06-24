// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "category.h"

Category::Category(IdGenerator& idGenerator) : name(""), description(""), id(idGenerator.getCategoryId()) {}

Category::Category(IdGenerator& idGenerator, const CustomString name, const CustomString description) :
    name(name),
    description(description),
    id(idGenerator.getCategoryId()) {}

// getters and setters
const CustomString& Category::getName() const {return name;}
const CustomString& Category::getDescription() const {return description;}
int Category::getId() const {return id;}

void Category::setName(const CustomString& name) {this->name = name;}
void Category::setDescription(const CustomString& description) {this->description = description;}

// Serialize-deserialize
void Category::serialize(std::ofstream& out) const {
    name.serialize(out);
    description.serialize(out);
    out.write(reinterpret_cast<const char*>(&this->id), sizeof(this->id));
}

void Category::deserialize(std::ifstream& in) {
    name.deserialize(in);
    description.deserialize(in);
    in.read(reinterpret_cast<char*>(&this->id), sizeof(this->id));
}