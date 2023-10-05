#include "MyLinkedList.h"
#include "NodoRegistro.h"
#include <fstream>
using namespace std;

#ifndef BITACORA_H_INCLUDED
#define BITACORA_H_INCLUDED

class Bitacora{
    private:
        ifstream archivo;
        MyLinkedList nodosIpOrdenada;
    public:
        Bitacora();

};


#endif // BITACORA_H_INCLUDED
