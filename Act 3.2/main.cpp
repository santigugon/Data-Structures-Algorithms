#include <iostream>
#include "MyHeap.h"

using namespace std;

int main()
{
    int lista[8]={5,12,64,1,37,90,91,97};
    int lista2[6]={28,21,17,19,5,8};
    MyHeap hola(lista,8);
    hola.imprimir();
    MyHeap hola2(lista2,6);
    hola2.imprimir();
    cout<<"TOP "<<hola2.top()<<endl;
    hola2.push(29);
    hola2.imprimir();
    cout << "Hello world!" << endl;
    return 0;
}
