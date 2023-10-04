#include <iostream>
#include "MyLinkedList.h"

using namespace std;

int main()
{

    MyLinkedList lista;
    //lista.first();
    //lista.last();
    lista.insertFirst(1);

    cout<<"Head"<<lista.head->data<<endl;
    cout<<"TAIL"<<lista.tail->data<<endl;
    cout<<lista<<endl;
    lista.insertFirst(2);

    cout<<"Head"<<lista.head->data<<endl;
    cout<<"TAIL"<<lista.tail->data<<endl;
    cout<<lista<<endl;
    lista.insertFirst(3);
    cout<<"Head"<<lista.head->data<<endl;
    cout<<"TAIL"<<lista.tail->data<<endl;
    cout<<lista<<endl;
    lista.insertLast(4);
    lista.insertAt(-1,5);
    cout<<"Head"<<lista.head->data<<endl;
    cout<<"TAIL"<<lista.tail->data<<endl;
    lista.insertLast(5);
    cout<<lista<<endl;
    cout<<lista.last()<<endl;
    cout<<"Head"<<lista.head->data<<endl;
    cout<<"TAIL"<<lista.tail->data<<endl;


    cout<<"Head"<<lista.head->data<<endl;
    cout<<"TAIL"<<lista.tail->data<<endl;
    cout<<lista<<endl;
    lista.insertLast(8);
    lista.insertLast(3);
    lista.insertLast(7);
    lista.insertAt(4,10); //REVISAR CUANDO ES EL PRIMERO
    lista.setAt(3,6);
    //lista.removeLast();
    //std::cout<<"En la posicion 3 tenemos="<<lista.getAt(3)<<std::endl;
    //lista.removeAt(3);
    cout<<lista;
    lista.print();

    return 0;
}
