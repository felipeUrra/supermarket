// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "../customFunctions/customString.h"
#include "../utils/idGenerator.h"

class Worker {
private:
    int id;
    CustomString name;
    CustomString lastName;
    int age;
    int telephoneNumber;
    CustomString password;

public:
    Worker(IdGenerator* idGenerator);
    Worker(IdGenerator* idGenerator, const CustomString& name, const CustomString& lastName,
        int age, int telephoneNumber, const CustomString& password);
    
    virtual ~Worker() = 0;

    // Getters and setters
    int getId() const;
    const CustomString& getName() const;
    const CustomString& getLastName() const;
    int getAge() const;
    int getTelephoneNumber() const;
    const CustomString& getPassword() const;

    void setName(const CustomString& name);
    void setLastName(const CustomString& lastName);
    void setAge(int age);
    void setTelephoneNumber(int telephoneNumber);
    void setPassword(const CustomString& password);
};