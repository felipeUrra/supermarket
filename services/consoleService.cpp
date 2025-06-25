// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "consoleService.h"
#include "../utils/utils.h"
#include "../commands/managerCommands.h"
#include "../commands/cashierCommands.h"
#include "../products/productByUnit.h"
#include "../products/productByWeight.h"

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
        ConsoleService::printLine("");
    } else if (cmd == "list-workers") {
        CommonCommands::listWorkers(supermarket);
    } else if (cmd == "list-products") {
        CommonCommands::listProducts(supermarket);
    } else if (cmd == "list-products-by-category") {
        CommonCommands::listProductsByCategory(supermarket);
    } else if (cmd == "list-transactions") {
        CommonCommands::listTransactions(supermarket);
    } else if (cmd == "list-feed") {
        CommonCommands::listFeed(supermarket);
    } else if (cmd == "leave") {
        CommonCommands::leave(supermarket, loggedUser);
    } else if (cmd == "approve") {
        ManagerCommands::approveCashier(supermarket, loggedUser);
    } else if (cmd == "add-category") {
        ManagerCommands::addCategory(supermarket, loggedUser);
    } else if (cmd == "decline") {
        ManagerCommands::declineCashier(supermarket, loggedUser);
    } else if (cmd == "list-pending") {
        ManagerCommands::listPending(supermarket, loggedUser);
    } else if (cmd == "list-warned-cashiers") {
        ManagerCommands::listWarnedCashier(supermarket, loggedUser);
    } else if (cmd == "warn-cashier") {
        ManagerCommands::warnCashier(supermarket, loggedUser);
    } else if (cmd == "fire-cashier") {
        ManagerCommands::fireCashier(supermarket, loggedUser);
    } else if (cmd == "promote-cashier") {
        ManagerCommands::promoteCashier(supermarket, loggedUser);
    } else if (cmd == "load-gift-cards") {
        ManagerCommands::loadGiftCards(supermarket, loggedUser);
    } else if (cmd == "load-products") {
        ManagerCommands::loadProducts(supermarket, loggedUser);
    } else if (cmd == "add-product") {
        ManagerCommands::addProduct(supermarket, loggedUser);
    } else if (cmd == "delete-category") {
        ManagerCommands::deleteCategory(supermarket, loggedUser);
    } else if (cmd == "delete-product") {
        ManagerCommands::deleteProduct(supermarket, loggedUser);
    } else if (cmd == "sell") {
        CashierCommands::sell(supermarket, loggedUser);
    }
    else {
        ConsoleService::printLine("Unknown command: " + cmd);
        ConsoleService::printLine("Please try again.\n");
        ConsoleService::discardInput();
    }
}

void ConsoleService::printLine(const CustomString& str) {
    std::cout << str << std::endl;
}

void ConsoleService::print(const CustomString& str) {
    std::cout << str;
}

void ConsoleService::discardInput() {
    std::cin.ignore(10000, '\n');
}

void ConsoleService::printProductsList(Supermarket* supermarket) {
    if (supermarket->getProductsList().isEmpty()) {
        ConsoleService::printLine("No products available for sale.");
        return;
    }
    ConsoleService::printLine("Products:");
    for (int i = 0; i < supermarket->getProductsList().getSize(); i++) {
        Product* product = supermarket->getProductsList()[i];

        if (auto* byUnit = dynamic_cast<ProductByUnit*>(product)) {
            std::cout << (i + 1) << ". " << product->getName() << " : "
                    << byUnit->getPrice() << " : " << byUnit->getAvailableAmount() << "\n";
        } else if (auto* byWeight = dynamic_cast<ProductByWeight*>(product)) {
            std::cout << (i + 1) << ". " << product->getName() << " : "
                    << byWeight->getPrice() << "/kg : " << byWeight->getAvailableKg() << "\n";
        }
    }
}