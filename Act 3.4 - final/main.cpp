//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 3.4 - Actividad Integral de BST
//7/11/2023

//Descripcion- Este programa realiza el ordenamiento de un registro de IPs con su respectivo mensaje, este ordenamiento lo realiza en base a las jerarquias de las IPs y despues nos permite observar cuales son aquellas con mas frecuencias gracias a un inorder al reves

#include <iostream>
#include <vector>
#include <string>
#include "Bitacora.h"
#include <fstream>

//Complejidad O(n log n) por el ordenamiento que es el peor de las complejidades
void bitacoraFrecuencias(int nIpsAMostrar){
 //Creamos la bitacora que toma ya el archivo por default
    Bitacora bitacora;
    //Ordenamos la lista ligada
    bitacora.mergeSort(bitacora.getNodosIpOrdenada());
    //Creamos la bitacora ordenada a partir de los ips
    bitacora.crearBitacoraOrdenada();
    //Creamos el arbol con los nodos de la frecuencia
    bitacora.crearArbolNodos();
    //Aqui imprimiremos las ips con mayor frecuencia en base al numero que hayamos declarado anteriormente
    bitacora.obtenerMayores(nIpsAMostrar);

}

int main() {
    //Variable a cambiar si queremos modificar el numero de ips a mostrar
    int nIpsAMostrar=5;
    bitacoraFrecuencias(nIpsAMostrar);

    return 0;
}

