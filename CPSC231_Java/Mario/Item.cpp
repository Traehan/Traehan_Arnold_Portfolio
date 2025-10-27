#include "Item.h"

//this is the data type that is held within the grid
Item::Item(string name) {
    this->name = name;
}

Item::Item() {
    this->name = "";
}