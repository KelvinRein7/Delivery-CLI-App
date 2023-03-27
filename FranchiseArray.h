#ifndef FRANCHISEARRAY_H
#define FRANCHISEARRAY_H

#include <iostream>
#include <string>

#include "Franchise.h"
#include "defs.h"

using namespace std;

class FranchiseArray {
    public:
        FranchiseArray();
        ~FranchiseArray();

        bool isFull() const;
        void addFranchise(Franchise* franchise);
        void printFranchises();

        Franchise* getFranchise(const string& id) const;

        Franchise* findClosestFranchise(Location location);

        

    private:
        Franchise** franchisePtr;
        int numFranchises;
};







#endif