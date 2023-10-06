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
