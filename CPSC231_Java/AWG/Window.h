#ifndef WINDOW_H
#define WINDOW_H

#include "Queue.h"  // Assuming you have a Queue implementation

class Customer;  // Forward declaration of Customer class

class Window {
private:
    bool isOccupied;
    Queue<Customer*> customerAtWindow;
    int idleTime;
    int totalIdleTime;
    int customersAttended;
    bool idleForMoreThanFive;

public:
    Window();
    ~Window();

    bool isIdle();
    void attendCustomer(Customer* c);
    void setOccupied(bool occ);
    Customer* getCustomerAtWindow();
    bool getIsOccupied();
    void removeCustomer();
    void incrementIdleTime();
    int getIdleTime();
    int getLongestIdleTime();
    int getCustomersAttended();
    bool getIdleForMoreThanFive();
};

#endif
