#pragma once
#include <iostream>

using Type = int;
typedef unsigned int uint;

class CustomVector {
private:
    Type* data;
    uint size;
    uint capacity;

    void resize(uint);

    uint getNextPowerOfTwo(uint n) const;
    uint allocateCapacity(uint n) const;

    void copyFrom(const CustomVector&);
    void free();

public:
    // big four
    CustomVector();
    CustomVector(const CustomVector&);
    CustomVector& operator=(const CustomVector&);
    ~CustomVector();

    CustomVector(uint);

    uint getSize() const;
    uint getCapacity() const;

    CustomVector& push_back(const Type&);
    CustomVector& pop_back();

    CustomVector& insert(const Type&, uint);
    CustomVector& remove(uint);

    Type& operator[](uint);

    CustomVector& clear();
};