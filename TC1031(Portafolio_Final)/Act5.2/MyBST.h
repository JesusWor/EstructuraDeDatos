// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
// Descripcion: Este programa hace uso de una hash table concatenada medainte un BST para el guardado y acomodo
// de Registros dados mediane un archivo

#ifndef MYBST_H
#define MYBST_H

#include <string>
using namespace std;

struct MyNodeBST{
    string key;
    string data;
    int id;
    MyNodeBST *left,
              *right,
              *padre;
    MyNodeBST(string key, string data, int id) {
        this->key = key;
        this->data = data;
        this->id = id;   
        this->left = this->right = nullptr;
        this->padre = padre;
    }
};

class MyBST{
    private:
        MyNodeBST* raiz;
        int size;

    public:
        MyBST();
        ~MyBST();
        int getSize();
        void insert(string key, string data, int id);
        string getRaizData();
        string getRaizKey();
        int getRaiztId();
        void eliminarRaiz();
        void mostrar();
        void inorder(MyNodeBST* nodo);
        void eliminar();
};

#endif