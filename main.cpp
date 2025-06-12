// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include <iostream>
#include "workers/manager.h"
#include "utils/randomNumberGenerator.h"
#include "services/consoleService.h"
#include "commands/commonCommands.h"

int main() {
    ConsoleService::printLine("Welcome to FMI Supermarket Management System 2024-2025!");
    Supermarket* supermarket = new Supermarket();
    Worker* loggedUser = nullptr;
    do {
        std::cout << "> ";
        ConsoleService::detectCommand(loggedUser, supermarket);
    } while (true);

    // IdGenerator& i = IdGenerator::getInstance();
    // RandomNumberGenerator& r = RandomNumberGenerator::getInstance();

    // Manager manager(&i, &r);

    // std::cout << manager.getSpecialCode() << '\n';


    // ConsoleService& consoleService = ConsoleService::getInstance();

    // int n = consoleService.readData<int>();
    // double d = consoleService.readData<double>();
    // CustomString str = consoleService.readData<CustomString>();
    // CustomString words = consoleService.readWords();
    // std::cout << n << " " << d << " " << str << " " << words <<'\n';

    return 0;
}