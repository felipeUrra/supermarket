// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "managerCommands.h"
#include "../services/consoleService.h"
#include "../utils/utils.h"
#include "../utils/idGenerator.h"
#include "../utils/randomNumberGenerator.h"
#include "../workers/worker.h"
#include "../workers/manager.h"
#include "../workers/cashier.h"

void ManagerCommands::approveCashier(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to approve cashiers.");
        ConsoleService::discardInput();
        return;
    }

    if (supermarket->getPendingList().isEmpty()) {
        ConsoleService::printLine("No pending cashiers to approve.");
        ConsoleService::discardInput();
        return;
    }

    int idCashier = ConsoleService::readData<int>();
    CustomString specialCode = ConsoleService::readData<CustomString>();
    
    Manager* manager = dynamic_cast<Manager*>(loggedUser);
    if (!manager || specialCode != manager->getSpecialCode()) {
        ConsoleService::printLine("Invalid special code. You cannot approve cashiers.");
        return;
    }
    for (size_t i = 0; i < supermarket->getPendingList().getSize(); i++) {
        Cashier* cashier = supermarket->getPendingList()[i];
        if (cashier->getId() == idCashier) {
            supermarket->addWorker(cashier);
            supermarket->getPendingList().remove(i);
            ConsoleService::printLine("Cashier approved successfully!");
            return;
        }
    }
    ConsoleService::printLine("Cashier not found in pending list.");
}

void ManagerCommands::addCategory(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add categories.");
        ConsoleService::discardInput();
        return;
    }

    const CustomString categoryName = ConsoleService::readData<CustomString>();
    const CustomString description = ConsoleService::readData<CustomString>();
    if (categoryName == "") {
        ConsoleService::printLine("Category name cannot be empty.");
        return;
    }

    Category* newCategory = new Category(IdGenerator::getInstance(), categoryName, description);
    supermarket->addCategory(newCategory);
    ConsoleService::printLine("Category \"" + categoryName + "\" added successfully!");
}