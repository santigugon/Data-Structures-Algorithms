//A00572499 Santiago Gutierrez Gonzalez
//Act 3.2 - Arbol Heap: Implementando una fila priorizada
//31/10/2023

//Descripcion- En este programa implementamos el ADT de una max_queue en forma de un heap

#ifndef MYHEAP_H_INCLUDED
#define MYHEAP_H_INCLUDED
class   MyHeap{
    private:
        int* values; //Arreglo donde se van a guardar los valores del HEAP
        int size;    //Representa cuantos valores tiene almacenado el Heap
        int len;    //Representa el tama�o o capacidad m�xima actual del arreglo
        void heap(int indice);
        void swap(int a, int b);
    public:
        MyHeap();
        MyHeap(int* valores,int size);
        void push(int n);
        void pop();
        int top();
        bool isEmpty();
        int length();
        void imprimir();
   };


#endif // MYHEAP_H_INCLUDED
