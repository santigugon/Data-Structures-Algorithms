//SANTIAGO GUTIERREZ GONZALEZ
//MATRICULA:A00572499
//ACT 2.1-Implementacion de un ADT de estructura de datos lineales
//Descripcion- Programa que implementa la estructura de datos de una lista ligada haciendo uso del struct nodo e implementando su metodos
//Fecha: 29/09/2023
#include "MyLinkedList.h"
#include <iostream>
using namespace std;

//Complejidad de tipo constante O(1)
MyLinkedList::MyLinkedList(){
    this->size=0;
    this->head=this->tail=nullptr;
}

//Complejidad de tipo lineal O(n)
MyLinkedList::~MyLinkedList(){
    while(!this->isEmpty()){
        this->removeFirst();
    }
}

//Complejidad de tipo constante O(1)
int MyLinkedList::first(){
    if(!this->isEmpty()){
        return this->head->data;
    }else{
        throw std::invalid_argument("La lista esta vacia, no hay un primer elemento");
    }
}

//Complejidad de tipo constante O(1)
int MyLinkedList::last(){
    if(!this->isEmpty()){
        return this->tail->data;
    }else{
        throw std::invalid_argument("La lista esta vacia, no hay un ultimo elemento");
    }
}

//Complejidad de tipo constante O(1)
int MyLinkedList::length()const{
    return this->size;
}

//Complejidad de tipo constante O(1)
bool MyLinkedList::isEmpty(){
   return this->size==0;
}

//Complejidad de tipo constante O(1)
void MyLinkedList::insertFirst(int data){
    this->head= new MyNodoLL(data, this->head);
    if(this->size==0){
        this->tail=this->head;
    }
    this->size++;
}

//Complejidad de tipo constante O(1)
void MyLinkedList::insertLast(int data){
    MyNodoLL* nodoFinal=new MyNodoLL (data);
    this->tail->next=nodoFinal;
    this->tail= nodoFinal;
    if(this->size==0){
        this->head=this->tail;
    }
    this->size++;

}

//Complejidad de tipo lineal O(n)
void MyLinkedList::insertAt(int pos, int data){
    if(pos>this->size||pos<0){
        throw std::invalid_argument("La posicion es mas grande que la lista o menor a 0 " );//,pos, " en una lista de tamaño ", this->size
    }
    else{
        if(pos==0){
            this->insertFirst(data);
        }
        else if(pos==this->size){
            this->insertLast(data);
        }
        else{
            MyNodoLL* nodoNuevo= new MyNodoLL(data);
            MyNodoLL* actual=this->head;
            int posActual=0;
            actual=head;
            while(posActual<pos-1){
                actual=actual->next;
                posActual++;
            }
            nodoNuevo->next=actual->next;
            actual->next=nodoNuevo;
            this->size++;
        }
    }
}

//Complejidad de tipo constante O(1)
void MyLinkedList::removeFirst(){
    if(!this->isEmpty()){
        MyNodoLL* aux=this->head;
        this->head=this->head->next;
        delete aux;
        this->size--;
        if(this->size==0){
            this->tail=nullptr;
        }
    }
    else{
        throw std::invalid_argument("La lista esta vacia, no se puede borrar su primer elemento");
    }
}

//Complejidad de tipo lineal O(n)
void MyLinkedList::removeLast(){
    if(!this->isEmpty()){
        MyNodoLL* lastEl=this->tail;
        MyNodoLL* aux=this->head;
        while(aux->next!=this->tail){
            aux=aux->next;
        }
        aux->next=nullptr;
        this->tail=aux;
        delete lastEl;
        this->size--;
    }
    else{
        throw std::invalid_argument("La lista esta vacia, no se puede borrar su ultimo elemento");
    }
}

//Complejidad de tipo lineal O(n)
void MyLinkedList::removeAt(int pos){
    if(pos>=this->size||pos<0){
        throw std::invalid_argument("La posicion indicada no es valida o la lista esta vacia");
    }else{
        if(pos==0){
            this->removeFirst();
        }
        else if(pos==this->size-1){
            this->removeLast();
        }else{
            int posI=0;
            MyNodoLL* aux=this->head;
            while(posI<pos-1){
                aux=aux->next;
                posI++;
            }
            MyNodoLL* elRemove= aux->next;
            aux->next=elRemove->next;
            delete elRemove;
            this->size--;
        }
    }
}


//Complejidad de tipo lineal O(n)
std::ostream& operator << (std::ostream& o, const MyLinkedList& list)
{
    MyNodoLL* actual=list.head;
    for(int i=0;i<list.length();i++){
        o<<actual->data<<",";
        actual=actual->next;
    }
    return o;
}

//Complejidad de tipo lineal O(n)
int MyLinkedList::getAt(int pos){
    if(pos>=this->size||pos<0){
        throw std::invalid_argument("La posicion indicada no es valida o la lista esta vacia");
    }
    else{
        int posI=0;
        MyNodoLL* aux=this->head;
        while(posI<pos){
            aux=aux->next;
            posI++;
        }
        return aux->data;
    }

}

//Complejidad de tipo lineal O(n)
void MyLinkedList::setAt(int pos, int data){
    if(pos>=this->size||pos<0){
        throw std::invalid_argument("La posicion indicada no es valida o la lista esta vacia");
    }
    else{
        int posI=0;
        MyNodoLL* aux=this->head;
        while(posI<pos){
            aux=aux->next;
            posI++;
        }
        aux->data=data;
    }
}



