// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "../workers/worker.h"

//#define TT template <typename T>

class ConsoleService {
private:
    static CustomString cmd;

public:
    ConsoleService() = delete;
    virtual ~ConsoleService() = 0;

    //getters and setters
    static const CustomString& getCmd();

    template <typename T>
    static T readData();

    static const CustomString readWords();

    static void detectCommand(CustomString& cmd, Role loggedUserRole);
};