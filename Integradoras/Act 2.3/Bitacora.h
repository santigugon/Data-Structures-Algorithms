//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 2.3 - Algoritmos de Busqueda y Ordenamiento
//10/10/2023

//Descripcion- Este programa realiza el ordenamiento de un registro de IPs con su respectivo mensaje, este ordenamiento lo realiza en base a las jerarquias de las IPs y posteriormente permite la busqueda en un rango de Ips dando la ip inicial y final


#include "MyLinkedList.h"
#include "NodoRegistro.h"
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


};


#endif // BITACORA_H_INCLUDED
