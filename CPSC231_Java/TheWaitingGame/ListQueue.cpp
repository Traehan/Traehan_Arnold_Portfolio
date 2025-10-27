#include "ListQueue.h"

template <typename T>
ListQueue<T>::ListQueue() {}

template <typename T>
ListQueue<T>::~ListQueue() {}

template <typename T>
void ListQueue<T>::enqueue(const T& value) {
    list.insertBack(value);
}

template <typename T>
T ListQueue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return list.removeFront();
}

template <typename T>
T ListQueue<T>::peek() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return list.peekFront();
}

template <typename T>
bool ListQueue<T>::isEmpty() {
    return list.isEmpty();
}

template <typename T>
unsigned int ListQueue<T>::getSize() {
    return list.getSize();
}
