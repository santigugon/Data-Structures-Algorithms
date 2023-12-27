//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 5.2 - Actividad Integral de BST
//26/11/2023

//Descripcion- Este programa almacena las direcciones Ip tomandolas como llaves dentro de un Hash table para posteriormente insertarla en una LL de BSTs donde podremos acceder a las fechas donde hubo un registro de esta Ip en forma creciente


#include <iostream>
#include "MyHashTable.h"
#include "Bitacora.h"


using namespace std;

int main()
{
    //Creamos la bitacora con la HashTable y sus respectivos LL y BST internos
    Bitacora bitacora;
    //Generamos el ciclo de busqueda
    bitacora.busquedaBitacora();
    return 0;
};
