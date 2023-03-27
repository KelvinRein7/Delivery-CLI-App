#include "FranchiseArray.h"
#include "Franchise.h"


FranchiseArray::FranchiseArray() {
    franchisePtr = new Franchise*[MAX_ARRAY];
    numFranchises = 0;
}

FranchiseArray::~FranchiseArray() {}

bool FranchiseArray::isFull() const {
    if(numFranchises == MAX_ARRAY){
        return true;
    }
    else{
        return false;
    }
}

void FranchiseArray::addFranchise(Franchise* franchise) {
    if(!isFull()){
        franchisePtr[numFranchises] = franchise;
        numFranchises++;
    }
    else{
        cout << "Sorry, the array is full." << endl;
    }
}

void FranchiseArray::printFranchises() {
    for (int i = 0; i < numFranchises; i++) {
        franchisePtr[i]->print();
    }
}

Franchise* FranchiseArray::getFranchise(const string& id) const {

    for (int i = 0; i < numFranchises; i++) {
        if (franchisePtr[i]->getId() == id) {
            return franchisePtr[i];
        }
    }
    return nullptr;

}

Franchise* FranchiseArray::findClosestFranchise(Location location) {

    Franchise* closestFranchise = franchisePtr[0];
    int minDistance = closestFranchise->getLocation().getDistance(location);
    
    for (int i = 0; i < numFranchises; i++) {
        int distance = franchisePtr[i]->getLocation().getDistance(location);
        if (distance < minDistance) {
            minDistance = distance;
            closestFranchise = franchisePtr[i];
        }
    }
    return closestFranchise;

}
