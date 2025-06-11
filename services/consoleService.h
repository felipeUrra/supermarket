// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "../workers/worker.h"
#include "../supermarket.h"
#include "../commands/commonCommands.h"
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

    static void detectCommand(Worker*& loggedUser, Supermarket* supermarket);

    static void printLine(const CustomString& str);
    static void discardInput();
};

template <>
inline int ConsoleService::readData<int>() {
    int var;
    std::cin >> var;
    return var;
}

template <>
inline double ConsoleService::readData<double>() {
    double var;
    std::cin >> var;
    return var;
}

template <>
inline CustomString ConsoleService::readData<CustomString>() {
    CustomString str;
    std::cin >> str;
    return str;
}