//A00572499 Santiago Gutierrez Gonzalez
//Act 4.2 - Grafos: Algoritmos complementarios
//17/11/2023

#include "MyGraph.h"
#include <iostream>

using namespace std;

int main()
{
    vector<vector<int>> listAdj={
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    vector<vector<int>> biPartito={
    {0,1,0,1,0,1,0,0},
    {1,0,1,0,1,0,1,1},
    {0,1,0,1,0,1,0,0},
    {1,0,1,0,1,0,1,1},
    {0,1,0,1,0,1,0,},
    {1,0,1,0,1,0,1,1},
    {0,1,0,1,0,1,0,0},
    {0,1,0,1,0,1,0,0}
    };

    MyGraph grafoD(listAdj);
    cout << "Graph 1 (Presentacion)!" <<(grafoD.isTree()?" Es arbol":"No es arbol")<< endl;
    grafoD.topologicalSort();
    cout << "Evaluacion bipartita!" <<(grafoD.bipartiteGraph()?" Es bipartito":"No es bipartito")<< endl;
    cout << endl;

    MyGraph grafoBi(biPartito);
    cout << "Graph 2  (Bipartito):" <<(grafoBi.isTree()?" Es arbol":"No es arbol")<< endl;
    grafoBi.topologicalSort();
    cout << "Evaluacion bipartita!" <<(grafoBi.bipartiteGraph()?" Es bipartito":"No es bipartito")<< endl;
    cout << endl;

    vector<vector<int>> testGraph = {
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0}
    };


    MyGraph testObj(testGraph);  // Assuming your constructor takes an adjacency matrix
    cout << "Graph 3  (BipartitoMINI):" <<(grafoBi.isTree()?" Es arbol":"No es arbol")<< endl;
    testObj.topologicalSort();
    cout << "Evaluacion bipartita!" <<(testObj.bipartiteGraph()?" Es bipartito":"No es bipartito")<< endl;
    cout << endl;

    vector<vector<int>> arbol={
    {0,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
    };

    MyGraph tree(arbol);  // Assuming your constructor takes an adjacency matrix
    cout << "Graph 3  (Tree): "  <<(tree.isTree()?" Es arbol":"No es arbol")<< endl;
    tree.topologicalSort();
    cout << "Evaluacion bipartita!" <<(tree.bipartiteGraph()?" Es bipartito":"No es bipartito")<< endl;
    cout << endl;

     // Test case 4: Empty graph
    vector<vector<int>> emptyGraph;
    MyGraph emptyObj(emptyGraph);
    cout << "Graph 4 (Empty): " << (emptyObj.isTree() ? "Is a tree" : "Is not a tree") << endl;
    emptyObj.topologicalSort();
    cout << "Bipartite: " << (emptyObj.bipartiteGraph() ? "Is bipartite" : "Is not bipartite") << endl;
    cout << endl;

    // Test case 5: Graph with only one node
    vector<vector<int>> singleNodeGraph = {{0}};
    MyGraph singleNodeObj(singleNodeGraph);
    cout << "Graph 5 (Single Node): " << (singleNodeObj.isTree() ? "Is a tree" : "Is not a tree") << endl;
    singleNodeObj.topologicalSort();
    cout << "Bipartite: " << (singleNodeObj.bipartiteGraph() ? "Is bipartite" : "Is not bipartite") << endl;

    return 0;
}
