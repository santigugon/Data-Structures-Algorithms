#include <iostream>
#ifndef MYLINKEDLIST_H_INCLUDED
#define MYLINKEDLIST_H_INCLUDED

struct MyNodoLL
{
    int data;
    MyNodoLL *next;

    MyNodoLL(int data, MyNodoLL* next){
    this->data=data;
    this->next=next;
    }
    MyNodoLL(int data):MyNodoLL(data, nullptr){
    }
};

class MyLinkedList{ //Nos servira para guardar el inicio de la lista
     public:
        int size;
        MyNodoLL* head;
        MyNodoLL* tail;

        MyLinkedList();
        ~MyLinkedList();
        int first();
        int last();
        int length()const;
        bool isEmpty();
        int getAt(int pos);
        void setAt(int pos, int data);
        void insertFirst(int data);
        void insertLast(int data);
        void insertAt(int pos, int data);
        void removeFirst();
        void removeLast();
        void removeAt(int pos);
        friend std::ostream& operator<<(std::ostream& o, const MyLinkedList& list);
        void print();
        void flush();

};


#endif // MYLINKEDLIST_H_INCLUDED
