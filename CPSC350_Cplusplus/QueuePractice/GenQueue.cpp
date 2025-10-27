#include "GenQueue.h"

GenQueue::GenQueue(){
    mSize = 64;
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new char[mSize];
}

GenQueue::GenQueue(int maxSize){
    mSize = maxSize;
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new char[mSize];
}

GenQueue::~GenQueue(){
    delete[] myQueue;
}

void GenQueue::insert(Char d){
    //TODO: Check if full
    if(isFull()){
        throw runtime_error("Que is full")
    }
    myQueue[rear++] = d;
    rear %= mSize; //IMPORTANT
    numElements++;
}

void GenQueue::enqueue(char d){
    if(isFull()){
        throw runtime_error("priority queue is full");
    }

    int i = numElements-1;
    while(i >= 0 && d < myQueue[i]){
        myQueue[i+1] = myQueue[i];
        i--;
    }
    myQueue[i+1] = d;
    numElements++;
}

char GenQueue::remove(){
    //todo: check if empty
    if(isEmpty()){
        throw runtime_error("Que is empty")
    }
    char c = '\0';
    c = myQueue[front++];
    front %= mSize;
    numElements--;
    return c;
}

char GenQueue::peek(){
    if(isEmpty()){
        throw runtime_error("Que is empty")
    }
    return myQueue(front);
}

bool GenQueue::isFull(){
    return (numElements == mSize);
}

bool GenQueue::isEmpty(){
    return (numElements == 0);
}

unsigned int GenQueue::getSize(){
    return numElements;
}

void GenQueue::printArray(){
    cout << "Q Size" getSize() << endl;
    cout << "Front: " << front << endl;
    cout << "Rear: " << rear << endl;
    for(int i = 0; i < mSize; ++i){
        cout << "Q[" << i << "]: " << myQueue[i];
        if(i != mSize-1){
            cout << " | ";
        }
    }
    cout << endl;
}



