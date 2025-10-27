#ifdef GENSTACK_H
#define GENSTACK_H

#include<iostream>
using namespace std;

class GenStack{

    public:
        GenStack(); //default constructor
        GenStack(int maxSize); //overloaded constructor
        ~GenStack(); //destructor

        //core functions
        void push(char data);
        char pop(); //return and remove
        char peek(); //aka top, just returns, DOES NOT remove

        //extra (aux) functions
        bool isEmpty();
        bool isFull();
        int getSize();

    private:
        int top;
        int mSize;
        char *myArray;


};


#endif