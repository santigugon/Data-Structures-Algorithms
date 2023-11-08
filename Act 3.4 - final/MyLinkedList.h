//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 3.4 - Actividad Integral de BST
//7/11/2023

//Descripcion- Este programa realiza el ordenamiento de un registro de IPs con su respectivo mensaje, este ordenamiento lo realiza en base a las jerarquias de las IPs y despues nos permite observar cuales son aquellas con mas frecuencias gracias a un inorder al reves


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
        void print();


};
#endif // MYLINKEDLIST_H_INCLUDED
