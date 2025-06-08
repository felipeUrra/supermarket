// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "worker.h"

Worker::Worker(IdGenerator* idGenerator, Role role) :
    role(role),
    id(idGenerator->getWorkerId()),
    name(""),
    lastName(""),
    age(0),
    phoneNumber(0),
    password("") {};

Worker::Worker(IdGenerator* idGenerator, Role role, const CustomString& name, const CustomString& lastName,int age, int phoneNumber, const CustomString& password) :
    role(role),
    id(idGenerator->getWorkerId()),
    name(name),
    lastName(lastName),
    age(age),
    phoneNumber(phoneNumber),
    password(password) {}

Worker::~Worker() {}

// Getters and setters
Role Worker::getRole() const {return this->role;}
int Worker::getId() const {return this->id;}
const CustomString& Worker::getName() const {return this->name;}
const CustomString& Worker::getLastName() const {return this->lastName;}
int Worker::getAge() const {return this->age;}
int Worker::getPhoneNumber() const {return this->phoneNumber;}
const CustomString& Worker::getPassword() const {return this->password;}

void Worker::setName(const CustomString& name) {this->name = name;}
void Worker::setLastName(const CustomString& lastName) {this->lastName = lastName;}
void Worker::setAge(int age) {this->age = age;}
void Worker::setPhoneNumber(int telephoneNumber) {this->phoneNumber = telephoneNumber;}
void Worker::setPassword(const CustomString& password) {this->password = password;}


const CustomString Worker::getRoleAsString() const {
    if (this->role == Role::Manager) {return "Manager";}
    return "Cashier";
}