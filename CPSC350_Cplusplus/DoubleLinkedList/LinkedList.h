#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"
//doubly linked list with pointers to next and prev

class LinkedList{
    private:
    ListNode *front;
    ListNode *back;
    unsigned int size;


    public:
    LinkedList();
    ~LinkedList();

    void insertFront();
    void insertBack();
    int removeFront();
    int removeBack();
    int removedNode(int value);
    int find(int value);
    bool isEmpty();
    unsigned int getSize();

    void printList(bool printLink);
};
#endif