// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "warning.h"

Warning::Warning() : sender(nullptr), description(""), warningGrade(WarningGrade::Low) {}

Warning::Warning(Manager* sender, const CustomString& description, WarningGrade warningGrade) :
    sender(sender),
    description(description),
    warningGrade(warningGrade) {}


//getters and setters
Manager* Warning::getSender() {return sender;}
const CustomString& Warning::getDescription() const {return description;}
WarningGrade Warning::getWarningGrade() const {return warningGrade;}

void Warning::setSender(Manager* sender) {this->sender = sender;}
void Warning::setDescription(const CustomString& description) {this->description = description;}
void Warning::setWarningGrade(WarningGrade warningGrade) {this->warningGrade = warningGrade;}