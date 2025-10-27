#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int timeNeededRegistrar;
    int timeNeededCashier;
    int timeNeededFinancialAid;
    std::string officeOrder;

public:
    Customer(int timeRegistrar, int timeCashier, int timeFinancialAid, const std::string& order);

    int getTimeNeededRegistrar() const;
    int getTimeNeededCashier() const;
    int getTimeNeededFinancialAid() const;
    const std::string& getOfficeOrder() const;
};

#endif
