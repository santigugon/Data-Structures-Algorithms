#ifndef MYHEAP_H_INCLUDED
#define MYHEAP_H_INCLUDED
class   MyHeap{
    private:
        int* values; //Arreglo donde se van a guardar los valores del HEAP
        int size;    //Representa cuantos valores tiene almacenado el Heap
       int len;    //Representa el tama�o o capacidad m�xima actual del arreglo
    public:
        MyHeap();//Inicializa el los atributos. El atributo values lo inicializa como un arreglo vac�o tama�o de 7.
        MyHeap(int* valores,int size); //Convierte el arreglo en un heap. Lo deja del mismo tama�o que tiene el arreglo
        void push(int n); //Inserta un valor en el heap. S�lo cuando el nuevo valor no cabe en el arreglo
                          //crece el arreglo al tama�o 2*n+1. (Expansi�n din+amica del arreglo)
                          //Es decir si se tiene el arreglo ya con 7 valores y se quiere insertar otro valor(El 8vo)
                          //entonces el arreglo se crece a tama�o 15, se copian los primeros 7 valores del arreglo original
                          //y se inserta el 8vo valor.
        void pop();//Se elimina un valor del heap. No es necesario nunca decrementar el tama�o del arreglo.
        int top();//regresa quien es el siguiente elemento en salir pero sin borrarlo
        bool isEmpty();//regresa true si el heap est� vac�o caso contrario regresa false
        int length();//regresa cu�ntos elementos est�n almacenando el heap. OJO: NO EL TAMA�O
        void imprimir();
        void heap(int indice);
        void swap(int a, int b);

   };


#endif // MYHEAP_H_INCLUDED
