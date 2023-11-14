
//A00572499 Santiago Gutierrez Gonzalez
//Act 4.1- Grafo: sus representaciones y sus recorridos
//12/11/2023

////Descripcion- Este programa realiza el recorrido en profundidad y amplitud de un arbol
#ifndef MYGRAPH_H_INCLUDED
#define MYGRAPH_H_INCLUDED

#include "iostream"
#include "vector"
#include "queue"
#include "stack"

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

//REFERENCIAS consultadas para la creacion
//(PSEUDOCODIGO)
//Presentacion 08.2-GRAFOSYRECORRIDOS por Edgar Salinas
//Salinas Gurrión, E. G., & de la Cueva Hernández, V. M. (2020). Estructuras de datos y algoritmos fundamentales. Digital. https://www.amazon.com.mx/Estructuras-datos-y-algoritmos-fundamentales-ebook/dp/B08FBJ9YFM/ref=cm_cr_arp_d_product_top?ie=UTF8#customerReviews
//BettaTech. (2021b, noviembre 29). Algoritmos BFS y DFS (Recorridos en grafos) [Vídeo]. YouTube. https://www.youtube.com/watch?v=_Yf8tneauJ8
