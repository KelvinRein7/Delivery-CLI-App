#ifndef FRANCHISE_H
#define FRANCHISE_H

#include <iostream>
#include <string>
#include <vector>
#include "Entity.h"
#include "defs.h"
#include "Order.h"


using namespace std;

class Franchise : public Entity {

    public:
        Franchise(string name, Location location);
        Franchise(const string& f);
        ~Franchise();

        void print() const;

        static void printMenu();
        static string getMenu(int index);

    
        Location getLocation() const;
        
        

    private:
        static const char code;
        static int nextId;
        static const string menu[];

};


#endif