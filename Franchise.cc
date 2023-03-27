#include "Franchise.h"
#include "Entity.h"
#include "Location.h"
#include "Order.h"
#include "Queue.h"
#include "defs.h"


int Franchise::nextId = 1;

const char Franchise::code = 'F';

const string Franchise::menu[MENU_ITEMS] = {
    "1. Large Poutine", 
    "2. Medium Poutine", 
    "3. Small Poutine"
};


Franchise::Franchise(string name, Location location) : 
    Entity(code, nextId++, name, location) {
}

Franchise::Franchise(const string& f) :
    Entity(code, nextId++, f, location) {
}
    

Franchise::~Franchise() {
    
}

Location Franchise::getLocation() const {
    return location;
}


void Franchise::print() const {
    cout << "Franchise Info: " << endl;
    Entity::print();
}

void Franchise::printMenu() {
    for (int i = 0; i < MENU_ITEMS; i++) {
        cout << menu[i] << endl;
    }
}

string Franchise::getMenu(int index) {
    if(index >= 0 && index < MENU_ITEMS) {
        return menu[index];
    }
    else {
        return "unknown menu item";
    }
}