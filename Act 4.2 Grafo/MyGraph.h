//A00572499 Santiago Gutierrez Gonzalez
//Act 4.2 - Grafos: Algoritmos complementarios
//17/11/2023

#ifndef MYGRAPH_H_INCLUDED
#define MYGRAPH_H_INCLUDED
#include <iostream>
#include "vector"

using namespace std;

class MyGraph{
    private:
        int nVertices;
        int nArcos;
        vector<vector<int>> listaAdj;
    public:
        MyGraph();
        MyGraph(int n, int m, vector<vector<int>> &listaAdj);
        void loadGraph(int n, int m, vector<vector<int>>& listaAdj );
        bool isTree();
        void topologicalSort();
        bool bipartiteGraph();


};

#endif // MYGRAPH_H_INCLUDED
