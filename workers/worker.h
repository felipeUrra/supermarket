// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "../customFunctions/customString.h"
#include "../utils/idGenerator.h"

enum class Role {Manager = 1, Cashier = 2};

class Worker {
private:
    Role role;
    int id;
    CustomString name;
    CustomString lastName;
    int age;
    CustomString phoneNumber;
    CustomString password;

public:
    Worker(IdGenerator& idGenerator, Role role);
    Worker(IdGenerator& idGenerator, Role role, const CustomString& name, const CustomString& lastName,
        int age, const CustomString& phoneNumber, const CustomString& password);
    
    virtual ~Worker() = 0;

    // Getters and setters
    Role getRole() const;
    int getId() const;
    const CustomString& getName() const;
    const CustomString& getLastName() const;
    int getAge() const;
    const CustomString& getPhoneNumber() const;
    const CustomString& getPassword() const;

    void setName(const CustomString& name);
    void setLastName(const CustomString& lastName);
    void setAge(int age);
    void setPhoneNumber(CustomString& phoneNumber);
    void setPassword(const CustomString& password);


    const CustomString getRoleAsString() const;
};