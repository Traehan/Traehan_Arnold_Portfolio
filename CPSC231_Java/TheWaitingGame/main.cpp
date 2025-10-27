#include <iostream>
#include "ServiceCenter.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " input_file.txt" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];
    ServiceCenter serviceCenter(inputFile);

    if (serviceCenter.isEmpty()) {
        std::cerr << "Error reading input file or no data found." << std::endl;
        return 1;
    }

    serviceCenter.runSimulation();
    serviceCenter.printMetrics();

    return 0;
}
