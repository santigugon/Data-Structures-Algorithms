#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

//PREGUNTA METODO SWAP
//PREGUNTA TAMANIO

int ordenaInsercion(vector<int> numeros){
    int tamanio=size(numeros)
    for(int i=1;i<tamanio;i++){
        for(int j=i-1;j>=0;j--){
            if(numeros[j+1]<numeros[j]){
                swap(numeros[j+1],numeros[j]);
            }else{
            break;
            }
        }
    }
}
