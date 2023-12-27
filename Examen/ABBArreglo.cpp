//SANTIAGO GUTIERREZ GONZALEZ A00572499
//Examen
//28/11/2023
#include "iostream"
#include <string>

#include "ABBArreglo.h"


using namespace std;

ABBArreglo::ABBArreglo(int nEl){
    this->datos= new int[nEl];
    for(int i=0; i<nEl;i++){
        this->datos[i]=0;
    }
    this->size=0;
    this->length=nEl;
}

void ABBArreglo::crecer(){
    int* aux=this->datos;
    this->datos=new int[this->length*2+1];
    for(int i=0;i<this->length*2+1;i++){
        if(i<this->length){
            this->datos[i]=aux[i];
        }
        else{
            this->datos[i]=0;
        }
    }
    this->length=length*2+1;
}


void ABBArreglo::insertar(int val){
    bool menor=true;
    int pos=0;
    while(menor&& pos<this->length){
        if(this->datos[pos]==0){
            this->datos[pos]=val;
            menor=false;
            this->size++;
        }
        else{
            if(val>this->datos[pos]){
                pos=2*pos+2;
            }
            else if(val<this->datos[pos]){
                pos=2*pos+1;
            }
        }
    }
    if(menor){
        this->crecer();
        insertar(val);
    }

}

int ABBArreglo::buscar(int val){
    bool igual=true;
    int pos=0;
    while(igual&& pos<this->length){
        if(this->datos[pos]==val){
            igual=false;
            return pos;
        }
        else{
            if(val>this->datos[pos]){
                pos=2*pos+2;
            }
            else if(val<this->datos[pos]){
                pos=2*pos+1;
            }
        }
    }
    if(igual){
        return -1;
    }

}

string ABBArreglo::imprimirNivel(){
    string impresion="";
    for(int i=0; i<this->length;i++){
        if(this->datos[i]!=0){
            impresion+=to_string(this->datos[i])+",";
        }
    }
    return impresion;
}
