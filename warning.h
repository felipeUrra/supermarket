// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "workers/manager.h"
#include "customFunctions/customString.h"

enum class WarningGrade {Low = 100, Middle = 200, High = 300};

class Warning {
private:
    Manager* sender;
    CustomString description;
    WarningGrade warningGrade;

public:
    Warning();
    Warning(Manager* sender, const CustomString& description, WarningGrade WarningGrade);
    ~Warning() = default;

    // Getters and setters
    Manager* getSender();
    const CustomString& getDescription() const;
    WarningGrade getWarningGrade() const;

    void setSender(Manager*);
    void setDescription(const CustomString&);
    void setWarningGrade(WarningGrade);
};