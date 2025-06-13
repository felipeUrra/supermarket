// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "warning.h"

Warning::Warning() : description(""), warningGrade(WarningGrade::Low) {}

Warning::Warning(int senderId, const CustomString& description, WarningGrade warningGrade) :
    senderId(senderId),
    description(description),
    warningGrade(warningGrade) {}


//getters and setters
int Warning::getSenderId() {return senderId;}
const CustomString& Warning::getDescription() const {return description;}
WarningGrade Warning::getWarningGrade() const {return warningGrade;}

void Warning::setSenderId(int sender) {this->senderId = senderId;}
void Warning::setDescription(const CustomString& description) {this->description = description;}
void Warning::setWarningGrade(WarningGrade warningGrade) {this->warningGrade = warningGrade;}