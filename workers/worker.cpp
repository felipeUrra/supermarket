// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "worker.h"

int Worker::nextId = 0;

Worker::Worker() : id(nextId++), name(""), lastName(""), age(0), telephoneNumber(0), password("") {};

Worker::Worker(const CustomString& name, const CustomString& lastName,int age, int telephoneNumber, const CustomString& password) :
    id(nextId++),
    name(name),
    lastName(lastName),
    age(age),
    telephoneNumber(telephoneNumber),
    password(password) {}

Worker::~Worker() {}

// Getters and setters
int Worker::getId() const {return this->id;}
const CustomString& Worker::getName() const {return this->name;}
const CustomString& Worker::getLastName() const {return this->lastName;}
int Worker::getAge() const {return this->age;}
int Worker::getTelephoneNumber() const {return this->telephoneNumber;}
const CustomString& Worker::getPassword() const {return this->password;}

void Worker::setName(const CustomString& name) {this->name = name;}
void Worker::setLastName(const CustomString& lastName) {this->lastName = lastName;}
void Worker::setAge(int age) {this->age = age;}
void Worker::setTelephoneNumber(int telephoneNumber) {this->telephoneNumber = telephoneNumber;}
void Worker::setPassword(const CustomString& password) {this->password = password;}