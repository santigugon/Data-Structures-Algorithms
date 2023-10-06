#include <iostream>
#include <vector>
#include <string>
#include "Bitacora.h"
#include <fstream>

int main() {
    cout<<"Hola mundo"<<endl;
    string respuesta="Y";
    Bitacora bitacora;

    bitacora.mergeSort(bitacora.getNodosIpOrdenada());
    bitacora.crearBitacoraOrdenada();


    while(respuesta=="Y" ||respuesta=="y"){

    bitacora.busquedaBitacora();
    cout<<"Deseas realizar otra busqueda? Y/N"<<endl;
    cin>>respuesta;
    }

    return 0;
}
//650.44.964.36:6943
//679.51.274.19:5851

//95.83.314.79:6429
//101.80.401.84:5919

//ESPACIOS AL FINAL DEL DOCUMENTO
