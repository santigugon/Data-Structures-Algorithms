#include "MyGraph.h"

 MyGraph::MyGraph(int n, int m, vector<vector<int>> &listaAdj){
    this->loadGraph( n,  m, listaAdj);
}

void MyGraph::loadGraph(int n, int m, vector<vector<int>> &listaAdj){
    if(n>=0&&m>=0){
        this->nVertices=n;
        this->nArcos=m;
        this->listaAdj=listaAdj;
    }
}

bool MyGraph::isTree(){
    vector<int> flag(this->listaAdj.size(),false);
    int nFlags=0;
    for(int i=0; i<this->listaAdj.size();i++){
        for(int j=0; j<this->listaAdj[i].size();j++){
            if(!flag[this->listaAdj[i][j]]){
                flag[this->listaAdj[i][j]]=true;
                nFlags++;
            }else{
                return false;
            }
        }
    }
    if(nFlags==listaAdj.size()){
        return false;
    }
    bool unicoNodo=false;
    for(int i=0;i<listaAdj.size();i++){
        if(!unicoNodo&&!flag[i]){
            unicoNodo=true;
        }else if(unicoNodo&&!flag[i]){
            return false;
        }
    }
    return true;

}
