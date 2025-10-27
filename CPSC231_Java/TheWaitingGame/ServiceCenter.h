#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include "Office.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

class ServiceCenter {
private:
    std::vector<Office> offices;
    int currentTime;

public:
    ServiceCenter(const std::string& inputFile);
    ~ServiceCenter();

    void runSimulation();
    void printMetrics();
};

#endif
