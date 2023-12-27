//A00572499 Santiago Gutierrez Gonzalez y A01281202 Cesar Mecinas Estrada
//Act 5.2 - Actividad Integral de BST
//26/11/2023

//Descripcion- Este programa almacena las direcciones Ip tomandolas como llaves dentro de un Hash table para posteriormente insertarla en una LL de BSTs donde podremos acceder a las fechas donde hubo un registro de esta Ip en forma creciente


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
void MyHashTable::put(string key, MyBST* value){
    this->size++;
    if(float(size)/float(sizeA)>=.75){
        this->rehashing();
    }
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
MyBST* MyHashTable::get(string key){
    if(this->size>0){
        int pos=getPos(key);
        MyNodoLL* aux=this->tabla[pos].head;
        bool notFound=true;
        while(aux!=nullptr){
            if(aux->key==key){

                return aux->data;
            }
            else{
                aux=aux->next;
            }
        }
        MyBST* vacio=new MyBST(key);
        return vacio;
    }
    MyBST* vacio=new MyBST(key);
    return vacio;
    //AGREGAR ARBOL INVALIDO AQUI
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
                this->size--;
                return;
            }
            else{
                aux=aux->next;
            }
            posicion++;
        }
    }
}

