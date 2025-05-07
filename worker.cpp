// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "worker.h"

uint8_t Worker::nextWorkerId = 0;

Worker::Worker(uint8_t workerId, const CustomString& name, const CustomString& lastName, uint8_t age, uint8_t telephoneNumber, const CustomString& password) {
    setWorkerId(workerId);
    setName(name);
    setLastName(lastName);
    setAge(age);
    setTelephoneNumber(telephoneNumber);
    setPassword(password);
}

Worker::~Worker() {}

// Getters and setters
void Worker::setWorkerId(uint8_t workerId) {this->workerId = workerId;}
void Worker::setName(const CustomString& name) {this->name = name;}
void Worker::setLastName(const CustomString& lastName) {this->lastName = lastName;}
void Worker::setAge(uint8_t age) {this->age = age;}
void Worker::setTelephoneNumber(uint8_t telephoneNumber) {this->telephoneNumber = telephoneNumber;}
void Worker::setPassword(const CustomString& password) {this->password = password;}

uint8_t Worker::getWorkerId() const {return this->workerId;}
const CustomString& Worker::getName() const {return this->name;}
const CustomString& Worker::getLastName() const {return this->lastName;}
uint8_t Worker::getAge() const {return this->age;}
uint8_t Worker::getTelephoneNumber() const {return this->telephoneNumber;}
const  CustomString& Worker::getPassword() const {return this->password;} // i will have to add all the needed logic to change it after the first time