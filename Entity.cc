#include "Entity.h"
#include "Queue.h"
#include "Location.h"
#include "Order.h"      

Entity::Entity(char code, int id, string name, Location location){
    this->id = code + to_string(id);
    this->name = name;
    this->location = location;
}

Entity::~Entity(){}

Entity::Entity(const string& e){
    this->id = e;
}

void Entity::setLocation(Location location){
    this->location = location;
}

int Entity::getNumOrders() const {
    return orders.size();
}

Order* Entity::getNextOrder(){
    if(!orders.empty()){
        return orders.popFirst();
    }
    else{
        return NULL;
    }
}

void Entity::addOrder(Order* order){
    orders.addLast(order);
}

void Entity::print() const {
    cout << "ID               : " << id << endl;
    cout << "Name             : " << name << endl;
    cout << "Location         : ";
    location.print();
    cout << endl;
    cout << "Number of Orders : " << orders.size() << endl;
    cout << endl;
}

bool Entity::equals(const string& id) const {
    if(this->id == id){
        return true;
    }
    else{
        return false;
    }
}

string Entity::getId() const {
    return id;
}