#ifndef MYSTACK_H_INCLUDED
#define MYSTACK_H_INCLUDED
#include "MyLinkedList.h"

class MyStack{
    private:
        MyLinkedList lista;
    public:
        ~MyStack();
        void push(int data);
        void pop();
        int top();
        bool isEmpty();
        void flush();


};


#endif // MYSTACK_H_INCLUDED
