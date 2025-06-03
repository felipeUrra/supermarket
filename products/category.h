// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "../customFunctions/customString.h"

class Category {
private:
    static int nextId;

    CustomString name;
    CustomString description;
    int id;

public:
    Category();
    Category(const CustomString& name, const CustomString& description);
    ~Category() = default;

    //getters and setters
    const CustomString& getName() const;
    const CustomString& getDescription() const;
    int getId() const;

    void setName(const CustomString& name);
    void setDescription(const CustomString& description);
};