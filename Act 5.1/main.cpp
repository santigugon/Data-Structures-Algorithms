#include <iostream>
#include "MyHashTable.h"

using namespace std;

int main()
{
    MyHashTable prueba;
     string key= "8";
    cout<<"La posicion seria en el "<<prueba.getPos(key);
    cout<<" para el key "<<key<<":"<<prueba.get(key)<<endl;

    //CASO 1 ELEMENTO
    prueba.put("12",5);
    cout<<"ESTA VACIO?"<<prueba.isEmpty()?"ESTA VACIO":"No esta vacio"<<endl;
    cout<<"TAMANIO DE LA TABLA "<<prueba.sizeA<<" N ELEMENTOS DENTRO " <<prueba.size<<endl;
    prueba.remove();
    prueba.put("1",1);
    prueba.put("2",2);
    prueba.put("3",3);
    prueba.put("4",4);
    prueba.put("5",12);
    prueba.put("6",6);
    prueba.put("7",7);



    //cout<<"EN La posicion "<< prueba.getPos(key)<<endl;
    //cout<<prueba.tabla[prueba.getPos(key)]<<"MUY POSIBLE ERROR"<<endl;

    cout<<"TAMANIO DE LA TABLA "<<prueba.sizeA<<" N ELEMENTOS DENTRO " <<prueba.size<<endl;
    prueba.put("8",8);
    cout<<"TAMANIO DE LA TABLA "<<prueba.sizeA<<" N ELEMENTOS DENTRO " <<prueba.size<<endl;
    prueba.put("9",9);
     cout<<"TAMANIO DE LA TABLA "<<prueba.sizeA<<" N ELEMENTOS DENTRO " <<prueba.size<<endl;
      prueba.put("10",10);
      cout<<"TAMANIO DE LA TABLA "<<prueba.sizeA<<" N ELEMENTOS DENTRO " <<prueba.size<<endl;

    cout<<endl;
    cout<<"CHEQUEO DE POSICIONES ADECUADAS"<<endl;
    cout<<"La posicion seria en el "<<prueba.getPos(key);
    cout<<" para el key "<<key<<":"<<prueba.get(key)<<endl;
    cout<<"TEST"<<endl;
    cout<<prueba.tabla[8]<<endl;
    prueba.remove(key);
    prueba.remove(key);
     cout<<"ESTA VACIO?"<<prueba.isEmpty()<<endl;
    cout<<"para el key "<<key<<":"<<prueba.get(key)<<endl;

    cout << "Hello world!" << endl;
    return 0;
}
