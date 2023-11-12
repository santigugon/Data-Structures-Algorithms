#ifndef MYGRAPH_H_INCLUDED
#define MYGRAPH_H_INCLUDED

#include "vector"

using namespace std;
class MyGraph {
public:
    vector<vector<int>> adjMatr;
    MyGraph(vector<vector<int>> matrAdj);
private:
    loadGraph(vector<vector<int>> matrAdj);
    DFS();
    BFS();

};

#endif // MYGRAPH_H_INCLUDED
