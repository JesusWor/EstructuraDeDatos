#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <vector>

using namespace std;

class MyGraph{
    private:
        vector<vector<int>> matriz;
        
    public:
        MyGraoh(vector<vector<int>>& matriz);
        void loadGraph(vector<vector<int>>& matriz);
        void DFS(); //imprimi el recorrido de DFS (profundidad) a partir del nodo inicial
        void DFSRecursivo(vector<vector<int>>& matriz);
        void BFS(); //imprimi el recorrido de BFS (anchura/amplitud) a partir del nodo inicial
};