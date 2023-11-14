//A00572499 Santiago Gutierrez Gonzalez
//Act 4.2 - Grafos: Algoritmos complementarios
//17/11/2023

#include "MyGraph.h"
#include <iostream>

using namespace std;

int main()
{
    vector<vector<int>> listAdj={
        {1,2,3,4},{5},{},{6},{},{7},{8},{},{}
        };

    MyGraph grafoD(8,8,listAdj);
    cout << "Hello world!" <<(grafoD.isTree()?" Es arbol":"No es arbol")<< endl;
    return 0;
}
