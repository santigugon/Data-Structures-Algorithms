#include <iostream>
#include "MyLinkedList.h"

using namespace std;

int main()
{

    MyLinkedList lista;
    //lista.first();
    //lista.removeFirst();
    lista.insertFirst(1);
 cout<<"LENGHT "<<lista.length()<<endl;
    cout<<"Head"<<lista.head->data<<endl;

    cout<<"TAIL"<<lista.tail->data<<endl;
    cout<<lista<<endl;
    lista.insertFirst(2);
 cout<<"LENGHT "<<lista.length()<<endl;
    cout<<"Head"<<lista.head->data<<endl;
    cout<<"TAIL"<<lista.tail->data<<endl;
    cout<<lista<<endl;
    lista.insertFirst(3);
     cout<<"LENGHT "<<lista.length()<<endl;
    cout<<"Head"<<lista.head->data<<endl;
    cout<<"TAIL"<<lista.tail->data<<endl;
    cout<<lista<<endl;
    lista.insertLast(4);
     cout<<"LENGHT "<<lista.length()<<endl;
    lista.insertAt(4,5);
    cout<<lista<<endl;
    cout<<"LENGHT aq "<<lista.length()<<endl;
    cout<<"Head"<<lista.head->data<<endl;
    cout<<"TAIL"<<lista.tail->data<<endl;
    lista.insertLast(5);
    cout<<lista<<endl;
     cout<<"LENGHT "<<lista.length()<<endl;
    cout<<lista.last()<<endl;
    lista.removeAt(5);
cout<<"LENGHT "<<lista.length()<<endl;
    cout<<lista<<endl;
    lista.removeLast();
    cout<<"LENGHT "<<lista.length()<<endl;
    lista.removeFirst();
    cout<<"LENGHT "<<lista.length()<<endl;
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
    //std::cout<<"En la posicion 3 tenemos="<<lista.getAt(3)<<std::endl;
    //lista.removeAt(3);
    cout<<lista;

    return 0;
}
