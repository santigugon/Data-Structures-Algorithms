//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 5.2 - Actividad Integral de BST
//26/11/2023

//Descripcion- Este programa almacena las direcciones Ip tomandolas como llaves dentro de un Hash table para posteriormente insertarla en una LL de BSTs donde podremos acceder a las fechas donde hubo un registro de esta Ip en forma creciente

#include "MyLinkedList.h"
#include "MyBST.h"
#include "MyHashTable.h"
#include <fstream>
using namespace std;

#ifndef BITACORA_H_INCLUDED
#define BITACORA_H_INCLUDED

class Bitacora{
    private:
        MyHashTable* tablaRegistros;
        ifstream archivo;
    public:
        Bitacora();
        void busquedaBitacora();

};


#endif // BITACORA_H_INCLUDED
