// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "workers/manager.h"
#include "customFunctions/customString.h"

enum class WarningGrade {Low = 100, Middle = 200, High = 300};

class Warning {
private:
    int senderId;
    CustomString description;
    WarningGrade warningGrade;

    Warning();

public:
    Warning(int senderId, const CustomString& description, WarningGrade WarningGrade);
    ~Warning() = default;

    // Getters and setters
    int getSenderId();
    const CustomString& getDescription() const;
    WarningGrade getWarningGrade() const;

    void setSenderId(int senderId);
    void setDescription(const CustomString&);
    void setWarningGrade(WarningGrade);
};