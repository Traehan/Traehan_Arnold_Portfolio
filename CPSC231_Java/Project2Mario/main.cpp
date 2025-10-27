#include "Level.h"

#include <iostream>

int main (int argc, char **argv){
    Level Level(5);
    // Initialize the level with specified percentages
    Level.MakeLevel(30, 20, 15, 10, 25);

    // Print the initialized grid
    std::cout << "Initial Level Grid:" << std::endl;
    Level.print();

    return 0;
}