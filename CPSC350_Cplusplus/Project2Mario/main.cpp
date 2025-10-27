#include "Level.h"

#include <iostream>

int main (int argc, char **argv){
    Level level(5);

    // Initialize the level with specified percentages
    level.initialize(30, 20, 15, 10, 25);

    // Print the initialized grid
    std::cout << "Initial Level Grid:" << std::endl;
    level.print();

    return 0;
}