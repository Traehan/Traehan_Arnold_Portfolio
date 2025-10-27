#ifndef EnvironmentInteraction_H
#define EnvironmentInteraction_H
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Item.h"
#include "Mario.h"

using namespace std;

class EnvironmentInteraction {
    public:
        EnvironmentInteraction(string* gameParameters);
        Item** createLevelGrid(int gridDimension);
        Item selectItem();
        string* gameParameters;
    private:
        int getRandom(int min, int max);
};
#endif