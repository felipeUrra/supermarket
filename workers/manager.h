// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "worker.h"

class Manager : public Worker {
private:
    CustomString specialCode;

public: 
    Manager();
    Manager(const CustomString& name, const CustomString& lastName,
        int age,int telephoneNumber,
        const CustomString& password,
        const CustomString& specialCode);
    
    ~Manager() = default;

    //getters and setters
    const CustomString& getSpecialCode() const;
    void setSpecialCode(const CustomString& name);
};