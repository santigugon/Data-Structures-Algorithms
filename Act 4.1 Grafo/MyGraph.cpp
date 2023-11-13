#include "MyGraph.h"
using namespace std;

//Complejidad de tipo constante O(1)
MyGraph::MyGraph(vector<vector<int>> &matrAdj){
    if(matrAdj.size()>0){
        if(matrAdj.size()==matrAdj[0].size())
            loadGraph(matrAdj);
    }
}


void MyGraph::loadGraph(vector<vector<int>> &matrAdj){
    this->adjMatr=matrAdj;
}

//N=Num de nodos
//A=Num de aristas
//Complejidad media O(N+A)
//Complejidad peor caso O(N^2)

void MyGraph::DFS(int nodoI){
    if(this->adjMatr.size()>0){
        int nodoTope;
        stack<int> pilaVisitados;
        //Aqui conocemos y verificamos hijos visitados
        vector<bool> flag;
        for(int i=0; i<this->adjMatr.size();i++){
            flag.push_back(false);
        }
        for(int nodo=nodoI; nodo<flag.size();nodo++){
            if(!flag[nodo]){
                flag[nodo]=true;
                pilaVisitados.push(nodo);
            }
            while(!pilaVisitados.empty()){
                nodoTope=pilaVisitados.top();
                cout<<nodoTope<<", ";
                pilaVisitados.pop();
                  for(int j=0; j<=this->adjMatr.size(); j++){
                    int proximoHijo=adjMatr.size()-j;
                    if(this->adjMatr[nodoTope][proximoHijo]==1 && !flag[proximoHijo]){

                        pilaVisitados.push(proximoHijo);
                        flag[proximoHijo]=true;
                    }
                }
            }
        }
    }

}

//N=Num de nodos
//A=Num de aristas
//Complejidad media O(N+A)
//Complejidad peor caso O(N^2)

void MyGraph::BFS(int nodoI){

    if(this->adjMatr.size()>0){
        int nodoTope;
        std::queue<int> colaVisitados;
        vector<bool> flag;
        for(int i=0; i<this->adjMatr.size();i++){
            flag.push_back(false);
        }
        for(int nodo=nodoI; nodo<flag.size();nodo++){
            //Aquí agregamos el nodo a la cola cuando no este marcado como visitado
            if(!flag[nodo]){
              colaVisitados.push(nodo);
              //Lo marcamos como visitado
              flag[nodo]=true;
            }
            while(!colaVisitados.empty()){
                //Guardamos el nodo
                nodoTope= colaVisitados.front();
                //Sacamos el nodo de la cola
                cout<<nodoTope<<", ";
                colaVisitados.pop();
                for(int j=0; j<this->adjMatr.size(); j++){
                    if(this->adjMatr[j][nodoTope]==1 && !flag[j]){
                        colaVisitados.push(j);
                        flag[j]=true;
                    }
                }
            }
        }
    }
}

