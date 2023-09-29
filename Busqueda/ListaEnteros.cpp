#include 'ListaEnteros.h'
#include <iostream>
using namespace std;

ListaEnteros::ListaEnteros(int length){

    this->length=length;
    this->valores=new int[length];
}

ListaEnteros::ListaEnteros(int length,int valores[]){

    this->length=length;
    this->valores=new int[length];
    for(int i=0;i<length;i++){
        this->valores[i]=valores[i];
    }
    this->size=length;
}

void ListaEnteros::imprimir(){
    for(int i=0; i<size;i++){
        cout<<this->valores[i]<<" , ";
    }
    cout<<endl;
}

int ListaEnteros::busquedaSec(int valor){
    for(int i=0;i<<size;i++){
        if(valor==valores[i]){
            return i;
        }
    }
    return -1;
}

int ListaEnteros::busquedaBinIt(int valor){
    int max= this->size;
    int min= 0;
    int average= (max+min)/2;

    for(int i=0;i<100;i++){
      if(valor==valores[average]){
        return average;
      }else if(valor>valores[average]){
        min=average+1;
        average=(max+min)/2
      }
      else if(valor<valores[average]){
        max=average-1;
        average=(max+min)/2
      }
    }

}

int ListaEnteros::busquedaBinSec(int valor){


}
//CASO BASE if(valores[average]==valor){
     //   return average
   //}
