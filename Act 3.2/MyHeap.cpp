#include <iostream>
#include "MyHeap.h"

using namespace std;

MyHeap::MyHeap(){
this->values=new int[7];
}

void MyHeap::heap(int indice){
    int hijoIzq=(indice+1)*2-1;
    int hijoDer=(indice+1)*2;
    int max=indice;

    cout<<this->values[indice]<<"<"<<this->values[hijoIzq]<<endl;
    cout<<this->values[indice]<<"<"<<this->values[hijoDer]<<endl;
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

MyHeap::MyHeap(int* lista, int size){
    this->values=lista;
    this->size=size;
    this->len=size;
    int pivote= (size)/2;
    for (int i=pivote;i>0;i--){
        heap(i-1);
        cout<<i<<endl;
    }
}


void MyHeap::swap(int a, int b){
    int aux=this->values[b];
    this->values[b]=this->values[a];
    this->values[a]=aux;
}

  void MyHeap::imprimir(){
        cout<<"arbol size: "<<this->size<<" len:"<<this->len<<endl;
        for(int i=0; i<this->size; i++){
            cout<<values[i]<<",";
        }
        cout<<endl;
}

int MyHeap::top(){
    return this->values[0];
}

void MyHeap::pop(){
    cout<<this->size<<endl;
    swap(0,this->size-1);
    this->values[this->size-1]=-500;
    int hijoIzq=1;
    int hijoDer=2;
    bool intercambiado=false;
    int min=0;
    this->size--;
    while(!intercambiado){
        if(hijoDer<this->size&&this->values[hijoIzq]>this->values[min]){
            swap(hijoIzq,min);
            min=hijoIzq;
            hijoIzq=(min+1)*2-1;
            hijoDer=(min+1)*2;
        }else if(hijoDer<this->size&&this->values[hijoDer]>this->values[min]){
            swap(hijoDer,min);
            min=hijoDer;
            hijoIzq=(min+1)*2-1;
            hijoDer=(min+1)*2;
        }else{

            intercambiado=true;
            return;
        }
        cout<<"Hijo izq"<<hijoIzq<<" hijo der"<<hijoDer<<endl;
    }
    //Eliminar elemento en size-1
}

int MyHeap::length(){
    return this->size;
}

bool MyHeap::isEmpty(){
    return this->size>0;
}

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
    int padre=indInser/2;
    this->values[indInser]=n;
    bool ordenado=false;
    while(!ordenado){
        if(this->values[padre]<this->values[indInser]){
            swap(padre,indInser);
            indInser=padre;
            padre=padre/2;
        }else{
            ordenado=true;
        }
    }

}

