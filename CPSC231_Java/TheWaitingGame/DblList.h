#ifndef DBLLIST_H
#define DBLLIST_H

#include "ListNode.h"
//doubly linked list with pointers to next and prev

template <typename T>
class DblList {
private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;

public:
    DblList();
    ~DblList();

    void insertFront(const T& value);
    void insertBack(const T& value);
    T removeFront();
    T removeBack();
    bool removeNode(const T& value);
    bool find(const T& value);
    bool isEmpty();
    unsigned int getSize();

    void printList(bool printLink);
};
#endif