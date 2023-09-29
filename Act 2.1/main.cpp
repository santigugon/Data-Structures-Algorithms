#include <iostream>
#include "MyLinkedList.h"

using namespace std;

int main()
{

    MyLinkedList lista;
    lista.insertFirst(4);
    lista.insertLast(8);
    lista.insertLast(3);
    lista.insertLast(7);
    lista.insertAt(4,10); //REVISAR CUANDO ES EL PRIMERO
    lista.setAt(3,6);
    //lista.removeLast();
    //std::cout<<"En la posicion 3 tenemos="<<lista.getAt(3)<<std::endl;
    cout<<"TAIL"<<lista.tail->data<<endl;
    //lista.removeAt(3);
    cout<<lista;
    lista.print();

    return 0;
}
