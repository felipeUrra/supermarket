// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "supermarket.h"
#include <fstream>

class System {
private:
    Supermarket* supermarket;
    Worker* loggedUser;
    bool exit;

public:
    System();
    ~System() = default;

    Supermarket* getSupermarket();
    Worker* getLoggedUser();
    bool getExit() const;

    void setSupermarket(Supermarket* supermarket);
    void setLoggedUser(Worker* loggedUser);
    void setExit(bool);

    // Serialize-deserialize
    void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);

    void run();
};