//SANTIAGO GUTIERREZ GONZALEZ
//MATRICULA:A00572499
//ACT 2.1-Implementacion de un ADT de estructura de datos lineales
//Descripcion- Programa que implementa la estructura de datos de una lista ligada haciendo uso del struct nodo e implementando su metodos
//Fecha: 29/09/2023
#include <iostream>
#ifndef MYLINKEDLIST_H_INCLUDED
#define MYLINKEDLIST_H_INCLUDED

//Aqui generamos el nodo donde se almacena los datos y un apuntador al proximo nodo
struct MyNodoLL
{
    int data;
    MyNodoLL *next;
    //Complejidad de tipo lineal O(1)
    MyNodoLL(int data, MyNodoLL* next){
        this->data=data;
        this->next=next;
    }
    //Complejidad de tipo lineal O(1)
    MyNodoLL(int data):MyNodoLL(data, nullptr){
    }
};

//Clase que almacena los metodos de la lista ligada ademas de atributos importantes como su cabeza o la cola
class MyLinkedList{
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
