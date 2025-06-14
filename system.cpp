// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "system.h"
#include "services/consoleService.h"
#include "utils/utils.h"

System::System() : loggedUser(nullptr), exit(false) {
    this->supermarket = new Supermarket();
}

Supermarket* System::getSupermarket() {return this->supermarket;}
Worker* System::getLoggedUser() {return this->loggedUser;}
bool System::getExit() const {return this->exit;}

void System::setSupermarket(Supermarket* supermarket) {this->supermarket = supermarket;}
void System::setLoggedUser(Worker* loggedUser) {this->loggedUser = loggedUser;}
void System::setExit(bool val) {this->exit = val;}

// Serialize-deserialize
void System::serialize(std::ofstream& out) const {this->supermarket->serialize(out);}

void System::deserialize(std::ifstream& in) {this->supermarket->deserialize(in);}


void System::run() {
    ConsoleService::printLine("Welcome to FMI Supermarket Management System 2024-2025!");
    Utils::loadSystemState(*this, "systemData.bin");

    do {
        std::cout << "> ";
        ConsoleService::detectCommand(this->loggedUser, this->supermarket, this->exit);
    } while (!this->exit);

    Utils::saveSystemState(*this, "systemData.bin");
}