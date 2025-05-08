// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "customFunctions/customString.h"
#include <stdint.h>

class Worker {
private:
    uint8_t workerId;
    static uint8_t nextWorkerId;
    CustomString name;
    CustomString lastName;
    uint8_t age;
    uint8_t telephoneNumber; // probably i will need to change the data type to something more accurate
    CustomString password;

public:
    Worker();
    Worker(uint8_t, const CustomString&, const CustomString&, uint8_t, uint8_t, const CustomString&);
    virtual ~Worker() = 0;

    // Getters and setters
    uint8_t getWorkerId() const;
    const CustomString& getName() const;
    const CustomString& getLastName() const;
    uint8_t getAge() const;
    uint8_t getTelephoneNumber() const;
    const CustomString& getPassword() const;

    void setWorkerId(uint8_t);
    void setName(const CustomString&);
    void setLastName(const CustomString&);
    void setAge(uint8_t);
    void setTelephoneNumber(uint8_t);
    void setPassword(const CustomString&); // i will have to create a checkIdentity() to validate the password change
};