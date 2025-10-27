#include <iostream>
#include <fstream>
#include <string>
#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item {
    public:
        Item(string name);
        Item();
        string name;
};
#endif