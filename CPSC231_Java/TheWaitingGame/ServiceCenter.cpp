#include "ServiceCenter.h"

ServiceCenter::ServiceCenter(const std::string& inputFile) : currentTime(0) {
    // Read input file and initialize offices
    std::ifstream file(inputFile);
    if (!file) {
        std::cerr << "Error opening file: " << inputFile << std::endl;
        return;
    }

    int numRegistrarWindows, numCashierWindows, numFinancialAidWindows;
    int arrivalTime, numStudents;
    while (file >> numRegistrarWindows >> numCashierWindows >> numFinancialAidWindows
                >> arrivalTime >> numStudents) {
        Office officeRegistrar(numRegistrarWindows);
        Office officeCashier(numCashierWindows);
        Office officeFinancialAid(numFinancialAidWindows);
        offices.push_back(officeRegistrar);
        offices.push_back(officeCashier);
        offices.push_back(officeFinancialAid);

        for (int i = 0; i < numStudents; ++i) {
            int timeRegistrar, timeCashier, timeFinancialAid;
            std::string officeOrder;
            file >> timeRegistrar >> timeCashier >> timeFinancialAid >> officeOrder;
            Customer customer(timeRegistrar, timeCashier, timeFinancialAid, officeOrder);
            offices[officeOrder[0] - 'A'].addCustomer(customer);
        }
    }

    file.close();
}

ServiceCenter::~ServiceCenter() {}

void ServiceCenter::runSimulation() {
    while (true) {
        bool allOfficesEmpty = true;
        for (auto& office : offices) {
            if (!office.isEmpty()) {
                office.processCustomers(currentTime);
                allOfficesEmpty = false;
            }
        }
        if (allOfficesEmpty) {
            break;
        }
        currentTime++;
    }
}

void ServiceCenter::printMetrics() {
    for (auto& office : offices) {
        std::cout << "Office Metrics for " << office.getName() << ":" << std::endl;
        std::cout << "Mean Wait Time: " << office.calculateMeanWaitTime() << std::endl;
        std::cout << "Longest Wait Time: " << office.calculateLongestWaitTime() << std::endl;
        std::cout << "Number of Students Waiting Over 10 Minutes: "
                  << office.calculateNumWaitingOverThreshold(10) << std::endl;
        std::cout << "Mean Window Idle Time: " << office.calculateMeanIdleTime() << std::endl;
        std::cout << "Longest Window Idle Time: " << office.calculateLongestIdleTime() << std::endl;
        std::cout << "Number of Windows Idle Over 5 Minutes: "
                  << office.calculateNumIdleOverThreshold(5) << std::endl;
        std::cout << std::endl;
    }
}
