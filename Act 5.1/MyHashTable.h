#ifndef MYHASHTABLE_H_INCLUDED
#define MYHASHTABLE_H_INCLUDED
#include "MyLinkedList.h"
#include <iostream>
#include "string"

using namespace std;

class MyHashTable{
    public://Recuerden que esto s�lo lo hacemos para poder revisar las actividades pero deber�a ser p�blico
    MyLinkedList* tabla;
    int size; //Cantidad de valores que hay almacenados en la tabla
    int sizeA; //Cantidad del arreglo
    void rehashing(); //Crece el arreglo al doble del tama�o del arreglo actual + 1
    int getPos(string key);

    MyHashTable();  //Tama�o inicial 11
    ~MyHashTable();
    bool isEmpty();
    void put(string key,int value);
    int get(string key);
    void remove(string key);
};


#endif // MYHASHTABLE_H_INCLUDED
