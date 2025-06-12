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
        ConsoleService::printLine("Manager registered successfully!");
        
        Manager* manager = dynamic_cast<Manager*>(worker);
        ConsoleService::printLine("Special code: " + manager->getSpecialCode());
        //return; la version final tiene que tener este return
    } else if (role == "cashier") {
        worker = new Cashier(IdGenerator::getInstance(), firstName, lastName, age, phoneNumber, password);
        // adding the cashier to the pending list in supermarket
        supermarket->addCashier((Cashier*)worker);
        ConsoleService::printLine("Cashier registration pending approval from a manager.");
        return;
    }
    // quitar esto para version final
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

void CommonCommands::logout(Supermarket* supermarket, Worker*& loggedUser) {
    if (loggedUser == nullptr) {
        ConsoleService::printLine("Nobody is logged!");
        ConsoleService::discardInput();
        return;
    }

    loggedUser = nullptr;
}

void CommonCommands::listUserData(Supermarket* supermarket, Worker* loggedUser) {

    if (loggedUser != nullptr) {
        ConsoleService::printLine(loggedUser->getRoleAsString() + ": "
            + loggedUser->getName() + " " + loggedUser->getLastName()
            + " ID: " + CustomString::valueOf(loggedUser->getId()) + " phone number: " + loggedUser->getPhoneNumber()
            + " password: " + loggedUser->getPassword());
        
        return;
    }

    ConsoleService::printLine("There is no user logged!");
}