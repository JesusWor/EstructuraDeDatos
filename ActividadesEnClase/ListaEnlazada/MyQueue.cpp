#include "MyQueue.h"

void MyQueue::enqueue(int data){
    this->lista.insertLast(data);
}

void MyQueue::dequeue(){
    this->lista.removeFirst();
}

int MyQueue::peek(){
    return this->lista.first();
}

//O(1)
bool MyQueue::isEmpty(){
    return this->lista.isEmpty();
}

//O(n)
int MyQueue::length(){
    return this->lista.length();
}

void MyQueue::flush(){
    while(!isEmpty()){
        lista.removeFirst();
    }
}