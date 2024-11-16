#include "MyBST.h"
#include <iostream>

using namespace std;

MyBST::MyBST(){
    this->size = 0;
    this->root = nullptr;
}

int MyBST::length(){
    return this->size;
}

bool MyBST::isEmpty(){
    return this->size == 0;
}

bool MyBST::search(int data){
    MyNodeBST *current = this->root;
    while(current != nullptr){
        if(current->data == data){
            return true;
        }else if(current->data < data){
            current = current->right;
        }else{
            current = current->left;
        }
    }
    return false;

    /*while(current != nullptr){
        if(current->data == data){
            return true;
        }else{
                        //condicion         valor V      valor F
            current = data<current->data?current->left:current->right;
        }
    }
    return false;*/

    /*while(current != nullptr){
        if(this->root == data){
            return true;
        }else if(this->current < data){
            return searchRec(current->right, data)
        }
        else{
            return searchRec(current->left, data)
        }
    }
    return false;*/
}

bool MyBST::searchRec(int data){
    return searchRec(data, this->root);
}

bool MyBST::searchRec(int data, MyNodeBST *current){
    if(current == nullptr){
        return false;
    }
    if(current->data == data){
        return true;
    }
    if(data < current->data){
        return searchRec(data, current->left);
    }else{
        return searchRec(data, current->right);
    }
}

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

MyBST::~MyBST(){
    while(!isEmpty()){
        remove();
    }
}


/*bool MyBST::search(int data){
    MyNodeBST* current = root;
    while(current!=nullptr){
        if(current->data==data){
            return true;
        }
        if(data<current->data){
            current=current->left;
        }else{
            current=current->right;
        }
    }
    return false;
}*/

/*
Convierte el árbol a un array ordenado.
*/
void MyBST::treeToArray(MyNodeBST* node, int* array, int &index){
    if(node == nullptr){
        return;
    }
    treeToArray(node->left, array, index);
    array[index++] = node->data;
    treeToArray(node->right, array, index);
}

/*
Convierte un array ordenado de nuevo a un BST equilibrado.
*/
MyNodeBST* MyBST::arrayToTree(int* array, int start, int end){
    if(start > end){
        return nullptr;
    }
    int mid = (start + end) / 2;
    MyNodeBST* nuevo = new MyNodeBST(array[mid]);
    nuevo->left = arrayToTree(array, start, mid-1);
    nuevo->right = arrayToTree(array, mid+1, end);
    return nuevo;
}

// FUNCIONES PARA LE METODO DE ORDENAMIENTO
void MyBST::mergeSort(){
    if(this->size == 0) return;
        int* array = new int[this->size];
        int index = 0;
        treeToArray(this->root, array, index);
        merge(array, 0, this->size-1);
        delete[] array;
}

void MyBST::merge(int* array, int ini, int fin){
    if(ini < fin){
        int mid = (ini + fin)/2;
        merge(array, ini, mid);
        merge(array, mid+1, fin);
        mezcla(array, ini, mid, fin);
    }
}
 
void mezcla(int* array, int ini, int mid, int fin){
    int n1 = mid-ini+1;
    int n2 = fin-mid;
    int* izq = new int[n1];
    int* der = new int[n2];
    for (int i = 0; i < n1; i++){
        izq[i] = array[ini+i];
    }
    for(int j = 0; j < n2; j++){
        der[j] = array[mid=1+j];
    }
    int i = 0, j = 0, k = ini;
    while(i < n1 && j < n2){
        if(izq[i] <= der[j]){
            array[k] = izq[i];
            i++;
        }else{
            array[k] = der[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        array[k] = izq[i];
        i++;
        k++;
    }
    while(j < n2){
        array[k] = der[j];
        j++;
        k++;
    }
    delete[] izq;
    delete[] der;
}