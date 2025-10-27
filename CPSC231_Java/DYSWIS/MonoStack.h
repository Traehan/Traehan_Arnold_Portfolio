#ifndef MONO_STACK_H
#define MONO_STACK_H
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

template <typename T>
class MonoStack{
    public:
        MonoStack(int iSize);
        ~MonoStack();
        void push(T value); //adds to the top
        T pop(); //removes from the top
        T peek(); //returns the top without removing
        bool isFull();
        bool isEmpty();
        int size();
        void printStackStatus(int columnNumber);

    private:
        T* stackArr;
        int count; //# of items currently in the stack
        int maxSize; //max number of things in the stack
        int top; //value of the current top of the stack
};


template <typename T>
MonoStack<T>::MonoStack(int iSize){
    stackArr = new T[iSize];
    maxSize = iSize;
    count = 0;
    top = -1;
}
template <typename T>
MonoStack<T>::~MonoStack(){
    std::cout << "clearing a TStack obj!" << std::endl;
    delete[] stackArr;
}

template <typename T>
bool MonoStack<T>::isFull(){
    return (count == maxSize);
}
template <typename T>
bool MonoStack<T>::isEmpty(){
    return (count == 0);
}
template <typename T>
int MonoStack<T>::size(){
    return count;
}
template <typename T>
void MonoStack<T>::push(T value){
    if (isEmpty() || value > stackArr[top]) {
        stackArr[++top] = value;
        ++count;
    }
}
template <typename T>
T MonoStack<T>::pop(){
    --count;
    return stackArr[top--];
}
template <typename T>
T MonoStack<T>::peek(){
    return stackArr[top];
}

template <typename T>
void MonoStack<T>::printStackStatus(int columnNumber) {
    cout << "In column " << columnNumber << ", there are " << count << " that can see. Their heights are: ";
    for (int i = 0; i < count; i++) {
        if (i == count-1) {
            cout << stackArr[i] << " inches." << endl;
        } else {
            cout << stackArr[i] << ", ";
        }
    }
}
#endif