#include "Driver.h"
#include "Entity.h"

int Driver::nextId = 1;

const char Driver::code = 'D';

Driver::Driver(string name, Location location) : 
    Entity(code, nextId++, name, location) {
}

Driver::Driver(const string& d) :
    Entity(code, nextId++, d, location) {
}

Driver::~Driver() {
    
}

bool Driver::isFree() const {
    if (orders.empty()) {
        return true;
    }
    else {
        return false;
    }
}

void Driver::print() const {

    cout << "Driver Info: " << endl;
    Entity::print();
    
}

Location Driver::getLocation() const {
    return location;
}