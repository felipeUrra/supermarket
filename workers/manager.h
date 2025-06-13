// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "worker.h"
#include "../utils/randomNumberGenerator.h"

class Manager : public Worker {
private:
    CustomString specialCode;
    
    void generateSpecialCode(RandomNumberGenerator& randomNumberGenerator);

public: 
    Manager(IdGenerator& idGenerator, RandomNumberGenerator& randomNumberGenerator);
    Manager(IdGenerator& idGenerator, RandomNumberGenerator& randomNumberGenerator,
        const CustomString& name, const CustomString& lastName,
        int age, CustomString& phoneNumber,
        const CustomString& password);
    
    ~Manager() = default;

    // Getters and setters
    const CustomString& getSpecialCode() const;

    // Serialize-deserialize
    void serialize(std::ofstream& out) const override;
    void deserialize(std::ifstream& in);
};