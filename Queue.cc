#include "Queue.h"
#include "Order.h"


Queue::Queue() {
    head = NULL;
    tail = NULL;
    numOfOrders = 0;
}

Queue::~Queue() {
    while(!empty()) {
        popFirst();
    }
}

bool Queue::empty() const {
    if(numOfOrders == 0) {return true;}
    else {return false;}
}

int Queue::size() const{
    return numOfOrders;
}

Order* Queue::peekFirst(){
    if(!empty()) {
        return head->data;
    }
    else {
        return nullptr;
    }
}

Order* Queue::popFirst(){
    if(!empty()) {
        Node* tempHead = head;
        head = head->next;

        Order* tempOrder = tempHead->data;

        delete tempHead;

        numOfOrders--;

        return tempOrder;
    }
    else {
        return nullptr;
    }
}

void Queue::addLast(Order* order) {
    Node* temp = new Node;
    temp->data = order;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = tail->next;
    }
    numOfOrders++;
}
