#ifndef MYGRAPH_H_INCLUDED
#define MYGRAPH_H_INCLUDED

#include "iostream"
#include "vector"
#include "queue"

using namespace std;
class MyGraph {
private:
    vector<vector<int>> adjMatr;
    int visitedNodes;
public:
    MyGraph(vector<vector<int>> &matrAdj);
    void loadGraph(vector<vector<int>> &matrAdj);
    void DFS(int nodoI);
    void BFS(int nodoI);

};

#endif // MYGRAPH_H_INCLUDED
