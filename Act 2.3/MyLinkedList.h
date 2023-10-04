#include "NodoRegistro.h"
#ifndef MYLINKEDLIST_H_INCLUDED
#define MYLINKEDLIST_H_INCLUDED

struct MyNodoLL
{
    NodoRegistro data;
    MyNodoLL *next;
    //Complejidad de tipo lineal O(1)
    MyNodoLL(NodoRegistro data, MyNodoLL* next){
        this->data=data;
        this->next=next;
    }
    //Complejidad de tipo lineal O(1)
    MyNodoLL(NodoRegistro data):MyNodoLL(data, nullptr){
    }
};

class MyLinkedList{
     public:
        int size;
        MyNodoLL* head;
        MyNodoLL* tail;
        MyLinkedList();
        ~MyLinkedList();
        NodoRegistro first();
        NodoRegistro last();
        int length()const;
        bool isEmpty();
        NodoRegistro getAt(int pos);
        void setAt(int pos, NodoRegistro data);
        void insertFirst(NodoRegistro data);
        void insertLast(NodoRegistro data);
        void insertAt(int pos, NodoRegistro data);
        void removeFirst();
        void removeLast();
        void removeAt(int pos);
       // friend std::ostream& operator<<(std::ostream& o,  MyLinkedList& list);

};
#endif // MYLINKEDLIST_H_INCLUDED
