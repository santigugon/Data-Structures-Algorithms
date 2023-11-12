#include <iostream>
#include "MyGraph.h"
using namespace std;

int main()
{
    // Matriz de adyacencia
    int matrizAdyacencia[9][9] = {
        {0, 1, 1, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0}
    };

    // Convertir la matriz en un vector
  vector<vector<int>> vectorResultante;
    for (int i = 0; i < 9; ++i) {
        vector<int> filaVector;
        for (int j = 0; j < 9; ++j) {
            filaVector.push_back(matrizAdyacencia[i][j]);
        }
        vectorResultante.push_back(filaVector);
    }



    MyGraph prueba(vectorResultante);
    prueba.BFS(3);
    return 0;
}
