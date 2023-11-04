#include <iostream>
#include "MyHeap.h"
#include <cassert>

using namespace std;

int main()
{
    /*
    // Caso 1: Crear un heap vacio e imprimirlo
    cout << "Caso 1: Crear un heap vacio e imprimirlo" << endl;
    MyHeap heap1;
    assert(heap1.isEmpty());
    assert(heap1.length() == 0);
    heap1.imprimir(); // Deberia imprimir: "arbol size: 0 len: 7\n"

    // Caso 2: Crear un heap a partir de un conjunto de valores y probar operaciones
    cout << "Caso 2: Crear un heap a partir de un conjunto de valores y probar operaciones" << endl;
    int valores2[] = {4, 2, 7, 9, 5, 3, 8};
    MyHeap heap2(valores2, 7);
    assert(!heap2.isEmpty());
    assert(heap2.length() == 7);
    assert(heap2.top() == 9);
    heap2.imprimir(); // Debería imprimir la representación del heap

    // Caso 3: Agregar elementos y verificar que el heap se ajusta correctamente
    cout << "\nCaso 3: Agregar elementos y verificar que el heap se ajusta correctamente" << endl;
    heap2.push(10);
    heap2.push(1);
    assert(heap2.length() == 9);
    assert(heap2.top() == 10);
    heap2.imprimir(); // Debería imprimir la representación del heap después de las inserciones

    // Caso 4: Eliminar elementos y verificar que el heap se ajusta correctamente
    cout << "\nCaso 4: Eliminar elementos y verificar que el heap se ajusta correctamente" << endl;
    heap2.pop();
    assert(heap2.length() == 8);
    assert(heap2.top() == 9);
    heap2.imprimir(); // Debería imprimir la representación del heap después de la eliminación

    // Caso 5: Crear un heap vacio, intentar eliminar elementos y verificar que sigue vacio
    cout << "\nCaso 5: Crear un heap vacio, intentar eliminar elementos y verificar que sigue vacio" << endl;
    MyHeap heap3;
    heap3.pop(); // No debería producir ningún resultado
    assert(heap3.isEmpty());
    heap3.imprimir(); // Debería imprimir: "arbol size: 0 len: 7\n"

    // Caso 6: Crear un heap con un solo elemento y verificar que se mantiene igual
    cout << "Caso 6: Crear un heap con un solo elemento y verificar que se mantiene igual" << endl;
    int valores6[] = {42};
    MyHeap heap6(valores6, 1);
    assert(!heap6.isEmpty());
    assert(heap6.length() == 1);
    assert(heap6.top() == 42);
    heap6.imprimir();

    // Caso 7: Prueba con elementos duplicados
    cout << "\nCaso 7: Prueba con elementos duplicados" << endl;
    int valores7[] = {3, 3, 3, 3, 3};
    MyHeap heap7(valores7, 5);
    assert(heap7.top() == 3);
    heap7.imprimir();

    // Caso 8: Prueba con elementos negativos
    cout << "\nCaso 8: Prueba con elementos negativos" << endl;
    int valores8[] = {-5, -1, -10, -2, -8};
    MyHeap heap8(valores8, 5);
    assert(heap8.top() == -1);
    heap8.imprimir();

    // Caso 9: Prueba con valores extremos
    cout << "\nCaso 9: Prueba con valores extremos" << endl;
    int valores9[10000]; // Crear un heap con 10,000 elementos
    for (int i = 0; i < 10000; i++) {
        valores9[i] = i;
    }
    MyHeap heap9(valores9, 10000);
    heap9.push(10000);
    assert(heap9.top() == 10000);
    heap9.pop();
    assert(heap9.top() == 9999);
    heap9.imprimir();

    // Caso 10: Prueba de límites
    /*
    cout << "\nCaso 10: Prueba de limites" << endl;
    MyHeap heap10;
    for (int i = 0; i < 1000000; i++) {
        heap10.push(i);
    }
    assert(heap10.length() == 1000000);
    assert(heap10.top() == 999999);
    for (int i = 0; i < 1000000; i++) {
        heap10.pop();
    }

    assert(heap10.isEmpty());
    heap10.imprimir();
    */

    cout << "\nTodas las pruebas han pasado exitosamente!!" << endl;




     MyHeap emptyHeap;
    cout << "Testing with an empty heap:" << endl;
    emptyHeap.imprimir();
    cout << "Heap size: " << emptyHeap.length() << endl;
    cout << "Is heap empty? " << (emptyHeap.isEmpty() ? "Yes" : "No") << endl;
    cout << "Top element: " << emptyHeap.top() << endl;
    cout << "Pop element: ";
    emptyHeap.pop();
    emptyHeap.push(1);
    emptyHeap.imprimir();
    cout << endl;

    // Create a one-element heap
    int oneElementArray[] = {45};
    MyHeap oneElementHeap(oneElementArray, 1);
    cout << "Testing with a one-element heap:" << endl;
    oneElementHeap.imprimir();
    cout << "Heap size: " << oneElementHeap.length() << endl;
    cout << "Is heap empty? " << (oneElementHeap.isEmpty() ? "Yes" : "No") << endl;
    cout << "Top element: " << oneElementHeap.top() << endl;
    cout << "Pop element: ";
    oneElementHeap.pop();
    oneElementHeap.imprimir();
    cout << endl;

    // Create a complete heap
    int completeArray[] = {15, 79, 90, 10, 55, 12, 20, 50};
    MyHeap completeHeap(completeArray, sizeof(completeArray) / sizeof(completeArray[0]));
    cout << "Testing with a complete heap:" << endl;
    completeHeap.imprimir();
    cout << "Heap size: " << completeHeap.length() << endl;
    cout << "Is heap empty? " << (completeHeap.isEmpty() ? "Yes" : "No") << endl;
    cout << "Top element: " << completeHeap.top() << endl;

    // Push additional elements
    completeHeap.push(30);
    completeHeap.push(70);
    cout << "Pushed elements 30 and 70:" << endl;
    completeHeap.imprimir();

    // Pop some elements
    cout << "Popped elements: ";
    completeHeap.pop();
    completeHeap.pop();
    completeHeap.imprimir();

    // Test heapify on a new array
    int arrayToHeapify[] = {30, 20, 40, 10, 70, 60, 50};
    MyHeap heapifiedHeap(arrayToHeapify, sizeof(arrayToHeapify) / sizeof(arrayToHeapify[0]));
    cout << "Testing heapify on a new array:" << endl;
    heapifiedHeap.imprimir();
    cout << "Heap size: " << heapifiedHeap.length() << endl;
    cout << "Top element: " << heapifiedHeap.top() << endl;

    cout<< "end of test" << endl;
    //Push duplicado
    int lista2[11]={15,60,72,70,56,32,62,92,45,30,65};
    MyHeap duplicado(lista2, 11);
    int lista3[11]={82, 70, 51, 63, 55, 37, 10, 43, 27, 30, 34};
    int lista4[7]={8,5,4,3,9,6,2};
    MyHeap duplicado2(lista3, 11);
    duplicado.imprimir();
     duplicado2.imprimir();
    duplicado2.push(95);
    duplicado2.pop();
    duplicado2.imprimir();

    /*

    int lista[8]={5,12,64,1,37,90,91,97};
    //int lista2[6]={28,21,17,19,5,8};
    //
    int lista2[11]={82, 70, 51, 63, 55, 37, 10, 43, 27, 30, 34};
    int lista4[7]={8,5,4,3,9,6,2};
    MyHeap hola(lista,8);
    hola.imprimir();
    MyHeap hola2(lista2,11);
    hola2.imprimir();
    cout<<"TOP "<<hola2.top()<<endl;
   // hola2.push(29);
    hola2.imprimir();
    cout << "Hello world!" << endl;
    MyHeap lista3;
    lista3.imprimir();
    lista3.push(15);
    lista3.push(60);
    lista3.push(72);
    lista3.push(70);
    lista3.push(56);
    lista3.push(32);
    lista3.push(62);
    lista3.imprimir();
    lista3.push(92);
    lista3.push(45);
    lista3.push(30);
    lista3.push(65);
cout<<"Lista 3"<<endl;
    lista3.imprimir();
    hola2.imprimir();
    hola2.push(95);
    hola2.imprimir();
    cout<<"Sacamos primer prioridad"<<hola2.top()<<endl;
    hola2.pop();
    hola2.imprimir();
    int lista5[12]={95, 82, 51, 63, 70, 37, 10, 43, 27, 55, 34, 30};
    MyHeap listaH5(lista5,12);
    listaH5.imprimir();
    cout<<"Borrado lista 5"<<endl;
    listaH5.pop();
    listaH5.imprimir();
    MyHeap listaH4(lista4,7);
    listaH4.imprimir();
    */
    return 0;
}
