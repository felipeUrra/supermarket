// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once

#include "../system.h"

class CommonCommands {
public:
    CommonCommands() = delete;
    virtual ~CommonCommands() = 0;

    static void registerUser(Supermarket* supermarket);
    static void login(Supermarket* supermarket, Worker*& loggedUser);
    static void logout(Supermarket* supermarket, Worker*& loggedUser);
    static void listUserData(Supermarket* supermarket, Worker* loggedUser);
    static void exit(bool& exit);
};