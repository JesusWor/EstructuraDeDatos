#include "MyBST.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

MyBST::MyBST(){
    this->size=0;
    this->raiz=nullptr;
}

MyBST::~MyBST(){
    eliminar();
}

int MyBST::getSize(){
    return size;
}

void MyBST::insert(string key, string data, int id) {
    MyNodeBST* nodoNuevo = new MyNodeBST(key, data, id);
    if (raiz == nullptr) {
        raiz = nodoNuevo;
    } else {
        MyNodeBST* current = raiz;
        MyNodeBST* padre = nullptr;
        while (current != nullptr) {
            padre = current;
            if (id < current->id) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (id < padre->id) {
            padre->left = nodoNuevo;
        } else {
            padre->right = nodoNuevo;
        }
    }
    size++;
}


void MyBST::mostrar(){
    if(raiz == nullptr){
        cout<<"No hay elementos en el arbol"<<endl;
    }
    inorder(raiz);
}

void MyBST::inorder(MyNodeBST* nodo){
    if(nodo == nullptr){
        return;
    }else {
        inorder(nodo->left);
        cout<<nodo->data<<endl;
        inorder(nodo->right);
    }
}

void MyBST::eliminar(){
    if(this->size > 0){
        if(this-> size == 1){
            delete raiz;
            this->raiz=nullptr;
        } else {
            MyNodeBST* nodoBorrar = raiz;
            MyNodeBST* tmp = raiz;
            while(nodoBorrar->left != nullptr){
                nodoBorrar = nodoBorrar->left;
            }
            while(tmp->right != nullptr){
                tmp= tmp->right;
            }
            delete nodoBorrar;
            delete tmp;
        }
    }
}