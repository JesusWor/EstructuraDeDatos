/* 
Implmentacion de un BST con operaciones avanzadas
En el siguiente codigo veremos las funciones que necesitamos y como es que 
estas funcionaran, ademas de como es que se implementaran los metodos de profundidad,
insertar y remover datos de un arbol.
Se utilio un video de youtube para poder lograr de manera correcta la funcion de remove,tambien
para comprender mejor el tema visto en clase y resolver algunas dudas
Referencia: Programación ATS. (2016, 21 diciembre). 120. Programación en C++ || Árboles || Eliminar un nodo del árbol - parte 2 [Vídeo]. YouTube. https://www.youtube.com/watch?v=u9c-4qlvt24
Refencia 2: Programación ATS. (2016c, diciembre 23). 121. Programación en C++ || Árboles || Eliminar un nodo del árbol - parte 3 [Vídeo]. YouTube. https://www.youtube.com/watch?v=Kchi5guHGx0
Jesús Eduardo Escobar Meza A01743270
16/10/24
*/
#include "MyBST.h"
#include <iostream>

using namespace std;

//Complejidad O(1)
/* Esta funcion nos permite incializar el BST vacio*/
MyBST::MyBST(){
    this->size=0;
    this->root=nullptr;
}

//Complejidad O(1)
/* Esta funcion nos permite saber la longitud del BST*/
int MyBST::length(){
    return this->size;
}

//Complejidad O(1)
/* Esta funcion nos permite saber si el BST esta vacio o no*/
bool MyBST::isEmpty(){
    return this->size == 0;
}

//Complejidad O(log n) en el mejor de los casos, en el peor O(n)
/* Esta funcion nos permite buscar un elemento en el arbol llamando a la funcion privada que sera la encargada de realizar todo el 
algoritmo de busqueda*/
bool MyBST::search(int data){
    return search(data,root);
}

//Complejidad O(log n) en el mejor de los casos, en el peor O(n)
/* Esta funcion nos permite buscar un valor en el BST de manera recursiva a partir de un nodo*/
bool MyBST::search(int data, MyNodeBST* current){
    if(current==nullptr){
        return false;
        }
    if(current->data==data){
        return true;
    }
    if(data<current->data){
        return search(data,current->left);
    }else{
        return search(data,current->right);
        }
}

//Complejidad O(log n) en los casos promedio, en el peor O(n)
/* Esta funcion nos permite isertar un valor al BST*/
bool MyBST::insert(int data){
    MyNodeBST* nuevo = new MyNodeBST(data);
    MyNodeBST* current = root;
    MyNodeBST* padre = nullptr;
    while(current != nullptr){
        if(current->data == data){
            return false;
        }
        padre = current;
        if(data < current->data){
            current = current->left;
        } else {
            current = current->right;
        }
    }
    nuevo->padre = padre;
    if(padre == nullptr){
        root = nuevo;
    } else if(data < padre->data){
        padre->left = nuevo;
    } else {
        padre->right = nuevo;
    }
    size++;
    return true;
}

//Complejidad O(log n) en los casos promedio, en el peor O(n)
/* Esta funcion nos eliminar un nodo llamando a la funcion remove que acepta 
dos parametros y checa si el nodo esta vacio, si lo esta regresa false*/
bool MyBST::remove(int data){
    if(root != nullptr){
        return remove(root, data);
    } else {
        return false;
    }
}

//Complejidad O(log n) en los casos promedio, en el peor O(n)
/* Esta funcion nos permite buscar el minimo de un nodo haciendo que se vaya a la isquierda
lo maximo posible*/
MyNodeBST* MyBST::minimo(MyNodeBST* current){
    if(current == nullptr){
        return nullptr;
    } 
    if (current->left){
        return minimo(current->left);
    } else {
        return current;
    }
}

//Complejidad O(1)
/* Esta funcion nos permite remplazar un nodo con otro haciendo que ese nodo se convierta en el padre*/
void MyBST::remplazo(MyNodeBST* current, MyNodeBST* nuevo){
    if(current->padre){
        if(current == current->padre->left){
            current->padre->left = nuevo;
        } else if(current == current->padre->right) {
            current->padre->right = nuevo;
        }
    } else {
        root = nuevo;
    }
    if(nuevo){
        nuevo->padre = current->padre;
    }
}

//Complejidad O(log n) en los casos promedio, en el peor O(n)
/* Esta funcion nos permite eliminar un nodo de un BST contemplando 4 casos posibles:
1.- Cuando el nodo a eliminar tiene dos hijos
2.- Cuando el nodo a eliminar tiene un hijo izquierdo
3.- Cuando el nodo a eliminar tiene un hijo derecho
4.- Cuando el nodo a eliminar no contiene ningun hijo*/
bool MyBST::remove(MyNodeBST* current, int data){
    if(current==nullptr){
        return false;
    } else if(data < current->data){
        return remove(current->left, data);
    } else if(data > current->data){
        return remove(current->right, data);
    } else{
        if(current->left && current->right){//Condicion para cuando se elimine un nodo con dos hijos
            MyNodeBST* minor = minimo(current->right);
            current->data = minor->data;
            remove(current->right,minor->data);
        }else if(current->left){ //condicion para cuando un nodo tiene un hijo (izquierdo)
            remplazo(current, current->left);
            delete current;
        } else if(current->right){ //Condicion para cuando un nodo tienen solo un hijo (derecho)
            remplazo(current, current->right);
            delete current;
        } else { //Caso para cuando el nodo a eliminar no tiene hijos
            remplazo(current, nullptr);
            delete current;
        }
    }
    return false;
}

//Complejidad O(n)
/* Esta funcion nos permite hacer un recorrido en preorden del BST*/
void MyBST::preorder(){
    preorder(root);
}

//Complejidad O(n)
/* Esta funcion nos permite imprime el recorrido en preorden del BST de manera recursiva (raiz, izquierda, derecha)*/
void MyBST::preorder(MyNodeBST* current){
    if(current!=nullptr){
        cout<<current->data<<",";
        preorder(current->left);
        preorder(current->right);
    } else {
        return;
    }
}

//Complejidad O(n)
/* Esta funcion nos permite hacer un recorrido en inorden del BST*/
void MyBST::inorder(){
    inorder(root);
}

//Complejidad O(n)
/* Esta funcion nos permite imprimir el recorrido en inorden del BST de manera recursiva (izquierda, raiz, derecha)*/
void MyBST::inorder(MyNodeBST* current){
    if(current!=nullptr){
        inorder(current->left);
        cout<<current->data<<",";
        inorder(current->right);
    } else{
        return;
    }
}

//Complejidad O(n)
/* Esta funcion nos permite hacer un recorrido en postorden del BST*/
void MyBST::postorder(){
    postorder(root);
}

//Complejidad O(n)
/* Esta funcion nos permite imprimir el recorrido en postorden del BST de manera recursiva (izquierda, derecha, raiz)*/
void MyBST::postorder(MyNodeBST* current){
    if(current!=nullptr){
        postorder(current->left);
        postorder(current->right);
        cout<<current->data<<",";
    } else {
        return;
    }
}

//Complejidad O(n)
/* Esta funcion nos permite hacer un recorrido en nivel del BST*/
void MyBST::level(){
    int h = height(root);
    for(int i=1;i<=h;i++){
        level(root,i);
    }
}

//Complejidad O(n)
/* Esta funcion nos permite imprimir un nivel especifico del arbol de manera recursiva*/
void MyBST::level(MyNodeBST* current, int nivel){
    if(current==nullptr){
        return;
    }
    if(nivel==1){
        cout<<current->data<<",";
    }else if(nivel>1){
        level(current->left,nivel-1);
        level(current->right,nivel-1);
    }
}

//Complejidad O(1)
/* Esta funcion nos permite seleccionar el tipo de recorrido que se le quiere hacer al BST*/
void MyBST::visit(int type){
    switch(type){
        case 1:
            preorder();
            break;
        case 2:
            inorder();
            break;
        case 3:
            postorder();
            break;
        case 4:
            level();
            break;
        default:
            cout<<"Opcion no valida"<<endl;
    }
}

//Complejidad O(1)
/* Esta funcion nos permite saber la altura del BST*/
int MyBST::height(){
    return height(root);
}

//Complejidad O(n)
/* Esta funcion nos permite saber la altura que tendra nuestro arbol de manera recursiva*/
int MyBST::height(MyNodeBST* current){
    if(current==nullptr){
        return 0;
    }
    int left = height(current->left);
    int right = height(current->right);
    if(left > right){
        return left+1;
    } else {
        return right+1;
    }
}

//Complejidad O(log n) en los casos promedio, en el peor O(n)
/* Esta funcion nos permite saber cual es el ancestor del nodo que se mande*/
void MyBST::ancestors(int data){
    MyNodeBST* current = root;
    if(current==nullptr){
        return;
    }
    while(current!=nullptr){
        if(current->data==data){
            return;
        }
        if(data<current->data){
            cout<<current->data<<",";
            current=current->left;
        }else{
            cout<<current->data<<",";
            current=current->right;
        }
    }
}

//Complejidad O(log n) en los casos promedio, en el peor O(n)
/* Esta funcion nos permite saber en que nivel se encuentra un nodo*/
int MyBST::whatLevelAmI(int data){
    if(root==nullptr){
        return -1;
    }
    MyNodeBST* current = root;
    int level = 0;
    while(current!=nullptr){
        if(current->data==data){
            return level;
        }
        if(data<current->data){
            current=current->left;
        }else{
            current=current->right;
        }
        level++;
    }
    return -1;
}

/* Cabe a clarar que los dios videos referenciados me ayuudaron a completar el metodo de remove, debido a que me dio na vision mas clara de las condiciones
algunos de los codigos dueron basados de esos video y otros solo siervieron como referencia.*/