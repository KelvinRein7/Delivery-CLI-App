#ifndef DRIVERARRAY_H
#define DRIVERARRAY_H

#include <iostream>
#include <string>
#include "Driver.h"
#include "defs.h"

using namespace std;

class DriverArray {
    public:
        DriverArray();
        ~DriverArray();

        bool isFull() const;
        void addDriver(Driver* driver);
        void printDrivers();

        Driver* getDriver(string id) const;

        Driver* findClosestDriver(Location location);

    private:
        Driver** driverPtr;
        int numDrivers;
};










#endif