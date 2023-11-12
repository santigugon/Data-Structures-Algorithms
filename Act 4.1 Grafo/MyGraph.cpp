#include "MyGraph.h"
using namespace std;

MyGraph::MyGraph(vector<vector<int>> &matrAdj){
    if(matrAdj.size()==matrAdj[0].size()){
        loadGraph(matrAdj);
    }
}

void MyGraph::loadGraph(vector<vector<int>> &matrAdj){
    this->adjMatr=matrAdj;
}

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
            flag[nodo]=true;
            pilaVisitados.push(nodo);
            while(!pilaVisitados.empty()){
                nodoTope=pilaVisitados.top();
                cout<<nodoTope<<", ";
                pilaVisitados.pop();
                  for(int j=0; j<this->adjMatr.size(); j++){
                    if(this->adjMatr[j][nodoTope]==1 && !flag[j]){
                        pilaVisitados.push(j);
                        flag[j]=true;
                    }
                }
            }
        }
    }

}

void MyGraph::BFS(int nodoI){

    if(this->adjMatr.size()>0){
        cout<<"Hola"<<endl;
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

