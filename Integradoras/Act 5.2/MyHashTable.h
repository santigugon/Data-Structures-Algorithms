//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 5.2 - Actividad Integral de BST
//26/11/2023

//Descripcion- Este programa almacena las direcciones Ip tomandolas como llaves dentro de un Hash table para posteriormente insertarla en una LL de BSTs donde podremos acceder a las fechas donde hubo un registro de esta Ip en forma creciente

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
    void put(string key,MyBST* value);
    MyBST* get(string key);
    void remove(string key);
};


#endif // MYHASHTABLE_H_INCLUDED
