//A00572499 Santiago Gutierrez Gonzalez
//Act 1.2 - Algoritmos de Búsqueda y Ordenamiento
//05/09/2023

//Descripción- En este programa usamos los algoritmos de ordenamiento y busqueda mas importantes. Que incluyen el merge
//sort, insertion sort, bubble sort para el ordenamiento y busqueda binaria y secuencial. Incluimos sus respectivas complejidades
//Después se prueba con vectores, ordenandolos y ya ordenados buscamos ciertos números.

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

//Swap- Complejidad de orden Constante(1)
void swap(int& a, int& b){ //Tenemos que poner el amperson aqui para modificar el valor de la variable y no una simple copia
    int tmp=a;
    a=b;
    b=tmp;
}

//ordenaInsecion-Complejidad de orden cuadratica O(n^2)
int ordenaInsercion(vector<int> &numeros){
    int numComp=0;
    int tamanio=numeros.size();
    for(int i=1;i<tamanio;i++){
        for(int j=i-1;j>=0;j--){
            numComp++;
            if(numeros[j+1]<numeros[j]){
                swap(numeros[j+1],numeros[j]);
            }else{
                break;
            }
        }
    }
    return numComp;
}

//ordenaBurbuja- complejidad de orden cuadratica O(n^2)
int ordenaBurbuja(vector<int> &numeros){
    int numComp=0;
    int tamanio=numeros.size();
    bool bandera=true;
    for(int i=0; i<tamanio-1 && bandera;i++){
        bandera=false;
        for(int j=0; j<tamanio-1-i;j++){
            numComp++;
            if(numeros[j]>numeros[j+1]){
                swap(numeros[j],numeros[j+1]);
                bandera=true;
            }
        }
    }
    return numComp;
}

//busqSequncial-complejidad de orden Lineal O(n)
int busqSecuencial(vector<int> &numeros,int n,int &numComp){
   int tamanio= numeros.size();
   for(int i=0;i<tamanio;i++){
        numComp++;
        if(n==numeros[i]){
            return i;
        }
    }
    return -1;
}

//busqBinaria-complejidad de orden logaritmica O(log(n))
int busqBinaria(vector<int> &numeros,int n,int &numComp){
    int tamanio=numeros.size();
    int max= tamanio-1;
    int min= 0;
    int average;
    while(min<=max){
        average=(max+min)/2;
        numComp++;
        if(n==numeros[average]){
            return average;
        }
        if(n>numeros[average]){
            min=average+1;
            numComp++;
        }
        else if(n<numeros[average]){
            max=average-1;
            numComp++;
      }
    }
    return -1;
}

//mezcla-complejidad de orden Lineal O(n)
int mezcla(vector<int> &numeros,int ini, int fin){
    int numComparaciones=0;
    int centro=(ini+fin)/2;
    int j=ini;
    int k=centro+1;
    int tamanio=fin-ini;
    int temp[tamanio+1];

    for(int i=0; i< tamanio+1;i++){
        if(j<=centro && k<=fin){
            if(numeros[j]<numeros[k]){
                numComparaciones++;
                temp[i]=numeros[j++];
            }else if(numeros[k]<numeros[j]){
                numComparaciones++;
                temp[i]=numeros[k++];
            }
        }else if(j>centro){
            temp[i]=numeros[k++];
        }else{
            temp[i]=numeros[j++];
        }
    }
    for(int a=0;a<tamanio+1;a++){
        numeros[ini+a]=temp[a];
    }
    return numComparaciones;

}

//ordenaMerge-complejidad de orden Logaritmica y lineal O(n*log(n))
int ordenaMerge(vector<int> &numeros, int ini, int fin){
    int numComparaciones=0;
    if(ini<fin){
        int centro= (ini+fin)/2;
        numComparaciones+=ordenaMerge(numeros,ini,centro);
        numComparaciones+=ordenaMerge(numeros,centro+1,fin);
        numComparaciones+=mezcla(numeros,ini,fin);
    }
    return numComparaciones;

}

//ordenaMerge-complejidad de orden Logaritmica y lineal O(n*log(n))
int ordenaMerge(vector<int> &numeros){
    int tamanio=numeros.size()-1;
    return ordenaMerge(numeros,0,tamanio);
}

int main(){
	vector<int> v1, v2, v3;
	int n, dato;
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> dato;
		v1.push_back(dato);
		v2.push_back(dato);
		v3.push_back(dato);
	}
	cout << ordenaInsercion(v1) << " " << ordenaBurbuja(v2) << " " << ordenaMerge(v3) << endl;
	int q, pos;
	int cantBS, cantBB;
	cin >> q;
	for (int i=0; i<q; i++){
		cantBS = 0;
		cantBB = 0;
		cin >> dato;
		pos = busqSecuencial(v1, dato, cantBS);
		pos = busqBinaria(v1, dato, cantBB);
		cout << pos << " " << cantBS << " " << cantBB << endl;
	}
}
