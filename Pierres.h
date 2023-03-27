#ifndef PIERRES_H
#define PIERRES_H

#include <iostream>
#include <string>
#include <vector>

#include "Driver.h"
#include "Franchise.h"
#include "DriverArray.h"
#include "FranchiseArray.h"

using namespace std;

class Pierres {

    public:
        Pierres();
        void addDriver(string name, Location location);
        void addFranchise(string name, Location location);

        void takeOrder(string customerName, int menuItem, Location location);

        void driverPickup(string franchiseId, int numOrders);
        void driverDeliver(string driverId, int numOrders);

        void printFranchises();
        void printDrivers();



    private:
        // vector<Driver*> drivers;
        // vector<Franchise*> franchises;

        DriverArray* drivers;
        FranchiseArray* franchises;

        int numDrivers;
        int numFranchises;
};













#endif