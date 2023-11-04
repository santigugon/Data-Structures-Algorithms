//A00572499 Santiago Gutierrez Gonzalez
//Act 3.2 - Arbol Heap: Implementando una fila priorizada
//31/10/2023

//Descripcion- En este programa implementamos el ADT de una max_queue en forma de un heap
#include <iostream>
#include "MyHeap.h"

using namespace std;

//Complejidad de tipo constante O(1) en todo caso
MyHeap::MyHeap(){
    this->values=new int[7];
    this->size=0;
    this->len=7;
}

//, Complejidad de tipo logaritmica O(log n) (Peor caso),  complejidad de tipo constante O(1) (Mejor caso) donde no hay que reacomodar los nodos por lo que no hacemos llamada recursiva
void MyHeap::heap(int indice){
    int hijoIzq=(indice+1)*2-1;
    int hijoDer=(indice+1)*2;
    int max=indice;

    if(hijoIzq<this->size&&this->values[indice]<this->values[hijoIzq]){
        max=hijoIzq;
    }
    if(hijoDer<this->size&&this->values[max]<this->values[hijoDer]){
        max=hijoDer;
    }
    if(indice!=max){
        swap(indice,max);
        heap(max);
    }
}

//Complejidad de tipo lineal  logaritmtica O(n log n) (peor caso) ,y es  O(n) (mejor caso ) cuando los nodos ya estan en su posicion en la lista y heap es constante
MyHeap::MyHeap(int* lista, int size){
    this->values=lista;
    this->size=size;
    this->len=size;
    int pivote= (size)/2;
    //Parte lineal O(n)
    for (int i=pivote;i>0;i--){
        //Parte logaritmica O(log n)
        heap(i-1);
    }
}

//Complejidad de tipo constante O(1) en todo caso
void MyHeap::swap(int a, int b){
    int aux=this->values[b];
    this->values[b]=this->values[a];
    this->values[a]=aux;
}

//Complejidad de tipo lineal O(n) en todo caso
  void MyHeap::imprimir(){
        cout<<"arbol size: "<<this->size<<" len:"<<this->len<<endl;
        for(int i=0; i<this->size; i++){
            cout<<values[i]<<",";
        }
        cout<<endl;
}

//Complejidad de tipo constante O(1) en todo caso
int MyHeap::top(){
    if(size!=0)
        return this->values[0];
    else{
        return -1; //Este valor depende del que nosotros queramos asignar para representar que no es parte del heap
    }
}

//Complejidad de tipo logaritmica O(log n) en todo caso
void MyHeap::pop(){
    if(size==0)
        return;
    swap(0,this->size-1);
    this->values[this->size-1]=-500;

    int hijoIzq=1;
    int hijoDer=2;
    int hijoMay=1;

    this->size--;
    bool intercambiado=false;
    int min=0;

    while(!intercambiado){
        if(this->values[hijoDer]>this->values[hijoIzq]){
            hijoMay=hijoDer;
        }
        else if(this->values[hijoIzq]>this->values[hijoDer]){
            hijoMay=hijoIzq;
        }
        if(hijoIzq<this->size&&this->values[min]<this->values[hijoMay]){
            swap(hijoMay,min);
            min=hijoMay;
            hijoIzq=(min+1)*2-1;
            hijoDer=(min+1)*2;
        }
        else{
            intercambiado=true;
            return;
        }
    }
}

//Complejidad de tipo constante O(1) todo caso
int MyHeap::length(){
    return this->size;
}

//Complejidad de tipo constante O(1) todo caso
bool MyHeap::isEmpty(){
    return this->size==0;
}

//Complejidad de tipo logaritmica O(log n) si no tenemos que crecer (mejor caso), cuando se tiene que crecer el arreglo seria O(n) (peor caso)
void MyHeap::push(int n){
    if(this->len==this->size){
        this->len=this->len*2+1;
        int* arregloAnterior=this->values;
        this->values=new int[this->len];
        for(int i=0;i<this->size;i++){
            this->values[i]=arregloAnterior[i];
        }
    }
    this->size++;
    int indInser=this->size-1;
    int padre=(indInser-1)/2;
    this->values[indInser]=n;
    bool ordenado=false;
    while(!ordenado){
        if(this->values[padre]<this->values[indInser]&&indInser!=padre){
            swap(padre,indInser);
            indInser=padre;
            padre=(padre-1)/2;
        }
        else{
            ordenado=true;
        }
    }
}

