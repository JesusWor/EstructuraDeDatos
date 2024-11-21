// Equipo 3
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
// Descripcion: Este programa hace uso de una hash table concatenada medainte un BST para el guardado y acomodo
// de Registros dados mediane un archivo

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

//O(1)
//Devuelve el size del BST
int MyBST::getSize(){
    return size;
}

//O(log n)
//Inserta un nuevo nodo en el BST
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

//O(n)
//Muestra todos los nodos del BST
void MyBST::mostrar(){
    if(raiz == nullptr){
        cout<<"No hay elementos en el arbol"<<endl;
    }
    inorder(raiz);
}

//O(n)
//Recorre y muestra todos los nodos del BST
void MyBST::inorder(MyNodeBST* nodo){
    if(nodo == nullptr){
        return;
    }else {
        inorder(nodo->left);
        cout<<nodo->data<<endl;
        inorder(nodo->right);
    }
}

//O(n)
//Elimina todos los nodos del BST
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

//O(1)
//Devuelve la key de la raiz
string MyBST::getRaizKey(){
    return raiz->key;
}

//O(1)
//Devuelve la data de la raiz
string MyBST::getRaizData(){
    return raiz->data;
}

//O(1)
//Devuelve el id de la raiz
int MyBST::getRaiztId(){
    return raiz->id;
}

//O(log n)
//Elimina la raiz del BST
void MyBST::eliminarRaiz(){
    MyNodeBST* raizTemp = raiz;

    if(raiz == nullptr){
        return;
    }
    if (raiz->left != nullptr){
        MyNodeBST* nodo= raiz->left;
        while(nodo->right != nullptr){
            nodo = nodo->right;
        }
        nodo->right= raiz->right;
        raiz= raiz->left;

    } else if (raiz->right != nullptr) {
        raiz = raiz->right;
    } else {
        raiz = nullptr;
    }

    delete raizTemp;
    size--;
}