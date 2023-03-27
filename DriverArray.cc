#include "DriverArray.h"

DriverArray::DriverArray() {
    numDrivers = 0;
    driverPtr = new Driver*[MAX_ARRAY];
}

DriverArray::~DriverArray() {}

bool DriverArray::isFull() const {
    if(numDrivers == MAX_ARRAY){
        return true;
    }
    else{
        return false;
    }
}

void DriverArray::addDriver(Driver* driver) {
    if(!isFull()){
        driverPtr[numDrivers] = driver;
        numDrivers++;
    }
    else{
        cout << "Sorry, the array is full." << endl;
    }
}


void DriverArray::printDrivers() {
    for (int i = 0; i < numDrivers; i++) {
        driverPtr[i]->print();
    }
}

Driver* DriverArray::getDriver(string id) const {
    for (int i = 0; i < numDrivers; i++) {
        if (driverPtr[i]->getId() == id) {
            return driverPtr[i];
        }
    }
    return nullptr;
}

Driver* DriverArray::findClosestDriver(Location location) {
    
    Driver* closestDriver = driverPtr[0];
    int minDistance = closestDriver->getLocation().getDistance(location);

    for (int i = 0; i < numDrivers; i++) {
        if (driverPtr[i]->isFree()) {
            int distance = driverPtr[i]->getLocation().getDistance(location);
            if (distance < minDistance) {
                minDistance = distance;
                closestDriver = driverPtr[i];
            }
        }
    }
    return closestDriver;
}