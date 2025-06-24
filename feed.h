// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "customFunctions/customString.h"
#include <fstream>

class Feed {
private:
    CustomString authorName;
    CustomString authorLastName;
    CustomString description; // it will be the command name, bc it is descriptive enough
    CustomString date;
    CustomString time;

    void setActualDateAndTime();

public:
    Feed();
    Feed(const CustomString& authorName, const CustomString& authorLastName, const CustomString& description);
    ~Feed() = default;

    //getters and setters
    const CustomString& getAuthorName() const;
    const CustomString& getAuthorLastName() const;
    const CustomString& getDescription() const;
    const CustomString& getDate() const;
    const CustomString& getTime() const;

    void setDescription(const CustomString& description);

    // serialize-deserialize
    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);
};