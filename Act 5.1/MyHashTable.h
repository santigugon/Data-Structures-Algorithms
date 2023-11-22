//SANTIAGO GUTIERREZ GONZALEZ
//MATRICULA:A00572499
//ACT 5.1-Implementacion individual de operaciones sobre conjuntos
//Descripcion- Programa que sirve para implementar la insercion y busqueda de elementos en un HashTable
//Fecha: 21/11/2023

#ifndef MYHASHTABLE_H_INCLUDED
#define MYHASHTABLE_H_INCLUDED
#include <list>
#include <iostream>
#include "MyLinkedList.h"
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
