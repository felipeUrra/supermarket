#pragma once
#include "manager.h"
#include "customFunctions/customString.h"

enum class CriticalityDegree {Low = 100, Middle = 200, High = 300};

class Warning {
private:
    Manager* sender; // it will be for reference, so i will not have a default constructor
    CustomString description;
    CriticalityDegree criticalityDegree;

public:
    Warning();
    Warning(Manager*, const CustomString&, CriticalityDegree);
    ~Warning() = default;

    // Getters and setters
    Manager* getSender() const;
    const CustomString& getDescription() const;
    CriticalityDegree getCriticalityDegree() const;

    void setSender(Manager*);
    void setDescription(const CustomString&);
    void setCriticalityDegree(CriticalityDegree);
};