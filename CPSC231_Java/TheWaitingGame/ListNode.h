#ifndef LISTNODE_H
#define LISTNODE_h

#include <iostream>
#include <exception>

using namespace std;

template <typename T>;
class ListNode{
    public:
    ListNode();
    ListNode(int d);
    ~ListNode();

    ListNode *next;
    ListNode *prev;
    
    int data;
};

#endif