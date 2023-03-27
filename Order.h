#ifndef ORDER_H
#define ORDER_H

#include "Location.h"
#include <iostream>
#include <string>

using namespace std;


class Order {

    public:
        Order(string name, int item, Location location);
        Location getLocation() const;
        void print() const;

    private:
        string customerName;
        int menuItem;
        Location deliLocation;
        
};





#endif