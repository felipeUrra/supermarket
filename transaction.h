// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "workers/cashier.h"

class Transaction {
private:
    static int nextId;

    Cashier* cashier;
    double total;
    CustomString date;
    CustomString time;
    int id;

    void setActualDateAndTime(); // maybe put it in a class for Utils

public:
    Transaction();
    Transaction(Cashier* cashier, double total);
    ~Transaction() = default;

    //getters and setters
    Cashier* getCashier();
    double getTotal() const;
    const CustomString& getDate() const;
    const CustomString& getTime() const;
    int getId() const;

    void setCashier(Cashier* cashier);
    void setTotal(double total);
};