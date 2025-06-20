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

void ConsoleService::detectCommand(Worker*& loggedUser, Supermarket* supermarket, bool& exit) {
    CustomString cmd = ConsoleService::readData<CustomString>();
    if (cmd == "exit") {
        CommonCommands::exit(exit);
    } else if (cmd == "register") {
        CommonCommands::registerUser(supermarket);
    } else if (cmd == "login") {
        CommonCommands::login(supermarket, loggedUser);
    } else if (cmd == "logout") {
        CommonCommands::logout(supermarket, loggedUser);
    } else if (cmd == "list-user-data") {
        CommonCommands::listUserData(supermarket, loggedUser);
    } else if (cmd == "approve") {
        ManagerCommands::approveCashier(supermarket, loggedUser);
    } else if (cmd == "add-category") {
        ManagerCommands::addCategory(supermarket, loggedUser);
    } else if (cmd == "decline") {
        ManagerCommands::declineCashier(supermarket, loggedUser);
    } else if (cmd == "list-pending") {
        ManagerCommands::listPending(supermarket, loggedUser);
    } else if (cmd == "load-gift-cards") {
        ManagerCommands::loadGiftCards(supermarket, loggedUser);
    } else if (cmd == "add-product") {
        ManagerCommands::addProduct(supermarket, loggedUser);
    } else if (cmd == "sell") {
        ManagerCommands::sell(supermarket, loggedUser);
    }
    else {
        ConsoleService::printLine("Unknown command: " + cmd);
        ConsoleService::printLine("Please try again.");
        ConsoleService::discardInput();
    }
}

void ConsoleService::printLine(const CustomString& str) {
    std::cout << str << std::endl;
}

void ConsoleService::discardInput() {
    std::cin.ignore(10000, '\n');
}