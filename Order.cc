#include "Order.h"
#include "Queue.h"

Order::Order(string name, int item, Location location) {
    customerName = name;
    menuItem = item;
    deliLocation = location;
}

Location Order::getLocation() const {
    return deliLocation;
}

void Order::print() const {
    cout << "Customer Name: " << customerName << endl;
    cout << "Location: ";
    deliLocation.print();
    cout << endl;
    cout << "Menu Item: " << menuItem << endl;
}
