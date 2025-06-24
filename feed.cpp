// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "feed.h"
#include <ctime>

Feed::Feed() : description("") {
    setActualDateAndTime();
}

Feed::Feed(const CustomString& authorName, const CustomString& authorLastName, const CustomString& description) :
    authorName(authorName),
    authorLastName(authorLastName),
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
const CustomString& Feed::getAuthorName() const {return this->authorName;}
const CustomString& Feed::getAuthorLastName() const {return this->authorLastName;}
const CustomString& Feed::getDescription() const {return this->description;}
const CustomString& Feed::getDate() const {return this->date;}
const CustomString& Feed::getTime() const {return this->time;}

void Feed::setDescription(const CustomString& description) {this->description = description;}

// serialize-deserialize
void Feed::serialize(std::ofstream& out) const {
    this->authorName.serialize(out);
    this->authorLastName.serialize(out);
    this->description.serialize(out);
    this->date.serialize(out);
    this->time.serialize(out);
}

void Feed::deserialize(std::ifstream& in) {
    this->authorName.deserialize(in);
    this->authorLastName.deserialize(in);
    this->description.deserialize(in);
    this->date.deserialize(in);
    this->time.deserialize(in);
}