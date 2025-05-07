#include "customVector.h"
#include <iostream>

CustomVector::CustomVector() : CustomVector(4) {};

CustomVector::CustomVector(uint newSize) : size(newSize) {
    this->capacity = allocateCapacity(newSize);
    this->data = new Type[this->capacity];
}

CustomVector::CustomVector(const CustomVector& other) {
    copyFrom(other);
}

CustomVector& CustomVector::operator=(const CustomVector& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    
    return *this;
}

CustomVector::~CustomVector() {
    free();
}

uint CustomVector::getSize() const{
    return this->size;
}

uint CustomVector::getCapacity() const{
    return this->capacity;
}

CustomVector& CustomVector::push_back(const Type& data) {
    if (this->size >= this->capacity) {
        resize(this->capacity * 2);
    }

    this->data[this->size++] = data;

    return *this;
}

CustomVector& CustomVector::pop_back() {
    if (this->size > 0) {
        this->size--;
    } else {
        return *this;
    }

    if ((this->size * 4) <= this->capacity && this->capacity > 1) {
        resize(this->capacity / 2);
    }
    
    return *this;
}

CustomVector& CustomVector::insert(const Type& data, uint position) {
    if (position > this->size) {
        return *this;
    }

    if (this->size >= this->capacity) {
        resize(this->capacity * 2);
    }

    for (int i = this->size; i > position; i++) {
        this->data[i] = this->data[i - 1];
    }

    this->data[position] = data;
    this->size++;
    
    return *this;
}

CustomVector& CustomVector::remove(uint position) {
    if (position > this->size) {
        return *this;
    }
    
    for (int i = position + 1; i < this->size; i++) {
        this->data[i - 1] = this->data[i];
    }
    
    this->size--;

    if ((this->size * 4) <= this->capacity && this->capacity > 1) {
        resize(this->capacity / 2);
    }
    
    return *this;
}

Type& CustomVector::operator[](uint idx) {
    return this->data[idx];
}

CustomVector& CustomVector::clear() {
    this->size = 0;
    return *this;
}

void CustomVector::resize(uint newCapacity) {
    Type* newData = new Type[newCapacity];

    for (int i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
    }

    delete[] data;
    data = newData;

    this->capacity = newCapacity;
    
}

uint CustomVector::getNextPowerOfTwo(uint n) const {
    if (n == 0) return 1;

	while (n & (n - 1))
	{
		n &= (n - 1);
	}

	return n << 1;
}

uint CustomVector::allocateCapacity(uint n) const {
    return std::max(getNextPowerOfTwo(n + 1), 8u);
}

void CustomVector::copyFrom(const CustomVector& other) {
    this->size = size;
    this->capacity = capacity;

    this->data = new Type(this->capacity);

    for (int i = 0; i < this->capacity; i++) {
        this->data[i] = other.data[i];
    }
}

void CustomVector::free() {
    delete[] this->data;

    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
}