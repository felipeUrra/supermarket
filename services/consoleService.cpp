// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "consoleService.h"
#include "../utils/utils.h"

CustomString ConsoleService::cmd = "";

const CustomString& ConsoleService::getCmd() {return cmd;}

const CustomString ConsoleService::readWords() {
    CustomString str;
    char* buffer = new char[256000];

    std::cin.getline(buffer, 256000);
    str = buffer;

    return str;
}

void ConsoleService::detectCommand(CustomString& cmd, Role loggedUserRole) {

}

// templateFunctions
template <>
int ConsoleService::readData<int>() {
    int var;
    std::cin >> var;
    
    return var;
}

template <>
double ConsoleService::readData<double>() {
    double var;
    std::cin >> var;

    return var;
}

template <>
CustomString ConsoleService::readData<CustomString>() {
    CustomString str;
    std::cin >> str;

    return str;
}