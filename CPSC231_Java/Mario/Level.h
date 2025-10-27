#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Item.h"
#include "Mario.h"

using namespace std;

class Level {
    public:
        Level(string* gameParameters);
        Item** createLevel(int gridDimension);
        Item **createFinalLevel(int gridDimension);
        Item assignSquare();
        string* gameParameters;
    private:
        int getRandom(int min, int max);
};
#endif