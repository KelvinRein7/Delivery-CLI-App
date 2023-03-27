#include "Pierres.h"
#include "Order.h"
#include "Location.h"
#include "Franchise.h"
#include "DriverArray.h"
#include "FranchiseArray.h"

Pierres::Pierres() {
    drivers = new DriverArray();
    franchises = new FranchiseArray();
}

void Pierres::addDriver(string name, Location location){
    drivers->addDriver(new Driver(name, location));
}

void Pierres::addFranchise(string name, Location location){
    franchises->addFranchise(new Franchise(name, location));
}

void Pierres::printFranchises(){
    cout << "Print Franchises:" << endl;
    franchises->printFranchises();
}

void Pierres::printDrivers(){
    cout << "Print Drivers:" << endl;
    drivers->printDrivers();
}

void Pierres::takeOrder(string customerName, int menuItem, Location location){

    if(menuItem < 1 || menuItem > 3){
        cout << "Sorry, item option is not on the menu." << endl;
        return;
    }
    
    Franchise* franchise = franchises->findClosestFranchise(location);
    franchise->addOrder(new Order(customerName, menuItem, location));
    cout << "Order has been placed successfully." << endl;
}

void Pierres::driverPickup(string franchiseId, int numOrders){

    Franchise* franchise = franchises->getFranchise(franchiseId);
    if(franchise == nullptr || franchise->getNumOrders() == 0){
        cout << "Sorry, no franchise with that ID was found." << endl;
        return;
    }

    //if input order num >> franchise order num
    //set it to franchise order num
    if(numOrders > franchise->getNumOrders()){
        numOrders = franchise->getNumOrders();
    }

    Driver* driver = drivers->findClosestDriver(franchise->getLocation());
    if(driver == nullptr){
        cout << "Sorry, no driver found." << endl;
        return;
    }

    driver->setLocation(franchise->getLocation());

    for(int i = 0; i < numOrders; i++){
        cout << "Driver is picking up your order..." << endl;
        Order* order = franchise->getNextOrder();
        driver->addOrder(order);
    }

}

void Pierres::driverDeliver(string driverId, int numOrders){

    Driver* driver = drivers->getDriver(driverId);

    if(driver == nullptr || driver->isFree() == true){
        cout << "Sorry, no driver with that ID was found." << endl;
        return;
    }

    if(numOrders > driver->getNumOrders()){
        numOrders = driver->getNumOrders();
    }


    for(int i = 0; i < numOrders; i++){
        cout << "Driver is delivering..." << endl;

        Order* tempOrder = driver->getNextOrder();
        driver->setLocation(tempOrder->getLocation());
        
        tempOrder->print();
        delete tempOrder;

        //delete driver->getNextOrder();
        //driver->setLocation(driver->getNextOrder()->getLocation());
    }
    //driver->setLocation(driver->getLocation());
    
}