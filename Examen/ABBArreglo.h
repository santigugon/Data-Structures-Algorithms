//SANTIAGO GUTIERREZ GONZALEZ A00572499
//Examen
//28/11/2023
#include <iostream>
#include <string>

using namespace std;

#ifndef ABBARREGLO_H_INCLUDED
#define ABBARREGLO_H_INCLUDED

class ABBArreglo{
private:

public:
    int* datos;
    int size;
    int length;

    ABBArreglo(int nElementos);
    void insertar(int val);
    int buscar(int valor);
    string imprimirNivel();
    void crecer();

};


#endif // ABBARREGLO_H_INCLUDED
