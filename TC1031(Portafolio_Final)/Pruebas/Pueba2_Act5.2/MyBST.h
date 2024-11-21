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
        string getAtData(string key);
        void mostrar();
        void inorder(MyNodeBST* nodo);
        void eliminar();
};

#endif