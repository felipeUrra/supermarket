// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "../customFunctions/customString.h"
#include "../system.h"

class Utils {
public:
    Utils() = default;
    virtual ~Utils() = 0;

    static CustomString intToStr(int num);
    static bool isAllGoodWithDataEntry(int var); 
    static bool isAllGoodWithDataEntry(double var);
    static bool isValidPhoneNumber(const CustomString& phoneNumber);

    static void saveSystemState(const System& system, const CustomString& filename);
    static void loadSystemState(System& system, const CustomString& filename);    
};