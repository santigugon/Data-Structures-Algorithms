//A00572499 Santiago Gutierrez Gonzalez
//Act 4.2 - Grafos: Algoritmos complementarios
//20/11/2023
//Descripcion- En este programa añadimos nuevos metodos al grafo para poder decir si es un arbol, si es un grafo bipartita o realizar un recorrido topologico
#ifndef MYGRAPH_H_INCLUDED
#define MYGRAPH_H_INCLUDED
#include <iostream>
#include "vector"
#include "queue"
#include "stack"

using namespace std;

class MyGraph{
    private:
        //vector<vector<int>> adjMatr;
    public:
        vector<vector<int>> adjMatr;
        MyGraph();
        MyGraph(vector<vector<int>> &matrAdj);
        void loadGraph(vector<vector<int>>& matrAdj );
        bool isTree();
        void topologicalSort();
        bool bipartiteGraph();
        void DFS(int nodoI);
        void BFS(int nodoI);


};

#endif // MYGRAPH_H_INCLUDED

//REFERENCIAS consultadas para la creacion
//(PSEUDOCODIGO)
//Presentacion 08.2-GRAFOSYRECORRIDOS por Edgar Salinas
