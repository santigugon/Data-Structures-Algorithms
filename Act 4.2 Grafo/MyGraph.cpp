#include "MyGraph.h"

void MyGraph::MyGraph(int n, int m, vector<vector<int>> &listaAdj){
    this->loadGraph(int n, int m, vector<vector<int>> &listaAdj);
}

void MyGraph::loadGraph(int n, int m, vector<vector<int>> &listaAdj){
    if(n>=0&&m>=0){
        this->nVertices=n;
        this->nArcos=m;
        this->listaAdj=listaAdj;
    }
}

bool MyGraph::isTree(){
    vector<int> flag;


}
