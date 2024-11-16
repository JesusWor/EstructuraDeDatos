#include "MyStack.h"

void MyStack::push(int data){
    this->lista.insertFirst(data);
}

void MyStack::pop(){
    this->lista.removeFirst();
}

int MyStack::top(){
    return this->lista.first();
}

bool MyStack::isEmpty(){
    return this->lista.isEmpty();
}

int MyStack::length(){
    return this->lista.length();
}

void MyStack::flush(){
    while(!isEmpty()){
        lista.removeFirst();
    }
}