#include <iostream>


using namespace std;
class ListaEnteros{
    private:
        int* valores;
        int length; //Hasta cuantos elementos necesito guardar en mi arreglo
        int size; //Tamaño actual del arreglo
        void mergeSort(int inicio, int fin);
        void mezcla(int ini, int fin);
    public:
        ListaEnteros(int length);
        ListaEnteros(int length, int valores[]);
        void imprimir();
        int busquedaSec(int valor);
        int busquedaBinIt(int valor);
        int busquedaBinRec(int valor);
        void bubbleSort();
        void swap(int& a,int& b);
        void selectionSort();
        void insertionSort();
        void mergeSort(); //Está es la función de preparación que manda llamar la config. inicial.


};

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
    for(int i=0;i<size;i++){
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
        average=(max+min)/2;
      }
      else if(valor<valores[average]){
        max=average-1;
        average=(max+min)/2;
      }
    }

}

int ListaEnteros::busquedaBinRec(int valor){

    int max= this->size;
    int min= 0;
    //if(average)
    //if(posicion>=size){
      //  return -1;
     //}
    int average= (max+min)/2;


}

void ListaEnteros::swap(int& a, int& b){ //Tenemos que poner el amperson aqui para modificar el valor de la variable y no una simple copia
    int tmp=a;
    a=b;
    b=tmp;
}

void ListaEnteros::bubbleSort(){
    bool bandera=true;
    for(int i=0; i<this->size-1 && bandera;i++){
        bandera=false;
        for(int j=0; j<this->size-1-i;j++){
            if(this->valores[j]>this->valores[j+1]){
                this->swap(valores[j],valores[j+1]);
                bandera=true;
            }
        }
    }
}

void ListaEnteros::selectionSort(){
    int minimo;
    for(int i=0;i<this->size-1;i++){
        minimo=i;
        for(int j=1+i;j<this->size;j++){
            if(valores[minimo]>valores[j]){
               minimo=j;
            }
        }
         swap(valores[minimo],valores[i]);
    }

}

void ListaEnteros::insertionSort(){
    for(int i=1;i<size;i++){
        for(int j=i-1;j>=0;j--){
            if(valores[j+1]<valores[j]){
                swap(valores[j+1],valores[j]);
            }else{
            break;
            }
        }
    }
}

void ListaEnteros::mergeSort(){
    mergeSort(0,this->size-1);
    int dataTmp[this->size-1];
}

void ListaEnteros::mergeSort(int ini, int fin){
    if(ini<fin){
        int central=(ini+fin)/2;
        mergeSort(ini,central);
        mergeSort(central+1,fin);
        mezcla(ini,fin);
    }
}

void ListaEnteros::mezcla(int ini, int fin){

    int central=(ini+fin)/2;
    int i=ini;
    int j=central+1;
    int dataTmp[this->size-1];
    if(valores[i]<valores[j]){
        dataTmp[ini++]=dataTmp[i++];
    }else{
        dataTmp[ini++]=dataTmp[j++];
    }
}

int main()
{
    cout << "Prueba" << endl;
    int numeros[]={22,14,0,10,3,30,1500,69};
    ListaEnteros lista(8, numeros);
    lista.imprimir();
    cout<<"Ordenamos"<<endl;
    lista.insertionSort();
    lista.imprimir();
    cout<<"(BinIt) El numero 2 esta en la posicion "<<lista.busquedaBinIt(2)<<endl;
    cout<<"(BinRec) El numero 2 esta en la posicion "<<lista.busquedaBinRec(2)<<endl;
    cout<<"(Sec) El numero 2 esta en la posicion "<<lista.busquedaSec(2)<<endl;
    return 0;
}
