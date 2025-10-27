#include "GenStack.h"

GenStack::GenStack(){
    mSize = 64; //default size of our stack
    top = -1;
    myArray = new char[mSize];
}

GenStack::GenStack(int maxSize){
    mSize = maxSize; //overloaded constructor if wanting different size
    top = -1;
    myArray = new char[mSize];
}

GenStack::~GenStack(){ //deconstructor
    cout << "stack destroyed, garbage takeb out has been" << endl; 
    delete [] myArray;
}

void GenStack::push(char data){
    if(isFull()){
        cout << " resizing stack is" << endl;
        char *temp = new char[2*msize];
        for(int i = 0; i < msize; ++i){
            temp[i] = myArray[i]; //copy data from old array to new array
        }
        mSize *= 2; //shorthand for mSize = mSize * 2
        delete[] myArray;
        myArray = temp;
    }
    //TODO: check if stack is full
    myArray[++top] = data;
}

char GenStack::pop(){
    if(isEmpty()){
        throw runtime_error("Stack is empty, nothing to pop");
    }
    //TODO: check if stack is empty
    return myArray[top--];
}

char GenStack::peek(){
    if(isEmpty()){
        throw runtime_error("Stack is empty, nothing to peep");
    }
    //TODO: check if stack is empty
    return myArray[top];
}

bool GenStack::isEmpty(){
    return (top ==-1);
}

bool GenStack::isEmpty(){
    return (top == mSize-1);
}

int GenStack::getSize(){
    return top + 1;
}