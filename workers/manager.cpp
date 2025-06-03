// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "manager.h"

Manager::Manager() : Worker(), specialCode("") {}

Manager::Manager(const CustomString& name, const CustomString& lastName, int age, int telephoneNumber, const CustomString& password, const CustomString& specialCode) :
    Worker(name, lastName, age, telephoneNumber, password),
    specialCode(specialCode) {}


//getters and setters
const CustomString& Manager::getSpecialCode() const{return this->specialCode;}
void Manager::setSpecialCode(const CustomString& specialCode) {this->specialCode = specialCode;}