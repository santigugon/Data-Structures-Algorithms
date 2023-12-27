//SANTIAGO GUTIERREZ GONZALEZ A00572499
//Examen
//28/11/2023

#include <iostream>
#include "ABBArreglo.h"

using namespace std;

int main()
{
    ABBArreglo vacio(0);
     cout<<"LA POSICION DE 11 es "<<vacio.buscar(11)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
    int nuevoNum=7;
    vacio.insertar(7);
    cout<<"LA POSICION DE 7 es "<<vacio.buscar(7)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
    nuevoNum=5;
     cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
     nuevoNum=4;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
     nuevoNum=8;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
     nuevoNum=10;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
     nuevoNum=1;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
     nuevoNum=2;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
     nuevoNum=6;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
     nuevoNum=9;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
     nuevoNum=12;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
     nuevoNum=-17;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
    nuevoNum=-11;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;
    nuevoNum=17;
    vacio.insertar(nuevoNum);
    cout<<"LA POSICION DE "<<nuevoNum<< " es "<<vacio.buscar(nuevoNum)<<endl;
    cout << vacio.length<<" SIZE:"<<vacio.size << endl;



     cout << vacio.length<<" SIZE:"<<vacio.size << endl;
    for(int i=0; i<vacio.length;i++){
        cout<<vacio.datos[i]<<",";
    }
    cout<<endl;
    cout<<vacio.imprimirNivel()<<endl;


    ABBArreglo arreglo(5);
    arreglo.insertar(5);
    arreglo.insertar(7);
    arreglo.insertar(14);
    arreglo.insertar(6);
    arreglo.insertar(3);
    arreglo.insertar(11);
    cout<<"LA POSICION DE 15 es "<<arreglo.buscar(11)<<endl;
    //arreglo.insertar(257);
    cout << arreglo.length<<" SIZE:"<<arreglo.size << endl;
    for(int i=0; i<arreglo.length;i++){
        cout<<arreglo.datos[i]<<",";
    }
    cout<<endl;
    cout<<arreglo.imprimirNivel()<<endl;


    for(int i=0; i<arreglo.length;i++){
        cout<<arreglo.datos[i]<<",";
    }

    cout << arreglo.length<<" SIZE:"<<arreglo.size << endl;

    return 0;
}
