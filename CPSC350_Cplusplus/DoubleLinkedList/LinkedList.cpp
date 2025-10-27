#include "LinkedList.h"



LinkedList::LinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

LinkedList::~LinkedList(){

}

void LinkedList::insertFront(int d){
    ListNode *node = new ListNode(d);

    if(isEmpty()){
        back = node;
    }
    else{
        //not an empty list
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}

void LinkedList::insertBack(int d){
    ListNode *node = new ListNode(d);

    if(isEmpty()){
        front = node;
    }
    else{
        //not an empty list
        node->previous = back;
        back->next = node;
    }
    back = node;
    ++size;
}

int LinkedList::removeFront(){
    if(isEmpty()){
        throw runtime_error("List is empty");
    }

    ListNode *temp = front;

    if(front->next = NULL){
        back = NULL;
    }
    else{
        front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    int data = temp->data;
    --size;

    return data;
}

int LinkedList::removeBack(){
    if(isEmpty()){
        throw runtime_error("List is empty");
    }

    ListNode *temp = back;

    if(back->prev = NULL){
        front = NULL;
    }
    else{
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    int data = temp->data;
    --size;

    return data;
}

int LinkedList::find(int value){
    int pos = -1;
    ListNode *curr = front;
}