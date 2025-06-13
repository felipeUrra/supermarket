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

// Serialize-deserialize
void Warning::serialize(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&this->senderId), sizeof(this->senderId));
    
    this->description.serialize(out);
    
    int warningGradeValue = static_cast<int>(this->warningGrade);
    out.write(reinterpret_cast<const char*>(&warningGradeValue), sizeof(warningGradeValue));
}

void Warning::deserialize(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&this->senderId), sizeof(this->senderId));

    this->description.deserialize(in);

    int warningGradeValue;
    in.read(reinterpret_cast<char*>(&warningGradeValue), sizeof(warningGradeValue));
    this->warningGrade = static_cast<WarningGrade>(warningGradeValue);
}