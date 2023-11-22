//SANTIAGO GUTIERREZ GONZALEZ
//MATRICULA:A00572499
//ACT 5.1-Implementacion individual de operaciones sobre conjuntos
//Descripcion- Programa que sirve para implementar la insercion y busqueda de elementos en un HashTable
//Fecha: 21/11/2023


#include "MyLinkedList.h"
#include "MyHashTable.h"

//Peor Caso y medio:Complejidad de tipo constante O(1)
MyHashTable::MyHashTable(){
    this->size=0;
    this->sizeA=11;
    this->tabla=new MyLinkedList[sizeA];

}

//Peor Caso y medio:Complejidad de tipo lineal O(n)
MyHashTable::~MyHashTable() {

    for (int i = 0; i < this->sizeA; i++) {
        if (this->tabla[i].head != nullptr) {
            tabla[i].deleteLinkedList();  // Destruye cada lista enlazada de la tabla
        }
    }
    delete[] this->tabla;
}

//Complejidad de tipo lineal O(n)
void MyHashTable::rehashing(){
    int oldSize=sizeA;
    this->sizeA=sizeA*2+1;
    MyLinkedList* tablaProv= this->tabla;
    this->tabla=new MyLinkedList[this->sizeA];
    int nuevaPos;
    for(int i=0; i<oldSize;i++){
        MyNodoLL* aux=tablaProv[i].head;
        while(aux!=nullptr){
            nuevaPos=this->getPos(aux->key);
            this->tabla[nuevaPos].insertLast(aux->data,aux->key);
            aux=aux->next;
        }
    }
    delete[] tablaProv;
}

//Complejidad de tipo constante O(1)
bool MyHashTable::isEmpty(){
    return this->size==0;
}

//Complejidad caso medio de tipo constante O(1)
//Complejidad peor caso de tipo lineal O(n)
void MyHashTable::put(string key, int value){
    this->size++;
    cout<<"FACTOR DE BALANCEO ANTES "<<float(size)/float(sizeA)<<endl;
    if(float(size)/float(sizeA)>=.75){
        this->rehashing();
    }
    cout<<"FACTOR DE BALANCEO DESPUES "<<float(size)/float(sizeA)<<endl;
    int hashKey=getPos(key);
    tabla[hashKey].insertLast(value,key);

}

//Peor Caso y medio:Complejidad de tipo O(1)
int MyHashTable::getPos(string key){
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}

//Complejidad caso medio de tipo constante O(1)
//Complejidad peor caso de tipo lineal O(n)
int MyHashTable::get(string key){
    if(this->size>0){
        int pos=getPos(key);
        MyNodoLL* aux=this->tabla[pos].head;
        bool notFound=true;
        while(aux!=nullptr){
            if(aux->key==key){

                return aux->data;
            }else{
                aux=aux->next;
            }
        }
    }
    return -1;
}

//Complejidad caso medio de tipo constante O(1)
//Complejidad peor caso de tipo lineal O(n)
void MyHashTable::remove(string key){
      if(this->size>0){
        int pos=getPos(key);
        MyNodoLL* aux=this->tabla[pos].head;
        bool notFound=true;
        int posicion=0;
        while(aux!=nullptr && notFound){
            if(aux->key==key){
                notFound=false;
                this->tabla[pos].removeAt(posicion);
            }
            else{
                aux=aux->next;
            }
            posicion++;
        }
    }
}

