#include "Customer.h"

Customer::Customer(int timeRegistrar, int timeCashier, int timeFinancialAid, const std::string& order)
    : timeNeededRegistrar(timeRegistrar), timeNeededCashier(timeCashier),
      timeNeededFinancialAid(timeFinancialAid), officeOrder(order) {}

int Customer::getTimeNeededRegistrar() const {
    return timeNeededRegistrar;
}

int Customer::getTimeNeededCashier() const {
    return timeNeededCashier;
}

int Customer::getTimeNeededFinancialAid() const {
    return timeNeededFinancialAid;
}

const std::string& Customer::getOfficeOrder() const {
    return officeOrder;
}
