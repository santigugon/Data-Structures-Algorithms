#include "MyStack.h"

void MyStack::push(int data){
    this->lista.insertFirst(data);
}

void MyStack::pop(){
    this->lista.removeFirst();
}

int MyStack()
