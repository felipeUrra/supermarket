// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "fileService.h"
#include "consoleService.h"
#include <iostream>
#include <fstream>

void FileService::createReceipt(Transaction* transaction) {
    CustomString str = "receipt_" + CustomString::valueOf(transaction->getId());
    str += ".txt";

    const char* filename = str.c_str();

    std::ofstream receipt(filename);

    if (!receipt.is_open()) {
        std::cerr << "It was not possible to open the file" << std::endl;
        return;
    }
    
    receipt << "RECEIPT" << std::endl;
    receipt << "TRANSACTION_ID:" << transaction->getId() << std::endl;
    receipt << "CASHIER_ID:" << transaction->getCashierId() << std::endl;
    receipt << transaction->getDate() << " " << transaction->getTime() << std::endl;
    receipt << '\n';
    for (int i = 0; i < transaction->getProductsName().getSize(); i++) {
        receipt << transaction->getProductsName()[i] << std::endl;
        receipt << transaction->getQuantities()[i] << "*" << transaction->getPrices()[i]
                << " - "
                << (transaction->getQuantities()[i] * transaction->getPrices()[i]) << std::endl;
        receipt << "###" << std::endl;
    }
    
    receipt << "TOTAL:" << transaction->getTotal();
    receipt.close();

    ConsoleService::printLine("Receipt saved as: " + str);
}

void FileService::createSpecialCodeFile(int id, const CustomString& code) {
    CustomString str = CustomString::valueOf(id) + "_special_code.txt";
    const char* filename = str.c_str();

    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "It was not possible to open the file" << std::endl;
        return;
    }

    file << code;
    file.close();

    ConsoleService::printLine("Code: " + str + '\n');
}