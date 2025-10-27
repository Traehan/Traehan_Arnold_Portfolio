#ifndef OFFICE_H
#define OFFICE_H

#include "ListQueue.h"
#include "Customer.h"

class Office {
private:
    ListQueue<Customer> queue;
    int numWindows; // Number of windows in the office
    int windowIdCounter; // Counter to assign unique IDs to windows
    std::vector<Window> windows; // Vector to hold window objects
    bool compareWindows(const Window& first, const Window& second); // Helper function for window comparison

public:
    Office(int numWindows);
    ~Office();

    void addCustomer(const Customer& customer);
    void processCustomers(int currentTime);
    double calculateMeanWaitTime();
    int calculateLongestWaitTime();
    int calculateNumWaitingOverThreshold(int threshold);
    double calculateMeanIdleTime();
    int calculateLongestIdleTime();
    int calculateNumIdleOverThreshold(int threshold);
};
#endif