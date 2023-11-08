//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 3.4 - Actividad Integral de BST
//7/11/2023

//Descripcion- Este programa realiza el ordenamiento de un registro de IPs con su respectivo mensaje, este ordenamiento lo realiza en base a las jerarquias de las IPs y despues nos permite observar cuales son aquellas con mas frecuencias gracias a un inorder al reves

#include "MyLinkedList.h"
#include "NodoRegistro.h"
#include "MyBST.h"
#include <fstream>
using namespace std;

#ifndef BITACORA_H_INCLUDED
#define BITACORA_H_INCLUDED

class Bitacora{
    private:
        ifstream archivo;
        MyLinkedList nodosIpNuevoOrden;
        MyNodoLL* ptr;
        MyNodoLL* ptr2;
        MyLinkedList nodosIpOrdenada;
        MyBST arbolNodos;
        int contador=0;
    public:
        Bitacora();
        void mergeSort(MyNodoLL**);
        void mezcla(MyNodoLL* primero, MyNodoLL** ini, MyNodoLL** fin);
        MyNodoLL* mergeSort(MyNodoLL*,MyNodoLL*);
        MyNodoLL** getNodosIpOrdenada();
        void imprimirLista();
        void crearBitacoraOrdenada();
        void busquedaBitacora();
        void crearArbolNodos();
        void obtenerMayores(int n);


};


#endif // BITACORA_H_INCLUDED
