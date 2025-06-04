// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#pragma once
#include "workers/worker.h"

class Feed {
private:
    Worker* author;
    CustomString description;
    CustomString date;
    CustomString time;

    void setActualDateAndTime(); // maybe put it in a class for Utils

public:
    Feed();
    Feed(Worker* author, const CustomString& description);
    ~Feed() = default;

    //getters and setters
    Worker* getAuthor();
    const CustomString& getDescription() const;
    const CustomString& getDate() const;
    const CustomString& getTime() const;

    void setWorker(Worker* author);
    void setDescription(const CustomString& description);
};