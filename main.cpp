#include <iostream>
#include "utils/idGenerator.h"

int main() {

    IdGenerator& n1 = IdGenerator::getInstance();
    IdGenerator& n2 = IdGenerator::getInstance();

    std::cout << n1.getWorkerId() << '\n';
    std::cout << n2.getWorkerId() << '\n';

    return 0;
}