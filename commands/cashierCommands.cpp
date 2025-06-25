// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "cashierCommands.h"
#include "../utils/utils.h"
#include "../services/consoleService.h"
#include "../services/fileService.h"
#include "../products/productByUnit.h"
#include "../products/productByWeight.h"
#include "../transaction.h"
#include "../giftCards/giftCard.h"

void CashierCommands::sell(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() == Role::Manager) {
        ConsoleService::printLine("You must be logged in as a cashier to sell products.");
        ConsoleService::discardInput();
        return;
    }

    Cashier* c = dynamic_cast<Cashier*>(loggedUser);
    c->setTransactionsCount(c->getTransactionsCount() + 1);

    Transaction* transaction = new Transaction(IdGenerator::getInstance());
    supermarket->getTransactionsList().push_back(transaction);

    ConsoleService::printProductsList(supermarket);
    ConsoleService::printLine("");
    ConsoleService::printLine("Transaction ID: " + CustomString::valueOf(transaction->getId()));
    std::cout << "Price: " << transaction->getTotal() << "\n\n";

    CustomString input;
    double quantity;
    do {
        ConsoleService::printLine("Enter product number to sell. Enter END to end the transaction:");
        std::cout << "> ";
        input = ConsoleService::readData<CustomString>();

        if (input == "END") break;
    } while (input.toInt() > supermarket->getProductsList().getSize() || input.toInt() <= 0);

    while (input != "END") {
        ConsoleService::printLine("Enter quantity:");
        std::cout << "> ";
        quantity = ConsoleService::readData<int>();

        Product* p = supermarket->getProductsList()[input.toInt() - 1];
        if (auto* byUnit = dynamic_cast<ProductByUnit*>(p)) {
            quantity = (int)quantity;

            if (quantity > byUnit->getAvailableAmount()) {
                ConsoleService::printLine("Theres isn't enough product!");
            } else {
                byUnit->setAvailableAmount(byUnit->getAvailableAmount() - quantity);

                transaction->setCashierId(c->getId());
                transaction->setTotal(transaction->getTotal() + (byUnit->getPrice() * quantity));
                transaction->getProductsName().push_back(byUnit->getName());
                transaction->getPrices().push_back(byUnit->getPrice());
                transaction->getQuantities().push_back(quantity);
            }
            
        } else if (auto* byWeight = dynamic_cast<ProductByWeight*>(p)) {
            if (quantity > byWeight->getAvailableKg()) {
                ConsoleService::printLine("Theres isn't enough product!");
            } else {
                byWeight->setAvailableKg(byWeight->getAvailableKg() - quantity);

                transaction->setCashierId(c->getId());
                transaction->setTotal(transaction->getTotal() + (byWeight->getPrice() * quantity));
                transaction->getProductsName().push_back(byWeight->getName());
                transaction->getPrices().push_back(byWeight->getPrice());
                transaction->getQuantities().push_back(quantity);
            }
        }

        ConsoleService::printLine("-----------------\n");
        ConsoleService::printProductsList(supermarket);
        ConsoleService::printLine("");
        ConsoleService::printLine("Transaction ID: " + CustomString::valueOf(transaction->getId()));
        std::cout << "Price: " << transaction->getTotal() << "\n\n";

        do {
            ConsoleService::printLine("Enter product number to sell. Enter END to end the transaction:");
            std::cout << "> ";
            input = ConsoleService::readData<CustomString>();
            if (input == "END") break;
        } while (input.toInt() > supermarket->getProductsList().getSize() || input.toInt() <= 0);
    }

    ConsoleService::print("Add voucher: (Y/N) ? ");
    CustomString answer = ConsoleService::readData<CustomString>();

    if (answer == "Y" || answer == "y") {
        ConsoleService::print("Enter voucher: ");
        CustomString voucherCode;

        GiftCard* gc = supermarket->getGiftCarByCode(voucherCode);
        if (gc == nullptr) {
            ConsoleService::printLine("There is no voucher with that id!");
        } else {
            transaction->applyGiftCard(gc, supermarket);
        }
    }
    
    FileService::createReceipt(transaction);
    std::cout << "Total: " << transaction->getTotal() << "lv. \n\n";

    c->removeWarning();
}