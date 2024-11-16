/* 
Implmentacion de listas enlazadas
En el siguiente codigo veremos las funciones que necesitamos y como es que 
estas funcionaran para poder implementar el algoritmo de listas enlazadas
Jesús Eduardo Escobar Meza A01743270
27/09/24
*/
#include "MyLinkedList.h"
#include <iostream>
#include <stdexcept>
using namespace std;

/*
Complejidad: O(1)
Descripción: Inicializa la lista enlazada. Establece el tamaño de la 
lista (size) en 0 y tanto el puntero head como tail a nullptr. 
Esto indica que la lista está vacía.
*/
MyLinkedList::MyLinkedList(){
    this->size = 0;
    this->head = this->tail = nullptr;
}

/*
Complejidad: O(n)
Descripción: Destruye la lista enlazada eliminando todos los nodos, 
llamando repetidamente a removeFirst(). Se asegura de liberar la memoria utilizada por cada nodo.
*/
MyLinkedList::~MyLinkedList(){
    while(!isEmpty()){
        removeFirst();
    }
}

/*
Complejidad: O(1)
Descripción: Devuelve el número de elementos en la lista. Simplemente retorna el valor de size, 
que se mantiene actualizado en todas las operaciones de inserción y eliminación.
*/
int MyLinkedList::length(){
    return size;
}

/*
Complejidad: O(1)
Descripción: Verifica si la lista está vacía. Retorna true si el tamaño 
de la lista es 0, de lo contrario, retorna false.
*/
bool MyLinkedList::isEmpty(){
    //return this->head = nullptr;
    return this->size = 0;
}


/*
Complejidad: O(1)
Descripción: Devuelve el valor del primer nodo en la lista (nodo apuntado por head). 
Si la lista está vacía, lanza una excepción invalid_argument.
*/
int MyLinkedList::first(){
    if (this->size > 0) {
        return this->head->data;
    }else{
        throw invalid_argument("No se pude regresar el primer elemento de una lista vacia");
    }
}

/*
Complejidad: O(1)
Descripción: Devuelve el valor del último nodo en la lista (nodo apuntado por tail). 
Si la lista está vacía, lanza una excepción invalid_argument.
*/
int MyLinkedList::last(){
    if(this->size > 0){
        return this->tail->data;
    }else{
        throw invalid_argument("No se pude regresar el ultimo elemento de una lista vacia");
    }
}

/*
Complejidad: O(1)
Descripción: Inserta un nuevo nodo con el valor data al principio de la lista. Si la lista está vacía, 
el nuevo nodo es tanto el head como el tail. Si no, el nuevo nodo se convierte en el head de la lista, 
apuntando al nodo anterior como next.
*/
void MyLinkedList::insertFirst(int data){
    //Si la lista esta vacia
    if(this->size == 0){
        MyNodoLL* nuevo = new MyNodoLL(data); //Se crea un nuevo nodo
        this->head = this->tail = nuevo; //Head y tail se vuelven iguales al nuevo nodo
    }
    //Caso general
    MyNodoLL* nuevo = new MyNodoLL(data); //Se crea un nuevo nodo
    nuevo -> next = head; //El nuevo nodo toma el valor del next
    this->head=nuevo; // Head se vuelve igual al nuevo
    this->size++; //El size se va incrementando
}

/*
Complejidad: O(n)
Descripción: Devuelve el valor del nodo en la posición pos. Se recorre la lista desde el primer nodo 
hasta alcanzar la posición pos. Si la posición es inválida, lanza una excepción invalid_argument.
*/
int MyLinkedList::getAt(int pos){
    if(pos < 0 || pos >= this->size){
        throw invalid_argument("Posicion invalida");
    }
    MyNodoLL* tmp = this->head;
    for(int i = 0; i < pos; i++){
        tmp = tmp->next;
    }
    return tmp->data;
}

/*
Complejidad: O(n)
Descripción: Modifica el valor del nodo en la posición pos con el nuevo valor data. Se recorre 
la lista hasta llegar a la posición pos. Si la posición es inválida, lanza una excepción invalid_argument.
*/
void MyLinkedList::setAt(int pos, int data){
    if(pos < 0 || pos >= this->size){
        throw invalid_argument("Posicion invalida");
    }
    MyNodoLL* tmp = this->head;
    for(int i = 0; i < pos; i++){
        tmp = tmp->next;
    }
    tmp->data = data;
}

/*
Complejidad: O(1)
Descripción: Inserta un nuevo nodo con el valor data al final de la lista. Si la lista está vacía, el nuevo nodo es tanto 
el head como el tail. Si no, el nuevo nodo se añade al final y el puntero tail se actualiza para apuntar al nuevo nodo.
*/
void MyLinkedList::insertLast(int data){
    if(this->size == 0){
        MyNodoLL* nuevo = new MyNodoLL(data);
        this->head = this->tail = nuevo;
    }else{
        MyNodoLL* nuevo = new MyNodoLL(data);
        this->tail->next = nuevo;
        this->tail = nuevo;
    }
    this->size++;
}

/*
Complejidad: O(n)
Descripción: Inserta un nuevo nodo con el valor data en la posición pos. Si la posición es 0, inserta al principio (usando insertFirst). 
Si es igual al tamaño de la lista, inserta al final (usando insertLast). Si es intermedia, recorre la lista hasta la posición pos - 1 e 
inserta el nuevo nodo en el medio.
*/
void MyLinkedList::insertAt(int pos, int data){
    if(pos < 0 || pos > this->size){
        throw invalid_argument("Posicion invalida");
    }
    if(pos == 0){
        insertFirst(data);
    }else if(pos == this->size){
        insertLast(data);
    }else{
        MyNodoLL* tmp = this->head;
        for(int i = 0; i < pos - 1; i++){
            tmp = tmp->next;
        }
        MyNodoLL* nuevo = new MyNodoLL(data);
        nuevo->next = tmp->next;
        tmp->next = nuevo;
        this->size++;
    }
}

/*
Complejidad: O(1)
Descripción: Elimina el primer nodo de la lista. Si la lista está vacía, lanza una excepción. Si el tamaño se reduce a 0 después 
de la eliminación, el puntero tail también se actualiza a nullptr.
*/
void MyLinkedList::removeFirst(){
    if(this->size > 0 ){
        MyNodoLL* tmp = this->head;
        this->head = this->head->next;
        delete tmp;
        size--;
        if(this->size == 0){
            this->tail = nullptr;
        }
    }else{
       throw invalid_argument("No se puede borrar el primer elemento de una lista vacia");
    }
}

/*
Complejidad: O(n)
Descripción: Elimina el último nodo de la lista. Si la lista está vacía, lanza una excepción. La operación requiere recorrer 
la lista para llegar al penúltimo nodo y actualizar el puntero tail.
*/
void MyLinkedList::removeLast(){
    if(this->size > 0){
        MyNodoLL* tmp = this->tail;
        this->tail = this->tail->next;
        delete tmp;
        size--;
        if(this->size == 0){
            this->head = nullptr;
        }
    }else{
         throw invalid_argument("No se puede borrar el ultimo elemento de una lista");
    }
}

/*
Complejidad: O(n)
Descripción: Elimina el nodo en la posición pos. Si es la primera posición, se llama a removeFirst(). 
Si es la última, se llama a removeLast(). Si es una posición intermedia, recorre la lista hasta pos - 1 
y elimina el nodo en pos.
*/
void MyLinkedList::removeAt(int pos){
    if(pos < 0 || pos >= this->size){
        throw invalid_argument("Posicion invalida");
    }
    if(pos == 0){
        removeFirst();
    }else if (pos == this->size){
        removeLast();
    }else{
        MyNodoLL* tmp = this->head;
        for(int i = 0; i < pos - 1; i++){
            tmp = tmp->next;
        }
        MyNodoLL* tmp2 = tmp->next;
        tmp->next = tmp2->next;
        delete tmp2;
        this->size--;
    }
}

/*
Complejidad: O(n)
Descripción: Sobrecarga del operador << para imprimir los valores de los nodos de la lista enlazada. Recorre la lista 
    y envía los valores de cada nodo al flujo de salida (ostream).
*/
ostream &operator<<(ostream& os, const MyLinkedList& ll){
    MyNodoLL* tmp = ll.head;
    while(tmp != nullptr){
        os << tmp->data << ",";
        tmp = tmp->next;
    }
    return os;
}

/*
Metodo par obtener un nodo en una posicion en especifico
*/
MyNodoLL* MyLinkedList::getNodoAt(int pos){
    MyNodoLL* tmp = this->head;
    for(int i = 0; i < pos; i++){
        tmp = tmp->next;
    }
    return tmp;
}

/* acontinuacion veremos las funcion necesariaos para ordenar una lista enlazda 
mediante el metodo mergeSort*/
void MyLinkedList::Mezcla(int ini, int fin){
    
}

void MyLinkedList::Mergesort(int ini, int fin){
    if(ini < fin){
        int mitad = (ini + fin)/2;
        Mergesort(ini, mitad);
        Mergesort(mitad+1,fin);
        Mezcla(ini,fin);
    }
}

void MyLinkedList::mergeSort(){
    if(this->size > 1){
        MergeSort(0, this->size-1);
    } else {
        return;
    }
}