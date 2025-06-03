// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "transaction.h"
#include <ctime>

int Transaction::nextId = 0;

Transaction::Transaction() : total(0), id(nextId++) {
    setActualDateAndTime();
}

Transaction::Transaction(Cashier* cashier, double total) :
    cashier(cashier),
    total(total),
    id(nextId++)
    {
        setActualDateAndTime();
    }


void Transaction::setActualDateAndTime() {
    time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    // date format: DD-MM-YYYY
    char buffDate[11]; // DD-MM-YYYY\0
    std::strftime(buffDate, sizeof(buffDate), "%d.%m.%Y", now);
    this->date = buffDate;

    // time format: HH-MM
    char buffTime[6]; // HH-MM\0
    std::strftime(buffTime, sizeof(buffTime), "%H:%M", now);
    this->time = buffTime;
}


//getters and setters
Cashier* Transaction::getCashier() {return this->cashier;}
double Transaction::getTotal() const {return this->total;}
const CustomString& Transaction::getDate() const {return this->date;}
const CustomString& Transaction::getTime() const {return this->time;}
int Transaction::getId() const {return this->id;}

void Transaction::setCashier(Cashier* cashier) {this->cashier = cashier;}
void Transaction::setTotal(double total) {this->total = total;}