// Felipe Urra Rivadeneira #0MI8000066 CI Group6
// Course project - 09Supermarket
// OOP(practice) - 2024-2025

#include "transaction.h"
#include "giftCards/singleCategoryGiftCard.h"
#include "giftCards/multipleCategoryGiftCard.h"
#include "giftCards/allProductsGiftCard.h"
#include "services/consoleService.h"
#include <ctime>

Transaction::Transaction(IdGenerator& idGenerator) : total(0), id(idGenerator.getTransactionId()) {
    setActualDateAndTime();
}

Transaction::Transaction(IdGenerator& idGenerator, int cashierId, double total) :
    cashierId(cashierId),
    total(total),
    id(idGenerator.getTransactionId())
    {
        setActualDateAndTime();
    }


void Transaction::setActualDateAndTime() {
    time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    // date format: DD-MM-YYYY
    char buffDate[11]; // DD-MM-YYYY\0
    std::strftime(buffDate, sizeof(buffDate), "%d.%m.%Y", now);
    this->date = buffDate;

    // time format: HH-MM
    char buffTime[6]; // HH-MM\0
    std::strftime(buffTime, sizeof(buffTime), "%H:%M", now);
    this->time = buffTime;
}


//getters and setters
int Transaction::getCashierId() {return this->cashierId;}
double Transaction::getTotal() const {return this->total;}
const CustomString& Transaction::getDate() const {return this->date;}
const CustomString& Transaction::getTime() const {return this->time;}
int Transaction::getId() const {return this->id;}
CustomVector<CustomString>& Transaction::getProductsName() {return this->productsName;}
CustomVector<double>& Transaction::getPrices() {return this->prices;}
CustomVector<double>& Transaction::getQuantities() {return this->quantities;}

void Transaction::setCashierId(int cashierId) {this->cashierId = cashierId;}
void Transaction::setTotal(double total) {this->total = total;}

void Transaction::applyGiftCard(GiftCard* gc, Supermarket* supermarket) {
    if (gc->getType() == GiftCardType::SingleCategory) {
        SingleCategoryGiftCard* sc = dynamic_cast<SingleCategoryGiftCard*>(gc);
        
        for (int i = 0; i < this->productsName.getSize(); i++) {
            Product* productSelled = supermarket->getProductByName(this->productsName[i]);

            if (productSelled->getCategoryName() == sc->getCategoryName()) {
                this->total = (productSelled[i].getPrice() * this->quantities[i]) - (productSelled[i].getPrice() * this->quantities[i])/sc->getDiscount();
            }
        }
        
        std::cout << sc->getDiscount();
        ConsoleService::printLine("'%' applied to all the product of the category "
                        + sc->getCategoryName()
                        + "! Transaction completed!");
    } else if (gc->getType() == GiftCardType::MultipleCategories) {
        MultipleCategoryGiftCard* mc = dynamic_cast<MultipleCategoryGiftCard*>(gc);

        for (int i = 0; i < this->productsName.getSize(); i++){
            Product* productSelled = supermarket->getProductByName(this->productsName[i]);

            for (int i = 0; i < mc->getCategoriesNames().getSize(); i++) {
                if (productSelled->getCategoryName() == mc->getCategoriesNames()[i]) {
                    this->total = (productSelled[i].getPrice() * this->quantities[i]) - (productSelled[i].getPrice() * this->quantities[i])/mc->getDiscount();
                }
            }
        }

        std::cout << mc->getDiscount();
        ConsoleService::print("'%' applied to all the product of the categories ");
        for (int i = 0; i < mc->getCategoriesNames().getSize(); i++) {
            if (i != mc->getCategoriesNames().getSize() - 1) {
                ConsoleService::print(mc->getCategoriesNames()[i] + ", ");
                continue;
            }
            
            ConsoleService::printLine(mc->getCategoriesNames()[i] + "! Transaction completed!");
        }
        
        
    } else {
        AllProductsGiftCard* ap = dynamic_cast<AllProductsGiftCard*>(gc);

        this->total = total - (total/ap->getDiscount());

        std::cout << ap->getDiscount();
        ConsoleService::printLine("'%' applied to all the products! Transaction completed");
    } 
}

// serialize-deserialize
void Transaction::serialize(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*>(&this->id), sizeof(this->id));
    out.write(reinterpret_cast<const char*>(&this->cashierId), sizeof(this->cashierId));
    out.write(reinterpret_cast<const char*>(&this->total), sizeof(this->total));
    this->date.serialize(out);
    this->time.serialize(out);

    int productsNameCount = this->productsName.getSize();
    out.write(reinterpret_cast<const char*>(&productsNameCount), sizeof(productsNameCount));
    for (int i = 0; i < productsNameCount; i++) {
        this->productsName[i].serialize(out);
    }

    int pricesCount = this->prices.getSize();
    out.write(reinterpret_cast<const char*>(&pricesCount), sizeof(pricesCount));
    for (int i = 0; i < pricesCount; i++) {
        out.write(reinterpret_cast<const char*>(&this->prices[i]), sizeof(this->prices[i]));
    }

    int quantitiesCount = this->quantities.getSize();
    out.write(reinterpret_cast<const char*>(&quantitiesCount), sizeof(quantitiesCount));
    for (int i = 0; i < quantitiesCount; i++) {
        out.write(reinterpret_cast<const char*>(&this->quantities[i]), sizeof(this->quantities[i]));
    }
}

void Transaction::deserialize(std::ifstream& in) {
    in.read(reinterpret_cast<char*>(&this->id), sizeof(this->id));
    in.read(reinterpret_cast<char*>(&this->cashierId), sizeof(this->cashierId));
    in.read(reinterpret_cast<char*>(&this->total), sizeof(this->total));
    this->date.deserialize(in);
    this->time.deserialize(in);

    int productsNameCount;
    in.read(reinterpret_cast<char*>(&productsNameCount), sizeof(productsNameCount));
    for (int i = 0; i < productsNameCount; i++) {
        this->productsName[i].deserialize(in);
    }

    int pricesCount;
    in.read(reinterpret_cast<char*>(&pricesCount), sizeof(pricesCount));
    for (int i = 0; i < pricesCount; i++) {
        in.read(reinterpret_cast<char*>(&this->prices[i]), sizeof(this->prices[i]));
    }

    int quantitiesCount;
    in.read(reinterpret_cast<char*>(&quantitiesCount), sizeof(quantitiesCount));
    for (int i = 0; i < quantitiesCount; i++) {
        in.read(reinterpret_cast<char*>(&this->quantities[i]), sizeof(this->quantities[i]));
    }
}