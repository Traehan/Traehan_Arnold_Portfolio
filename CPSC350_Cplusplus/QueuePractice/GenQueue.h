#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <exception>

//Array based Queue
using namespace;
class GenQueue{
    public:
        GenQueue(); //Default constructor
        GenQueue(int maxSize); //Overloaded Constructor
        ~GenQueue(); //destructor

        //Core Functions
        void insert(char d); //enqueue()
        char remove(); //dequeue()
        void enqueue(char d);

        //aux functions
        char peek(); 
        bool isFull(); 
        bool isEmpty();
        unsigned int getSize();
        void printArray(); //helper function to help visualize our array based queue

    private:
    unsigned int mSize;
    unsigned int front;
    unsigned int rear;
    unsigned int numElements;
    char *myQueue;

};

#endif