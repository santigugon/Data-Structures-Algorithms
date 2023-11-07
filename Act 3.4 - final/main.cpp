//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 2.3 - Algoritmos de Busqueda y Ordenamiento
//10/10/2023

//Descripcion- Este programa realiza el ordenamiento de un registro de IPs con su respectivo mensaje, este ordenamiento lo realiza en base a las jerarquias de las IPs y posteriormente permite la busqueda en un rango de Ips dando la ip inicial y final


#include <iostream>
#include <vector>
#include <string>
#include "Bitacora.h"
#include <fstream>
#include "NodoIP.h"

int main() {
    string respuesta="Y";
    //Creamos la bitacora que toma ya el archivo por default
    Bitacora bitacora;

    //Ordenamos la lista ligada
    bitacora.mergeSort(bitacora.getNodosIpOrdenada());

    //Creamos el archivo con la bitacora ordenadas

    //Generamos un while para las preguntas que manda llamar la busqueda
    /*
    while(respuesta=="Y" ||respuesta=="y"){

        bitacora.busquedaBitacora();
        cout<<"Deseas realizar otra busqueda? Y/N"<<endl;
        cin>>respuesta;
    }*/
    bitacora.crearArbolNodos();
    bitacora.obtenerMayores(740);

    return 0;
}

