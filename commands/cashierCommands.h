// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once

#include "../supermarket.h"

class CashierCommands {
public:
    CashierCommands() = delete;
    virtual ~CashierCommands() = 0;

    static void sell(Supermarket* supermarket, Worker* loggedUser);
};