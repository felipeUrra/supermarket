// Felipe Urra Rivadeneira 0MI8000066

#pragma once

#include <iostream>
#include <fstream>
#include "customVector.h"

namespace Constants
{
	constexpr size_t MAX_SIZE = 1024;
}

class CustomString
{
private:
	char* data;
	size_t size;
	size_t capacity;

	explicit CustomString(size_t newSize);

	unsigned int getNextPowerOfTwo(unsigned int n) const;
	unsigned int allocateCapacity(unsigned int size) const;

	void resize(size_t newCapacity);

	void copyFrom(const CustomString& other);
	void free();

public:
	static const int npos = -1;
	CustomString();
	CustomString(const char* data);

	CustomString(const CustomString& other);
	CustomString& operator=(const CustomString& other);

	const char* c_str() const; 
	static CustomString valueOf(int);

	size_t getSize() const;
	size_t getCapacity() const;

	// Serialize/deserialize
	void serialize(std::ofstream& out) const;
    void deserialize(std::ifstream& in);

	const char& operator[](size_t idx) const;
	char& operator[](size_t idx);

	CustomString& operator+=(const CustomString& other);
	CustomString& operator+=(char c);
	friend CustomString operator+(const CustomString& lhs, const CustomString& rhs);
	friend CustomString operator+(const CustomString& lhs, char c);
	friend CustomString operator+(char c, const CustomString& rhs);

	CustomString substr(size_t begin, size_t howMany) const;

	friend bool operator==(const CustomString& lhs, const CustomString& rhs);
	friend bool operator!=(const CustomString& lhs, const CustomString& rhs);

	friend bool operator<=(const CustomString& lhs, const CustomString& rhs);
	friend bool operator>=(const CustomString& lhs, const CustomString& rhs);

	friend bool operator<(const CustomString& lhs, const CustomString& rhs);
	friend bool operator>(const CustomString& lhs, const CustomString& rhs);

	friend std::istream& operator>>(std::istream& is, CustomString& other);
	friend std::ostream& operator<<(std::ostream& os, const CustomString& other);
	size_t indexOf(char c, size_t startPos = 0) const;
	double toDouble() const;
	int toInt() const;
	CustomVector<CustomString> split(char delimiter) const;
	bool isEmpty() const;

	~CustomString();
};