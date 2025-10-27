#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "DblList.h"

template <typename T>
class ListQueue {
private:
    DblList<T> list;

public:
    ListQueue();
    ~ListQueue();

    void enqueue(const T& value);
    T dequeue();
    T peek();
    bool isEmpty();
    unsigned int getSize();
};

#include "ListQueue.cpp" // Include the implementation file for template classes

#endif
