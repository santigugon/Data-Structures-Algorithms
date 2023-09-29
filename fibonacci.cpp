#include "iostream";
using namespace std;




unsigned long fibo(int n){
if(n==1){
return 1;
}
if(n==0){
return 1;
}

return fibo(n-2)+fibo(n-1);

}

unsigned long preparacionFibo(n){
unsigned long tabla[n+1];
for(int i=0;i<n;i++){
tabla[i]=0;

}


}



int main(){
int nSerie;
cout<<"Ingresa el numero de la serie a calcular ";
cin>>nSerie;
//cout<<"El resultado es "<<fibo(nSerie)<<endl;
int iterador=0;
int numAnterior=1;
int dosNumAnterior=1;

unsigned long fN=0;
for(iterador;iterador<nSerie-1;iterador++){

fN=numAnterior+dosNumAnterior;
dosNumAnterior=numAnterior;
numAnterior=fN;

}

cout<<"El resultado con interador es "<<fN;
return 0;


}
