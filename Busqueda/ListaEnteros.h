#ifndef LISTAENTEROS_H_INCLUDED
#define LISTAENTEROS_H_INCLUDED

class ListaEnteros{
    private:
        int* valores;
        int length; //Hasta cuantos elementos necesito guardar en mi arreglo
        int size; //Tamaño actual del arreglo
    public:
        ListaEnteros(int length);
        ListaEnteros(int length, int valores[]);
        void imprimir();
        int busquedaSec(int valor);
        int busquedaBinIt(int valor);
        int busquedaBinRec(int valor);
        void bubbleSort();

};


#endif // LISTAENTEROS_H_INCLUDED
