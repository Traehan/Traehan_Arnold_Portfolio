#include "Office.h"

Office::Office(int numWindows) : numWindows(numWindows), windowIdCounter(1) {
    for (int i = 0; i < numWindows; ++i) {
        windows.push_back(Window(windowIdCounter++));
    }
}

Office::~Office() {}

void Office::addCustomer(const Customer& customer) {
    queue.enqueue(customer);
}

void Office::processCustomers(int currentTime) {
    while (!queue.isEmpty()) {
        // Find the shortest idle window or any window if all are busy
        auto it = std::min_element(windows.begin(), windows.end(), compareWindows);
        if (it != windows.end()) {
            Window& window = *it;
            if (window.isIdle(currentTime)) {
                Customer customer = queue.dequeue();
                window.startService(customer, currentTime);
            } else {
                break; // All windows are busy
            }
        } else {
            break; // No idle windows
        }
    }

    // Update window status after processing customers
    for (auto& window : windows) {
        window.updateStatus(currentTime);
    }
}

double Office::calculateMeanWaitTime() {
    // Calculate mean wait time using the queue
}

int Office::calculateLongestWaitTime() {
    // Calculate longest wait time using the queue
}

int Office::calculateNumWaitingOverThreshold(int threshold) {
    // Calculate number of customers waiting over a given threshold using the queue
}

double Office::calculateMeanIdleTime() {
    // Calculate mean idle time for windows
}

int Office::calculateLongestIdleTime() {
    // Calculate longest idle time for windows
}

int Office::calculateNumIdleOverThreshold(int threshold) {
    // Calculate number of windows idle over a given threshold
}

bool Office::compareWindows(const Window& first, const Window& second) {
    // Compare windows for finding the shortest idle window
}
