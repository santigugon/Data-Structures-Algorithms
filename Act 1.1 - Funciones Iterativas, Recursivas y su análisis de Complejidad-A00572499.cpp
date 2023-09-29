#include <iostream>
//En este programa crearemos funciones las cual tienen como objetivo evaluar una sumatoria de 1 a n a partir de un metodo iterativo, recursivo y directo matematico
//Act 1.1 - Funciones Iterativas, Recursivas y su análisis de Complejidad
//Santiago Gutierrez Gonzalez A00572499
//20/08/2023
using namespace std;


//En las funciones a continuacion se da como parametro el número hasta el cual se busca calcular la sumatoria, empezando por el 1 hasta llegar a ese parametro. Se retorna el valor de la sumatoria.

//Aqui se hace de forma iterativa- Complejidad de Orden Lineal O(n)
int sumaIterativa(int n){
    if(n<=0){
        return 0;
    }
    int sumAcum=0;
    for (int i=0; i<=n;i++){ //Declaramos el for loop y se repite n-1 veces, este el peor caso por lo tanto la complejidad de nuestro algoritmo es de orden Lineal O(n)
        sumAcum+=i; //Esta es una instruccion de orden constante
    }
    return sumAcum;
}

//Aqui hacemos uso de la recursion- Complejidad de tipo O(n)
int sumaRecursiva(int n){
    if(n<=0){
        return 0;
    }
    if(n==1){ //En esta parte se declara el caso base de la recursion
        return 1;
    }
    else{
        return n+sumaRecursiva(n-1); //Es orden lineal pues, sólo se tiene una llamada recursiva, con incrementos o decrementos en el parámetro de control.
    }
}

//Por ultimo usamos el metodo matematico de suma directa - Complejidad de Orden Constante O(1)
int sumaDirecta(int n){
    if(n<=0){
        return 0; //Este es el "peor" escenario y sigue siendo una instruccion de complejidad constante.
    }
    return n*(n+1)/2; //Aqui podemos ver una instruccion con complejidad constante O(1) puesto sin importar el n solo se realiza una vez.
}

//Aqui tenemos nuestro main donde ejecutaremos la funciones anteriores
int main (){
    bool menu= true;
    int n;
    int eleccion;
    while(menu){ //Creamos este while a forma de menu
        cout<<"Ingresa 1 para calcular la sumatoria hasta el numero que tu ingreses."<<endl;
        cout<<"Ingresa 2 para ver 4 casos de prueba."<<endl;
        cout<<"Ingresa 3 para salir del programa."<<endl;
        cin>>eleccion;
        switch(eleccion){
            case 1: //Caso 1 para que el usuario ingrese
                cout<<"Ingresa el numero hasta el que buscas calcular la sumatoria:"<<endl;
                cin>>n;

                cout<<"Resultado suma iterativa: "<<sumaIterativa(n)<<endl;
                cout<<"Resultado suma recursiva: "<<sumaRecursiva(n)<<endl;
                cout<<"Resultado suma directa: "<<sumaDirecta(n)<<endl;
                cout<<endl;
                break;

            case 2: //Caso 2 donde se muestran los casos prueba
                cout<<"Resultado caso 1 de la suma iterativa con n=19 es "<<sumaIterativa(19)<<endl;
                cout<<"Resultado caso 1 de la suma recursiva con n=19 es "<<sumaRecursiva(19)<<endl;
                cout<<"Resultado caso 1 de la suma directa con n=19 es "<<sumaDirecta(19)<<endl;
                cout<<endl;

                cout<<"Resultado caso 2 de la suma iterativa con n=41 es "<<sumaIterativa(41)<<endl;
                cout<<"Resultado caso 2 de la suma recursiva con n=41 es "<<sumaRecursiva(41)<<endl;
                cout<<"Resultado caso 2 de la suma directa con n=41 es "<<sumaDirecta(41)<<endl;
                cout<<endl;

                cout<<"Resultado caso 3 de la suma iterativa con n=5 es "<<sumaIterativa(5)<<endl;
                cout<<"Resultado caso 3 de la suma recursiva con n=5 es "<<sumaRecursiva(5)<<endl;
                cout<<"Resultado caso 3 de la suma directa con n=5 es "<<sumaDirecta(5)<<endl;
                cout<<endl;

                cout<<"Resultado caso 4 de la suma iterativa con n=135 es "<<sumaIterativa(135)<<endl;
                cout<<"Resultado caso 4 de la suma recursiva con n=135 es "<<sumaRecursiva(135)<<endl;
                cout<<"Resultado caso 4 de la suma directa con n=135 es "<<sumaDirecta(135)<<endl;
                cout<<endl;
                break;

            case 3: //Caso 3 para abandonar el menu
                menu=false;
                break;
        }
    }
return 0;
}
