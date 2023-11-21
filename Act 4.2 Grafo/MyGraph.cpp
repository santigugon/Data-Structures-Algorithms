//A00572499 Santiago Gutierrez Gonzalez
//Act 4.2 - Grafos: Algoritmos complementarios
//20/11/2023

//Descripcion- En este programa añadimos nuevos metodos al grafo para poder decir si es un arbol, si es un grafo bipartita o realizar un recorrido topologico

#include "MyGraph.h"

//Constructor
//Complejidad de tipo constante O(1)
MyGraph::MyGraph(vector<vector<int>> &matrAdj){
    if(matrAdj.size()>0){
        loadGraph(matrAdj);
    }
}

//Cargamos la matriz de adyacencia la grafo
//Complejidad de tipo constante O(1)
void MyGraph::loadGraph(vector<vector<int>> &matrAdj){
    this->adjMatr=matrAdj;
}

//Realizamos el recorrido para saber si se tiene un unico un nodo raiz y que se puede representar como arbol
//N=Numero de nodos
//Complejidad de tipo O(N^2)
bool MyGraph::isTree(){
    vector<bool> flag(this->adjMatr.size(),false);
    int nFlags=0;
    for(int i=0; i<this->adjMatr.size();i++){
        for(int j=0; j<this->adjMatr[i].size();j++){
            if(this->adjMatr[i][j]==1){
                if(!flag[j]){
                    flag[j]=true;
                    nFlags++;
                }
                else{
                    return false;
                }
            }
        }
    }
    if(nFlags==adjMatr.size()){
        return false;
    }
    bool unicoNodo=false;
    for(int i=0;i<adjMatr.size();i++){
        if(!unicoNodo&&!flag[i]){
            unicoNodo=true;
        }else if(unicoNodo&&!flag[i]){
            return false;
        }
    }
    return true;

}

//Realizamos el recorrido para imprimir un recorrido topologico como el visto en clase
//N=Numero de nodos
//Complejidad de tipo O(N^2)
void MyGraph::topologicalSort(){
    queue<int> cola0;
    queue<int> resultado;
    vector<int> grados(this->adjMatr.size(),0);
    int top;
    for(int i=0; i<this->adjMatr.size();i++){
        for(int j=0; j<this->adjMatr[i].size();j++){
            if(this->adjMatr[i][j]==1){
                grados[j]++;
            }

        }
    }
    for(int i=0;i<grados.size();i++){
        if(grados[i]==0){
            cola0.push(i);
        }
    }
    while(!cola0.empty()){
        top=cola0.front();
        cola0.pop();
        cout<<top<<",";
        for(int indAdj=0;indAdj<adjMatr[top].size();indAdj++){
            if(this->adjMatr[top][indAdj]==1){
                grados[indAdj]--;
                if(grados[indAdj]==0){
                    cola0.push(indAdj);
                }
            }
        }
    }
    cout<<endl;
}

//Realizamos el recorrido para saber si el grafo se puede representar como grafo bipartita
//N=Numero de nodos
//Complejidad de tipo O(N^2)
bool MyGraph::bipartiteGraph(){
    vector<int> colores(this->adjMatr.size(),0);
    queue<int> coloreados;
    int colorActual;
    int colorContrario;
    int frente;
    for(int i=0;i<this->adjMatr.size();i++){
        if(colores[i]==0){
            colores[i]=1;
            coloreados.push(i);
        }
        while(!coloreados.empty()){
            frente=coloreados.front();
            coloreados.pop();
            colorActual=colores[frente];
            if(colorActual==1){
                colorContrario=2;
            }
            else{
                colorContrario=1;
            }
            for(int j=0; j<this->adjMatr[frente].size();j++){
                if(this->adjMatr[frente][j]==1){
                    if(colores[j]==0){
                        colores[j]=colorContrario;
                        coloreados.push(j);
                    }
                    else if(colores[j]==colorActual){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

//N=Num de nodos
//A=Num de arcos
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
                cout<<nodoTope<<",";
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
        cout<<endl;
    }

}

//N=Num de nodos
//A=Num de arcos
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
                cout<<nodoTope<<",";
                colaVisitados.pop();
                for(int j=0; j<this->adjMatr.size(); j++){
                    if(this->adjMatr[j][nodoTope]==1 && !flag[j]){
                        colaVisitados.push(j);
                        flag[j]=true;
                    }
                }
            }
        }
        cout<<endl;
    }
}
