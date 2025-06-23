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
#include "../giftCards/singleCategoryGiftCard.h"
#include "../giftCards/multipleCategoryGiftCard.h"
#include "../giftCards/allProductsGiftCard.h"
#include "../products/productByUnit.h"
#include "../products/productByWeight.h"

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

    for (int i = 0; i < supermarket->getPendingList().getSize(); i++) {
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

void ManagerCommands::declineCashier(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add categories.");
        ConsoleService::discardInput();
        return;
    }

    if (supermarket->getPendingList().isEmpty()) {
        ConsoleService::printLine("No pending cashiers to decline.");
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

    for (int i = 0; i < supermarket->getPendingList().getSize(); i++) {
        Cashier* cashier = supermarket->getPendingList()[i];
        if (cashier->getId() == idCashier) {
            supermarket->getPendingList().remove(i);
            ConsoleService::printLine("Cashier declined successfully!");
            return;
        }
    }
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

void ManagerCommands::listPending(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add categories.");
        ConsoleService::discardInput();
        return;
    }

    if (supermarket->getPendingList().isEmpty()) {
        ConsoleService::printLine("No pending cashiers.");
        ConsoleService::discardInput();
        return;
    }

    for (int i = 0; i < supermarket->getPendingList().getSize(); i++) {
        ConsoleService::printLine(supermarket->getPendingList()[i]->getRoleAsString() + ": "
        + supermarket->getPendingList()[i]->getName()
        + " " + supermarket->getPendingList()[i]->getLastName()
        + " ID: " + CustomString::valueOf(supermarket->getPendingList()[i]->getId())
        + " phone number: " + supermarket->getPendingList()[i]->getPhoneNumber()
        + " password: " + supermarket->getPendingList()[i]->getPassword());
    }
}

void ManagerCommands::loadGiftCards(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to load gift cards.");
        ConsoleService::discardInput();
        return;
    }

    // load gift cards from a text file
    CustomString fileName = ConsoleService::readData<CustomString>();
    std::ifstream file(fileName.c_str());
    if (!file.is_open()) {
        ConsoleService::printLine("Could not open file: " + fileName);
        return;
    }
    // format per line in the file <gift card type>:<category name>:<percentage discount>
    char* line = new char[1024];

    while (file.getline(line, 1024)) {
        CustomString lineStr = line;
        CustomVector<CustomString> data = lineStr.split(':');
        if (data.getSize() < 2) {
            ConsoleService::printLine("Invalid format for gift card: " + lineStr);
            continue;
        }
        CustomString giftCardType = data[0];
        GiftCardType giftCardTypeEnum;
        CustomString category;
        double percentage = 0.0;

        if (giftCardType == "GIFT_CARD_TYPE_1") {
            giftCardTypeEnum = GiftCardType::SingleCategory;
            category = data[1];
            percentage = data[2].toDouble();
            if (percentage < 0 || percentage > 100) {
                ConsoleService::printLine("Invalid percentage: " + lineStr);
                continue;
            }
            GiftCard* newGiftCard = new SingleCategoryGiftCard(RandomNumberGenerator::getInstance(), IdGenerator::getInstance(), percentage, category);
            supermarket->getGiftCardsList().push_back(newGiftCard);
        } else if (giftCardType == "GIFT_CARD_TYPE_2") {
            giftCardTypeEnum = GiftCardType::MultipleCategories;
            // for multiple categories, we can assume the format is <count>:<category1>:<category2>:...:<percentage>
            if (data.getSize() < 3) {
                ConsoleService::printLine("Invalid format for multiple categories gift card: " + lineStr);
                continue;
            }
            int count = data[1].toInt();
            if (count < 1 || count + 3 != data.getSize()) {
                ConsoleService::printLine("Invalid count for multiple categories gift card: " + lineStr);
                continue;
            }
            CustomVector<CustomString> categories;
            for (int i = 2; i <= count + 1; i++) {
                categories.push_back(data[i]);
            }
            percentage = data[count + 2].toDouble();
            if (percentage < 0 || percentage > 100) {
                ConsoleService::printLine("Invalid percentage: " + lineStr);
                continue;
            }
            GiftCard* newGiftCard = new MultipleCategoryGiftCard(RandomNumberGenerator::getInstance(), IdGenerator::getInstance(), percentage, categories);
            supermarket->getGiftCardsList().push_back(newGiftCard);
        } else if (giftCardType == "GIFT_CARD_TYPE_3") {
            // All products gift card format <gift card type>:<percentage discount>
            giftCardTypeEnum = GiftCardType::AllProducts;
            if (data.getSize() != 2) {
                ConsoleService::printLine("Invalid format for all products gift card: " + lineStr);
                continue;
            }
            percentage = data[1].toDouble();
            if (percentage < 0 || percentage > 100) {
                ConsoleService::printLine("Invalid percentage: " + lineStr);
                continue;
            }
            GiftCard* newGiftCard = new AllProductsGiftCard(RandomNumberGenerator::getInstance(), IdGenerator::getInstance(), percentage);
            supermarket->getGiftCardsList().push_back(newGiftCard);
        } else {
            ConsoleService::printLine("Unknown gift card type: " + giftCardType);
            continue;
        }
    }

}

bool ManagerCommands::getProductCommonData(Supermarket* supermarket, Product* product) {
    ConsoleService::printLine("Enter product name: ");
    CustomString productName = ConsoleService::readData<CustomString>();
    if (productName.isEmpty()) {
        ConsoleService::printLine("Product name cannot be empty.");
        return false;
    }
    ConsoleService::printLine("Enter product category: ");
    CustomString categoryName = ConsoleService::readData<CustomString>();
    if (categoryName.isEmpty()) {
        ConsoleService::printLine("Category name cannot be empty.");
        return false;
    }
    Category* category = supermarket->getCategoryByName(categoryName);
    if (category == nullptr) {
        ConsoleService::printLine("Category \"" + categoryName + "\" does not exist.");
        return false;
    }
    product->setName(productName);
    product->setCategoryName(category->getName());
    return true;
}

/*
Add product, here is an example of how it should show to the user:
> add-product product_by_unit
  Enter product name: eggs
  Enter product category: Dairy
  Enter price per unit: 2.5
  Enter quantity (units): 12
  Product "eggs" added successfully under category "Dairy"
*/
void ManagerCommands::addProductByUnit(Supermarket* supermarket, Worker* loggedUser) {

    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add products.");
        ConsoleService::discardInput();
        return;
    }
    Product* newProduct = new ProductByUnit();
    bool valid = getProductCommonData(supermarket, newProduct);
    if (!valid) {
        delete newProduct;
        return;
    }

    ConsoleService::printLine("Enter price per unit: ");
    double pricePerUnit = ConsoleService::readData<double>();
    if (pricePerUnit <= 0) {
        ConsoleService::printLine("Price per unit must be greater than zero.");
        return;
    }
    ConsoleService::printLine("Enter quantity (units): ");
    int quantity = ConsoleService::readData<int>();
    if (quantity <= 0) {
        ConsoleService::printLine("Quantity must be greater than zero.");
        return;
    }
    ProductByUnit* productByUnit = dynamic_cast<ProductByUnit*>(newProduct);
    if (productByUnit == nullptr) {
        ConsoleService::printLine("Error: Product is not of type ProductByUnit.");
        delete newProduct;
        return;
    }
    productByUnit->setPrice(pricePerUnit);
    productByUnit->setAvailableAmount(quantity);
    supermarket->getProductsList().push_back(newProduct);
    ConsoleService::printLine("Product \"" + newProduct->getName() + "\" added successfully under category \"" + newProduct->getCategoryName() + "\".");
}

void ManagerCommands::addProductByWeight(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add products.");
        ConsoleService::discardInput();
        return;
    }
    Product* newProduct = new ProductByWeight();
    bool valid = getProductCommonData(supermarket, newProduct);
    if (!valid) {
        delete newProduct;
        return;
    }

    ConsoleService::printLine("Enter price per kilogram: ");
    double pricePerKg = ConsoleService::readData<double>();
    if (pricePerKg <= 0) {
        ConsoleService::printLine("Price per kilogram must be greater than zero.");
        return;
    }
    ConsoleService::printLine("Enter quantity (kilograms): ");
    int quantity = ConsoleService::readData<int>();
    if (quantity <= 0) {
        ConsoleService::printLine("Quantity must be greater than zero.");
        return;
    }
    ProductByWeight* productByWeight = dynamic_cast<ProductByWeight*>(newProduct);
    if (productByWeight == nullptr) {
        ConsoleService::printLine("Error: Product is not of type ProductByWeight.");
        delete newProduct;
        return;
    }
    productByWeight->setAvailableKg(quantity);
    productByWeight->setPrice(pricePerKg);
    supermarket->getProductsList().push_back(newProduct);
    ConsoleService::printLine("Product \"" + newProduct->getName() + "\" added successfully under category \"" + newProduct->getCategoryName() + "\".");
}

void ManagerCommands::addProduct(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add products.");
        ConsoleService::discardInput();
        return;
    }

    CustomString productType = ConsoleService::readData<CustomString>();
    if (productType == "product_by_unit") {
        addProductByUnit(supermarket, loggedUser);
    } else if (productType == "product_by_weight") {
        addProductByWeight(supermarket, loggedUser);
    } else {
        ConsoleService::printLine("Unknown product type: " + productType);
        ConsoleService::discardInput();
    }
}