// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "commonCommands.h"
#include "../services/consoleService.h"
#include "../utils/utils.h"

void CommonCommands::registerUser() {
    CustomString role = ConsoleService::readData<CustomString>();
    CustomString firstName = ConsoleService::readData<CustomString>();
    CustomString lastName = ConsoleService::readData<CustomString>();
    
    int phoneNumber = ConsoleService::readData<int>();
    if (!Utils::isAllGoodWithDataEntry(phoneNumber)) return;

    int age = ConsoleService::readData<int>();
    if (!Utils::isAllGoodWithDataEntry(age)) return;

    CustomString password;

    
}