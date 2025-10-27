#include "DblList.h"

template <typename T>
DblList<T>::DblList() : front(nullptr), back(nullptr), size(0) {}

template <typename T>
DblList<T>::~DblList() {
    while (!isEmpty()) {
        removeFront();
    }
}

template <typename T>
void DblList<T>::insertFront(const T& value) {
    ListNode<T>* newNode = new ListNode<T>(value);
    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

template <typename T>
void DblList<T>::insertBack(const T& value) {
    ListNode<T>* newNode = new ListNode<T>(value);
    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        newNode->prev = back;
        back->next = newNode;
        back = newNode;
    }
    size++;
}

template <typename T>
T DblList<T>::removeFront() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    ListNode<T>* temp = front;
    T value = temp->data;
    if (front == back) {
        front = nullptr;
        back = nullptr;
    } else {
        front = front->next;
        front->prev = nullptr;
    }
    delete temp;
    size--;
    return value;
}

template <typename T>
T DblList<T>::removeBack() {
    if (isEmpty()) {
        throw std::out_of_range("List is empty");
    }
    ListNode<T>* temp = back;
    T value = temp->data;
    if (front == back) {
        front = nullptr;
        back = nullptr;
    } else {
        back = back->prev;
        back->next = nullptr;
    }
    delete temp;
    size--;
    return value;
}

template <typename T>
bool DblList<T>::removeNode(const T& value) {
    ListNode<T>* current = front;
    while (current != nullptr) {
        if (current->data == value) {
            if (current == front) {
                removeFront();
            } else if (current == back) {
                removeBack();
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                size--;
            }
            return true;
        }
        current = current->next;
    }
    return false; // Node with given value not found
}

template <typename T>
bool DblList<T>::find(const T& value) {
    ListNode<T>* current = front;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
bool DblList<T>::isEmpty() {
    return size == 0;
}

template <typename T>
unsigned int DblList<T>::getSize() {
    return size;
}

template <typename T>
void DblList<T>::printList(bool printLink) {
    ListNode<T>* current = front;
    while (current != nullptr) {
        std::cout << current->data << " ";
        if (printLink && current->next != nullptr) {
            std::cout << "<-> ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}