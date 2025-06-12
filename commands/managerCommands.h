// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once

#include "../supermarket.h"

class ManagerCommands {
public:
    ManagerCommands() = delete;
    virtual ~ManagerCommands() = 0;

    static void approveCashier(Supermarket* supermarket, Worker* loggedUser);
    static void declineCashier(Supermarket* supermarket, Worker* loggedUser);
    static void addCategory(Supermarket* supermarket, Worker* loggedUser);
};