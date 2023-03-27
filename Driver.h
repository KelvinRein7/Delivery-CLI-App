#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include "Location.h"
#include "Entity.h"

using namespace std;

class Driver : public Entity {

    public:
        Driver(string name, Location location);
        Driver(const string& d);

        ~Driver();

        bool isFree() const;

        void print() const;

        Location getLocation() const;




    private:
        static const char code;
        static int nextId;

};



#endif