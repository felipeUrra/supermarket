// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "feed.h"
#include <ctime>

Feed::Feed() : description("") {
    setActualDateAndTime();
}

Feed::Feed(Worker* author, const CustomString& description) :
    author(author),
    description(description)
    {
        setActualDateAndTime();
    }


void Feed::setActualDateAndTime() {
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
Worker* Feed::getAuthor() {return this->author;}
const CustomString& Feed::getDescription() const {return this->description;}
const CustomString& Feed::getDate() const {return this->date;}
const CustomString& Feed::getTime() const {return this->time;}

void Feed::setWorker(Worker* author) {this->author = author;}
void Feed::setDescription(const CustomString& description) {this->description = description;}