#ifndef WorldGameplay_H
#define WorldGameplay_H
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "Item.h"
#include "Mario.h"

using namespace std;

class WorldGameplay {
    public:
        WorldGameplay(string* gameParameters);
        Item** createLevelGrid(int gridDimension);
        Item selectItem();
        string* gameParameters;
    private:
        int getRandom(int min, int max);
};
#endif