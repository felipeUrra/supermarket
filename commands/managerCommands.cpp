// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "managerCommands.h"
#include "../services/consoleService.h"
#include "../services/fileService.h"
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
        ConsoleService::printLine("You must be logged in as a manager to approve cashiers.\n");
        ConsoleService::discardInput();
        return;
    }

    if (supermarket->getPendingList().isEmpty()) {
        ConsoleService::printLine("No pending cashiers to approve.\n");
        ConsoleService::discardInput();
        return;
    }

    int idCashier = ConsoleService::readData<int>();
    CustomString specialCode = ConsoleService::readData<CustomString>();
    
    Manager* manager = dynamic_cast<Manager*>(loggedUser);
    if (!manager || specialCode != manager->getSpecialCode()) {
        ConsoleService::printLine("Invalid special code. You cannot approve cashiers.\n");
        return;
    }

    for (int i = 0; i < supermarket->getPendingList().getSize(); i++) {
        Cashier* cashier = supermarket->getPendingList()[i];
        if (cashier->getId() == idCashier) {
            supermarket->addWorker(cashier);
            supermarket->getPendingList().remove(i);
            ConsoleService::printLine("Cashier approved successfully!\n");

            Utils::createFeed(supermarket, loggedUser, "Approve cashier");
            return;
        }
    }
    ConsoleService::printLine("Cashier not found in pending list.\n");
}

void ManagerCommands::declineCashier(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to decline cashiers.\n");
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
        ConsoleService::printLine("You must be logged in as a manager to add categories.\n");
        ConsoleService::discardInput();
        return;
    }

    const CustomString categoryName = ConsoleService::readData<CustomString>();
    const CustomString description = ConsoleService::readData<CustomString>();
    if (categoryName == "") {
        ConsoleService::printLine("Category name cannot be empty.\n");
        return;
    }

    if (supermarket->getCategoryByName(categoryName) != nullptr) {
        ConsoleService::printLine("There is already a category with that name\n");
        return;
    }

    Category* newCategory = new Category(IdGenerator::getInstance(), categoryName, description);
    supermarket->addCategory(newCategory);
    ConsoleService::printLine("Category \"" + categoryName + "\" added successfully!\n");
}

void ManagerCommands::listPending(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add categories.\n");
        ConsoleService::discardInput();
        return;
    }

    if (supermarket->getPendingList().isEmpty()) {
        ConsoleService::printLine("No pending cashiers.\n");
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

    ConsoleService::printLine("");
}

void ManagerCommands::listWarnedCashier(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add categories.\n");
        ConsoleService::discardInput();
        return;
    }

    int points = ConsoleService::readData<int>();
    if(points != 100 && points != 200 && points != 300) {
        ConsoleService::printLine("The warning points are 100, 200 or 300");
        return;
    }

    for (int i = 0; i < supermarket->getWorkersList().getSize(); i++) {
        Worker* w = supermarket->getWorkersList()[i];
        if (w->getRole() == Role::Cashier) {
            Cashier* c = (Cashier*)w;
            for (int j = 0; j < c->getWarnings().getSize(); j++) {
                if ((int)c->getWarnings()[j]->getWarningGrade() > points) {
                    CommonCommands::listUserData(supermarket, c);
                    break;
                }
            } 
        }
    }
    ConsoleService::printLine("");
}

void ManagerCommands::warnCashier(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add categories.\n");
        ConsoleService::discardInput();
        return;
    }

    int cashierId = ConsoleService::readData<int>();
    int points = ConsoleService::readData<int>();
    CustomString description = ConsoleService::readWords();

    Worker* w = supermarket->getWorkerById(cashierId);
    if (w == nullptr || w->getRole() != Role::Cashier) {
        ConsoleService::printLine("That id isn't of a cashier!\n");
        return;
    }

    Cashier* c = (Cashier*)w;
    
    if(points != 100 && points != 200 && points != 300) {
        ConsoleService::printLine("The warning points are 100, 200 or 300");
        return;
    }

    Warning* warning = new Warning(loggedUser->getId(), description, (WarningGrade)points);
    c->getWarnings().push_back(warning);
    ConsoleService::printLine("");

    Utils::createFeed(supermarket, loggedUser, "Warn cashier");
}

void ManagerCommands::fireCashier(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add categories.\n");
        ConsoleService::discardInput();
        return;
    }

    int cashierId = ConsoleService::readData<int>();
    CustomString specialCode = ConsoleService::readData<CustomString>();

    Manager* manager = dynamic_cast<Manager*>(loggedUser);
    if (!manager || specialCode != manager->getSpecialCode()) {
        ConsoleService::printLine("Invalid special code. You cannot approve cashiers.\n");
        return;
    }

    for (int i = 0; i < supermarket->getWorkersList().getSize(); i++) {
        Worker* w = supermarket->getWorkersList()[i];

        if (w->getRole() == Role::Cashier && w->getId() == cashierId) {
            Cashier* c = (Cashier*)w;
            delete c;
            supermarket->getWorkersList().remove(i);
            ConsoleService::printLine("Cashier fired successfully.\n");
            
            Utils::createFeed(supermarket, loggedUser, "Fire cashier");
            return;
        }
    }
    
    ConsoleService::printLine("There is no cashier with that id!\n");
}

void ManagerCommands::promoteCashier(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add categories.\n");
        ConsoleService::discardInput();
        return;
    }

    int cashierId = ConsoleService::readData<int>();
    CustomString specialCode = ConsoleService::readData<CustomString>();

    Manager* manager = dynamic_cast<Manager*>(loggedUser);
    if (!manager || specialCode != manager->getSpecialCode()) {
        ConsoleService::printLine("Invalid special code. You cannot approve cashiers.\n");
        return;
    }

    for (int i = 0; i < supermarket->getWorkersList().getSize(); i++) {
        Worker* w = supermarket->getWorkersList()[i];
        if (w->getRole() == Role::Cashier) {
            Cashier* c = (Cashier*)w;
            Manager* m = new Manager(IdGenerator::getInstance(), RandomNumberGenerator::getInstance());
            m->setId(c->getId());
            m->setName(c->getName());
            m->setLastName(c->getLastName());
            m->setAge(c->getAge());
            m->setPhoneNumber(c->getPhoneNumber());
            m->setPassword(c->getPassword());
            FileService::createSpecialCodeFile(m->getId(), m->getSpecialCode());
            std::cout << "Code: " << m->getId() << "_special_code.txt\n\n";

            delete c;
            supermarket->getWorkersList()[i] = m;

            ConsoleService::printLine("Promoted cashier successfully!\n");
            Utils::createFeed(supermarket, loggedUser, "Promote cashier");
            return;
        }
    }
    
    ConsoleService::printLine("There is no cashier with that id!\n");
}

void ManagerCommands::loadGiftCards(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to load gift cards.\n");
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

void ManagerCommands::loadProducts(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to load products.\n");
        ConsoleService::discardInput();
        return;
    }
    CustomString fileName = ConsoleService::readData<CustomString>();
    std::ifstream file(fileName.c_str());
    if (!file.is_open()) {
        ConsoleService::printLine("Could not open file: " + fileName);
        return;
    }
    char* line = new char[1024];
    while (file.getline(line, 1024)) {
        CustomString lineStr = line;
        CustomVector<CustomString> data = lineStr.split(':');
        if (data.getSize() < 2) {
            ConsoleService::printLine("Invalid format for product: " + lineStr);
            continue;
        }
        CustomString first = data[0];
        if (first == "NEW") {
            if (data.getSize() != 6) {
                ConsoleService::printLine("Invalid format for new product: " + lineStr);
                continue;
            }
            CustomString productType = data[1];
            CustomString productName = data[2];
            CustomString categoryName = data[3];
            double price = data[4].toDouble();
            double quantity = data[5].toDouble();
            if (price <= 0) {
                ConsoleService::printLine("Price and quantity must be greater than zero: " + lineStr);
                continue;
            }
            // check if the category exists
            Category* category = supermarket->getCategoryByName(categoryName);
            if (category == nullptr) {
                ConsoleService::printLine("Category \"" + categoryName + "\" does not exist. Product not added.");
                continue;
            }
            Product* newProduct = nullptr;
            if (productType == "product_by_unit" || productType == "PRODUCT_BY_UNIT") {
                newProduct = new ProductByUnit(productName, categoryName, price, quantity);
            } else if (productType == "product_by_weight" || productType == "PRODUCT_BY_WEIGHT") {
                newProduct = new ProductByWeight(productName, categoryName, price, quantity);
            } else {
                ConsoleService::printLine("Unknown product type: " + data[5]);
                continue;
            }
            // check if the product already exists
            if (supermarket->getProductByName(productName) != nullptr) {
                ConsoleService::printLine("Product with name " + productName + " already exists.");
                continue;
            }
            supermarket->getProductsList().push_back(newProduct);
            ConsoleService::printLine("Added new product: " + productName + " under category: " + categoryName);
        } else {
            CustomString productName = data[1];
            Product* existingProduct = supermarket->getProductByName(productName);
            if (existingProduct == nullptr) {
                ConsoleService::printLine("Product with ID " + productName + " not found.");
                continue;
            }
            CustomString productType = data[0];
            // if the entered product type is not the same as the existing product type, show an error
            if ((productType == "product_by_unit" || productType == "PRODUCT_BY_UNIT") && 
                dynamic_cast<ProductByUnit*>(existingProduct) == nullptr) {
                ConsoleService::printLine("Product type mismatch for product: " + productName);
                continue;
            } else if ((productType == "product_by_weight" || productType == "PRODUCT_BY_WEIGHT") && 
                       dynamic_cast<ProductByWeight*>(existingProduct) == nullptr) {
                ConsoleService::printLine("Product type mismatch for product: " + productName);
                continue;
            }

            double quantityToAdd = data[2].toDouble();
            if (quantityToAdd <= 0) {
                ConsoleService::printLine("Quantity must be greater than zero: " + lineStr);
                continue;
            }
            if (auto* byUnitProduct = dynamic_cast<ProductByUnit*>(existingProduct)) {
                byUnitProduct->setAvailableAmount(byUnitProduct->getAvailableAmount() + quantityToAdd);
            } else if (auto* byWeightProduct = dynamic_cast<ProductByWeight*>(existingProduct)) {
                byWeightProduct->setAvailableKg(byWeightProduct->getAvailableKg() + quantityToAdd);
            } else {
                ConsoleService::printLine("Unknown product type for product: " + productName);
                continue;
            }
            ConsoleService::printLine("Updated product: " + productName + " with additional quantity: " + CustomString::valueOf(quantityToAdd));
        }
    }
}

bool ManagerCommands::getProductCommonData(Supermarket* supermarket, Product* product) {
    ConsoleService::printLine("Enter product name: ");
    CustomString productName = ConsoleService::readData<CustomString>();
    if (productName.isEmpty()) {
        ConsoleService::printLine("Product's name cannot be empty.\n");
        return false;
    } else if (supermarket->getProductByName(productName) != nullptr) {
        ConsoleService::printLine("Product's name must be unique.\n");
    }
    ConsoleService::printLine("Enter product category: ");
    CustomString categoryName = ConsoleService::readData<CustomString>();
    if (categoryName.isEmpty()) {
        ConsoleService::printLine("Category name cannot be empty.\n");
        return false;
    }
    Category* category = supermarket->getCategoryByName(categoryName);
    if (category == nullptr) {
        ConsoleService::printLine("Category \"" + categoryName + "\" does not exist.\n");
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
        ConsoleService::printLine("You must be logged in as a manager to add products.\n");
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
        ConsoleService::printLine("Price per unit must be greater than zero.\n");
        return;
    }
    ConsoleService::printLine("Enter quantity (units): ");
    int quantity = ConsoleService::readData<int>();
    if (quantity <= 0) {
        ConsoleService::printLine("Quantity must be greater than zero.\n");
        return;
    }
    ProductByUnit* productByUnit = dynamic_cast<ProductByUnit*>(newProduct);
    if (productByUnit == nullptr) {
        ConsoleService::printLine("Error: Product is not of type ProductByUnit.\n");
        delete newProduct;
        return;
    }
    productByUnit->setPrice(pricePerUnit);
    productByUnit->setAvailableAmount(quantity);
    supermarket->getProductsList().push_back(newProduct);
    ConsoleService::printLine("Product \"" + newProduct->getName() + "\" added successfully under category \"" + newProduct->getCategoryName() + "\".\n");
}

void ManagerCommands::addProductByWeight(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add products.\n");
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
        ConsoleService::printLine("Price per kilogram must be greater than zero.\n");
        return;
    }
    ConsoleService::printLine("Enter quantity (kilograms): ");
    int quantity = ConsoleService::readData<int>();
    if (quantity <= 0) {
        ConsoleService::printLine("Quantity must be greater than zero.\n");
        return;
    }
    ProductByWeight* productByWeight = dynamic_cast<ProductByWeight*>(newProduct);
    if (productByWeight == nullptr) {
        ConsoleService::printLine("Error: Product is not of type ProductByWeight.\n");
        delete newProduct;
        return;
    }
    productByWeight->setAvailableKg(quantity);
    productByWeight->setPrice(pricePerKg);
    supermarket->getProductsList().push_back(newProduct);
    ConsoleService::printLine("Product \"" + newProduct->getName() + "\" added successfully under category \"" + newProduct->getCategoryName() + "\".\n");
}

void ManagerCommands::addProduct(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to add products.\n");
        ConsoleService::discardInput();
        return;
    }

    CustomString productType = ConsoleService::readData<CustomString>();
    if (productType == "product_by_unit") {
        addProductByUnit(supermarket, loggedUser);
    } else if (productType == "product_by_weight") {
        addProductByWeight(supermarket, loggedUser);
    } else {
        ConsoleService::printLine("Unknown product type: " + productType + "\n");
        ConsoleService::discardInput();
    }
}

void ManagerCommands::deleteCategory(Supermarket* supermarket, Worker* loggedUser) {
    
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to delete categories.\n");
        ConsoleService::discardInput();
        return;
    }
    int categoryId = ConsoleService::readData<int>();
    Category* category = supermarket->getCategoryById(categoryId);
    if (category == nullptr) {
        ConsoleService::printLine("Category with id " + CustomString::valueOf(categoryId) + " does not exist.\n");
        return;
    }
    // Check if there are products in the category
    for (int i = 0; i < supermarket->getProductsList().getSize(); i++) {
        if (supermarket->getProductsList()[i]->getCategoryName() == category->getName()) {
            ConsoleService::printLine("Cannot delete category \"" + category->getName() + "\" because it has products associated with it.\n");
            return;
        }
    }
    // Remove the category from the list
    for (int i = 0; i < supermarket->getCategoriesList().getSize(); i++) {
        if (supermarket->getCategoriesList()[i]->getId() == categoryId) {
            delete supermarket->getCategoriesList()[i];
            supermarket->getCategoriesList().remove(i);
            ConsoleService::printLine("Category deleted successfully.\n");
            return;
        }
    }
    return;
}

void ManagerCommands::deleteProduct(Supermarket* supermarket, Worker* loggedUser) {
    if (loggedUser == nullptr || loggedUser->getRole() != Role::Manager) {
        ConsoleService::printLine("You must be logged in as a manager to delete products.\n");
        ConsoleService::discardInput();
        return;
    }
    CustomString productName = ConsoleService::readData<CustomString>();
    Product* product = supermarket->getProductByName(productName);
    if (product == nullptr) {
        ConsoleService::printLine("Product with name \"" + productName + "\" does not exist.\n");
        return;
    }
    // Remove the product from the list
    for (int i = 0; i < supermarket->getProductsList().getSize(); i++) {
        if (supermarket->getProductsList()[i]->getName() == productName) {
            delete supermarket->getProductsList()[i];
            supermarket->getProductsList().remove(i);
            ConsoleService::printLine("Product deleted successfully.\n");
            return;
        }
    }
}