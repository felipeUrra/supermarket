// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "consoleService.h"
#include "../utils/utils.h"
#include "../commands/managerCommands.h"

CustomString ConsoleService::cmd = "";

const CustomString& ConsoleService::getCmd() {return cmd;}

const CustomString ConsoleService::readWords() {
    CustomString str;
    char* buffer = new char[256000];

    std::cin.getline(buffer, 256000);
    str = buffer;

    return str;
}

void ConsoleService::detectCommand(Worker*& loggedUser, Supermarket* supermarket) {
    CustomString cmd = ConsoleService::readData<CustomString>();
    if (cmd == "exit") {
        ConsoleService::printLine("Exiting the program...");
        exit(0);
    } else if (cmd == "register") {
        CommonCommands::registerUser(supermarket);
    } else if (cmd == "login") {
        CommonCommands::login(supermarket, loggedUser);
    } else if (cmd == "approve") {
        ManagerCommands::approveCashier(supermarket, loggedUser);
    } else if (cmd == "add_category") {
        ManagerCommands::addCategory(supermarket, loggedUser);
    }
    else {
        ConsoleService::printLine("Unknown command: " + cmd);
        ConsoleService::printLine("Please try again.");
    }
}

void ConsoleService::printLine(const CustomString& str) {
    std::cout << str << std::endl;
}

void ConsoleService::discardInput() {
    std::cin.ignore(10000, '\n');
}