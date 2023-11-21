#ifndef MYHASHTABLE_H_INCLUDED
#define MYHASHTABLE_H_INCLUDED
#include "MyLinkedList.h"
#include <iostream>
#include "string"

using namespace std;

class MyHashTable{
    public://Recuerden que esto sólo lo hacemos para poder revisar las actividades pero debería ser público
    MyLinkedList* tabla;
    int size; //Cantidad de valores que hay almacenados en la tabla
    int sizeA; //Cantidad del arreglo
    void rehashing(); //Crece el arreglo al doble del tamaño del arreglo actual + 1
    int getPos(string key);

    MyHashTable();  //Tamaño inicial 11
    ~MyHashTable();
    bool isEmpty();
    void put(string key,int value);
    int get(string key);
    void remove(string key);
};


#endif // MYHASHTABLE_H_INCLUDED
