#include "warning.h"

Warning::Warning() : sender(nullptr) ,criticalityDegree(CriticalityDegree::Low) {}

Warning::Warning(Manager* sender, const CustomString& description, CriticalityDegree criticalityDegree) {
    setSender(sender);
    setDescription(description);
    setCriticalityDegree(criticalityDegree);
}

Manager* Warning::getSender() const {return sender;}
const CustomString& Warning::getDescription() const {return description;}
CriticalityDegree Warning::getCriticalityDegree() const {return criticalityDegree;}

void Warning::setSender(Manager* sender) {this->sender = sender;}
void Warning::setDescription(const CustomString& description) {this->description = description;}
void Warning::setCriticalityDegree(CriticalityDegree criticalityDegree) {this->criticalityDegree = criticalityDegree;}