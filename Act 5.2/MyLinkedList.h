//SANTIAGO GUTIERREZ GONZALEZ
//MATRICULA:A00572499
//ACT 5.1-Implementacion individual de operaciones sobre conjuntos
//Descripcion- Programa que sirve para implementar la insercion y busqueda de elementos en un HashTable
//Fecha: 21/11/2023
#include <iostream>
#ifndef MYLINKEDLIST_H_INCLUDED
#define MYLINKEDLIST_H_INCLUDED
#include "string"
#include "MyBST.h"

using namespace std;
//Aqui generamos el nodo donde se almacena los datos y un apuntador al proximo nodo
struct MyNodoLL
{
    MyBST* data;

    string key;
    MyNodoLL *next;
    //Complejidad de tipo lineal O(1)
    MyNodoLL(MyBST* data,string key, MyNodoLL* next){
        this->data=data;
        this->next=next;
        this->key=key;
    }
    //Complejidad de tipo lineal O(1)
    MyNodoLL(MyBST* data,string key):MyNodoLL(data,key, nullptr){
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
        void deleteLinkedList();
        MyBST* first();
        MyBST* last();
        int length()const;
        bool isEmpty();
        MyBST* getAt(int pos);
        void setAt(int pos, MyBST* data,string key);
        void insertFirst(MyBST* data,string key);
        void insertLast(MyBST* data,string key);
        void insertAt(int pos, MyBST* data,string key);
        void removeFirst();
        void removeLast();
        void removeAt(int pos);
        friend std::ostream& operator<<(std::ostream& o, const MyLinkedList& list);
        void print();
        void flush();
};


#endif // MYLINKEDLIST_H_INCLUDED
