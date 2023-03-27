#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

#include "Queue.h"
#include "Location.h"
#include "Order.h"

using namespace std;

class Entity {

    public:
        Entity(char code, int id, string name, Location location);
        Entity(const string& e);
        ~Entity();

        void setLocation(Location location);
        int getNumOrders() const;

        Order* getNextOrder();

        void addOrder(Order* order);
        void print() const;

        bool equals(const string& id) const;

        string getId() const;
        
        


    protected:
        string id;
        string name;
        Location location;
        Queue orders;



};




#endif