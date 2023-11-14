//A00572499 Santiago Gutierrez Gonzalez
//Act 4.1- Grafo: sus representaciones y sus recorridos
//12/11/2023

////Descripcion- Este programa realiza el recorrido en profundidad y amplitud de un arbol

#include <iostream>
#include "MyGraph.h"
using namespace std;

int main()
{

    // Matriz de adyacencia
    vector<vector<int>> vectorResultante = {
        {0, 1, 1, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0}
    };

    cout<<endl<<"Caso Matriz presentacion"<<endl;
    MyGraph prueba(vectorResultante);
    cout<<"Recorrido DFS: "<<endl;
    prueba.DFS(0);
    cout<<"Recorrido BFS: "<<endl;
    prueba.BFS(0);

    //4 casos prueba extra --v
    /*
    //CASO PRUEBA CICLO
    vector<vector<int>> vectorResultante2={
        {0,1,1,1,0},
        {1,0,0,0,1},
        {1,0,0,1,1},
        {1,0,1,0,0},
        {0,1,1,0,0}

    };

    cout<<endl<<"Caso Matriz distinta"<<endl;
    MyGraph prueba2(vectorResultante2);
    cout<<"Recorrido DFS: "<<endl;
    prueba2.DFS(0);
    cout<<"Recorrido BFS: "<<endl;
    prueba2.BFS(0);

    //PRUEBA No CUADRADA
     vector<vector<int>> vectorResultante3={
        {0,1,1,1},
        {1,0,0,0},
        {1,0,0,1},
        {1,0,1,0},
        {0,1,1,0}

    };

    cout<<endl<<"Caso matriz no cuadrada"<<endl;
    MyGraph prueba3(vectorResultante3);
    cout<<"Recorrido DFS: "<<endl;
    prueba3.DFS(0);
    cout<<"Recorrido BFS: "<<endl;
    prueba3.BFS(0);

    //CASO UNICO ELEMENTO
     vector<vector<int>> vectorResultante4={
     {0}
     };

    cout<<endl<<"Caso 1 elemento"<<endl;
    MyGraph prueba4(vectorResultante4);
    cout<<"Recorrido DFS: "<<endl;
    prueba4.DFS(0);
    cout<<"Recorrido BFS: "<<endl;
    prueba4.BFS(0);

    //CASO 0 ELEMENTOS
    cout<<endl<<"Caso 0 elementos"<<endl;
    vector<vector<int>> vectorResultante5;
    MyGraph prueba5(vectorResultante5);
    cout<<"Recorrido DFS: "<<endl;
    prueba5.DFS(0);
    cout<<"Recorrido BFS: "<<endl;
    prueba5.BFS(0);
    */
    return 0;
}
