// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "commonCommands.h"
#include "../services/consoleService.h"
#include "../services/fileService.h"
#include "../utils/utils.h"
#include "../utils/idGenerator.h"
#include "../utils/randomNumberGenerator.h"
#include "../products/productByUnit.h"
#include "../products/productByWeight.h"
#include "../workers/worker.h"
#include "../workers/manager.h"
#include "../workers/cashier.h"
#include <iostream>

void CommonCommands::registerUser(Supermarket* supermarket) {
    CustomString role = ConsoleService::readData<CustomString>();
	if (role != "manager" && role != "cashier") {
		ConsoleService::printLine("Invalid role\n");
        ConsoleService::discardInput();
        return;
	}
    CustomString firstName = ConsoleService::readData<CustomString>();
    CustomString lastName = ConsoleService::readData<CustomString>();
    CustomString phoneNumber = ConsoleService::readData<CustomString>();
    if (!Utils::isValidPhoneNumber(phoneNumber)) {
		ConsoleService::printLine("Invalid phone number\n");
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
        FileService::createSpecialCodeFile(manager->getId(), manager->getSpecialCode());
        return;
    } else if (role == "cashier") {
        worker = new Cashier(IdGenerator::getInstance(), firstName, lastName, age, phoneNumber, password);
        // adding the cashier to the pending list in supermarket

        supermarket->addCashier((Cashier*)worker);
        ConsoleService::printLine("Cashier registration pending approval from a manager.\n");
        return;
    }
}

void CommonCommands::login(Supermarket* supermarket, Worker*& loggedUser) {
    if (loggedUser != nullptr) {
        ConsoleService::printLine("You are already logged in as " + loggedUser->getName() + "\n");
        ConsoleService::discardInput();
        return;
    }

    int id = ConsoleService::readData<int>();
    CustomString password = ConsoleService::readData<CustomString>();
    for (int i = 0; i < supermarket->getWorkersList().getSize(); i++) {
        Worker* worker = supermarket->getWorkersList()[i];
        if (worker->getId() == id && worker->getPassword() == password) {
            loggedUser = worker;
            ConsoleService::printLine("Login successful! Welcome " + worker->getName() + " " + worker->getLastName() + "\n");
            return;
        }
    }
}

void CommonCommands::logout(Supermarket* supermarket, Worker*& loggedUser) {
    if (loggedUser == nullptr) {
        ConsoleService::printLine("Nobody is logged!\n");
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
            + " password: " + loggedUser->getPassword() + "\n");
        
        return;
    }

    ConsoleService::printLine("There is no user logged!\n");
}

void CommonCommands::listWorkers(Supermarket* supermarket) {
    if (supermarket->getWorkersList().getSize() == 0) {
        ConsoleService::printLine("There are no workers!\n");
        return;
    }
    
    for (int i = 0; i < supermarket->getWorkersList().getSize(); i++) {
        Worker* w = supermarket->getWorkersList()[i];

        ConsoleService::printLine(w->getRoleAsString() + ": "
            + w->getName() + " " + w->getLastName()
            + " ID: " + CustomString::valueOf(w->getId()) + " phone number: " + w->getPhoneNumber()
            + " password: " + w->getPassword());
        
    }
    ConsoleService::printLine("");
}

void CommonCommands::listProducts(Supermarket* supermarket) {
    if (supermarket->getProductsList().getSize() == 0) {
        ConsoleService::printLine("There are no products!\n");
        return;
    }

    for (int i = 0; i < supermarket->getProductsList().getSize(); i++) {
        Product* p = supermarket->getProductsList()[i];

        if (p->getType() == ProductType::ByWeight) {
            ProductByWeight* bw = (ProductByWeight*)p;
            std::cout << bw->getName() << " - " << bw->getPrice() << "/kg - " << bw->getAvailableKg() << "\n";
            continue;
        }
        
        ProductByUnit* bu = (ProductByUnit*)p; 
        std::cout << bu->getName() << " - " << bu->getPrice() << " - " << bu->getAvailableAmount() << "\n";
    }

    ConsoleService::printLine("");
}

void CommonCommands::listProductsByCategory(Supermarket* supermarket) {
    int categoryId;
    categoryId = ConsoleService::readData<int>();

    if (supermarket->getProductsList().getSize() == 0) {
        ConsoleService::printLine("There are no products!\n");
        return;
    }

    for (int i = 0; i < supermarket->getProductsList().getSize(); i++) {
        Product* p = supermarket->getProductsList()[i];
        Category* c = supermarket->getCategoryById(categoryId);
        
        if (c == nullptr) {
            ConsoleService::printLine("That category doesn't exist!");
            return;
        }

        if (p->getCategoryName() == c->getName()) {
            if (p->getType() == ProductType::ByWeight) {
                ProductByWeight* bw = (ProductByWeight*)p;
                std::cout << bw->getName() << " - " << bw->getPrice() << "/kg - " << bw->getAvailableKg() << "\n";
                continue;
            }
        
            ProductByUnit* bu = (ProductByUnit*)p;
            std::cout << bu->getName() << " - " << bu->getPrice() << " - " << bu->getAvailableAmount();
        }
    }

    ConsoleService::printLine("");
}

void CommonCommands::listTransactions(Supermarket* supermarket) {
    if (supermarket->getTransactionsList().getSize() == 0) {
        ConsoleService::printLine("There are no transactions!\n");
    }
    
    for (int i = 0; i < supermarket->getTransactionsList().getSize(); i++) {
        Transaction* t = supermarket->getTransactionsList()[i];

        std::cout << "Transaction ID: " << t->getId()
                << " Cashier ID: " << t->getCashierId() << "\n"
                << "Date: " << t->getDate() << " Time: " << t->getTime() << "\n";

        for (int j = 0; j < t->getProductsName().getSize(); j++) {
            std::cout << t->getProductsName()[j] << " - ";

            if (supermarket->getProductByName(t->getProductsName()[j])->getType() == ProductType::ByWeight) {
                std::cout << t->getPrices()[j] << "lv/kg - "
                        << t->getQuantities()[j] << "\n";
                
                continue;
            }

            std::cout << t->getPrices()[j] << " - " << t->getQuantities()[j] << "\n";
        }
        
    }

    ConsoleService::printLine("");
}

void CommonCommands::listFeed(Supermarket* supermarket) {
    if (supermarket->getFeedList().getSize() == 0) {
        ConsoleService::printLine("There are no feed!\n");
    }
    
    for (int i = 0; i < supermarket->getFeedList().getSize(); i++) {
        Feed* f = supermarket->getFeedList()[i];

        ConsoleService::printLine(f->getDate() + " - " + f->getTime() + ": "
                + f->getDescription() + " by " + f->getAuthorName() + " " + f->getAuthorName());
    }
    
    ConsoleService::printLine("");
}

void CommonCommands::leave(Supermarket* supermarket) {return;}

void CommonCommands::exit(bool& exit) {
    ConsoleService::printLine("Exiting the program...");
    exit = true;
}