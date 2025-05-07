#pragma once
#include "customFunctions/customString.h"

enum class CriticalityDegree {Low = 100, Middle = 200, High = 300};

class Warning {
private:
    Manager& sender;
    CustomString description;
    CriticalityDegree criticalityDegree;
};