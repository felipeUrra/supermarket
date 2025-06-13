// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "worker.h"

Worker::Worker(IdGenerator& idGenerator, Role role) :
    role(role),
    id(idGenerator.getWorkerId()),
    name(""),
    lastName(""),
    age(0),
    phoneNumber(""),
    password("") {};

Worker::Worker(IdGenerator& idGenerator, Role role, const CustomString& name, const CustomString& lastName,int age, const CustomString& phoneNumber, const CustomString& password) :
    role(role),
    id(idGenerator.getWorkerId()),
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
const CustomString& Worker::getPhoneNumber() const {return this->phoneNumber;}
const CustomString& Worker::getPassword() const {return this->password;}

void Worker::setName(const CustomString& name) {this->name = name;}
void Worker::setLastName(const CustomString& lastName) {this->lastName = lastName;}
void Worker::setAge(int age) {this->age = age;}
void Worker::setPhoneNumber(CustomString& phoneNumber) {this->phoneNumber = phoneNumber;}
void Worker::setPassword(const CustomString& password) {this->password = password;}

const CustomString Worker::getRoleAsString() const {
    if (this->role == Role::Manager) {return "Manager";}
    return "Cashier";
}

// Serialize-deserialize
void Worker::serializeCommon(std::ofstream& out) const {
    int valueRole = static_cast<int>(this->role);
    out.write(reinterpret_cast<const char*>(&this->role), sizeof(this->role));

    out.write(reinterpret_cast<const char*>(&this->id), sizeof(this->id));
    
    this->name.serialize(out);
    this->lastName.serialize(out);

    out.write(reinterpret_cast<const char*>(&this->age), sizeof(this->age));

    this->phoneNumber.serialize(out);
    this->password.serialize(out);
}

void Worker::deserializeCommon(std::ifstream& in) {
    int valueRole;
    in.read(reinterpret_cast<char*>(&valueRole), sizeof(valueRole));
    this->role = static_cast<Role>(valueRole);

    in.read(reinterpret_cast<char*>(&this->id), sizeof(this->id));

    this->name.deserialize(in);
    this->lastName.deserialize(in);

    in.read(reinterpret_cast<char*>(&this->age), sizeof(this->age));

    this->phoneNumber.deserialize(in);
    this->password.deserialize(in);
}