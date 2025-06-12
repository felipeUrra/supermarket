// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "commonCommands.h"
#include "../services/consoleService.h"
#include "../utils/utils.h"
#include "../utils/idGenerator.h"
#include "../utils/randomNumberGenerator.h"
#include "../workers/worker.h"
#include "../workers/manager.h"
#include "../workers/cashier.h"

void CommonCommands::registerUser(Supermarket* supermarket) {
    CustomString role = ConsoleService::readData<CustomString>();
	if (role != "manager" && role != "cashier") {
		ConsoleService::printLine("Invalid role");
        ConsoleService::discardInput();
        return;
	}
    CustomString firstName = ConsoleService::readData<CustomString>();
    CustomString lastName = ConsoleService::readData<CustomString>();
    CustomString phoneNumber = ConsoleService::readData<CustomString>();
    if (!Utils::isValidPhoneNumber(phoneNumber)) {
		ConsoleService::printLine("Invalid phone number");
        ConsoleService::discardInput();
		return;
	}
    int age = ConsoleService::readData<int>();
    if (!Utils::isAllGoodWithDataEntry(age)) return;

    CustomString password = ConsoleService::readData<CustomString>();

    // add data specific to the role
    Worker* worker = nullptr;
    if (role == "manager") {
        worker = new Manager(IdGenerator::getInstance(), RandomNumberGenerator::getInstance(), firstName, lastName, age, phoneNumber, password);
        supermarket->addWorker(worker);
    } else if (role == "cashier") {
        worker = new Cashier(IdGenerator::getInstance(), firstName, lastName, age, phoneNumber, password);
        // adding the cashier to the pending list in supermarket
        supermarket->addCashier((Cashier*)worker);
    }
    ConsoleService::printLine("User registered successfully! " + worker->getName() + " " + worker->getLastName() + " with ID: " + (CustomString::valueOf(worker->getId())));
}

void CommonCommands::login(Supermarket* supermarket, Worker*& loggedUser) {
    if (loggedUser != nullptr) {
        ConsoleService::printLine("You are already logged in as " + loggedUser->getName());
        ConsoleService::discardInput();
        return;
    }

    int id = ConsoleService::readData<int>();
    CustomString password = ConsoleService::readData<CustomString>();
    for (size_t i = 0; i < supermarket->getWorkersList().getSize(); i++) {
        Worker* worker = supermarket->getWorkersList()[i];
        if (worker->getId() == id && worker->getPassword() == password) {
            loggedUser = worker;
            ConsoleService::printLine("Login successful! Welcome " + worker->getName() + " " + worker->getLastName());
            return;
        }
    }
}

void CommonCommands::approveCashier(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to approve cashiers.");
        return;
    }

    if (supermarket->getPendingList().isEmpty()) {
        ConsoleService::printLine("No pending cashiers to approve.");
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