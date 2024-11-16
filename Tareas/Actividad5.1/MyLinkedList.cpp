/* 
Implmentacion de listas enlazadas
En el siguiente codigo veremos las funciones que necesitamos y como es que estas funcionaran para poder implementar el algoritmo de 
listas enlazadas codigo que anteriormente se habia hecho pero que se tuvo que modificar para que pudiera ser compatible con el programa
de la tabla de hash ya que algunas funciones fueron removidas ya que no eran neceserias y algunas otras fueron modificadas para su buen 
funcionamiento.
Nombre: Jesus Eduardo Escobar Meza
Matricula: A01743270
Fecha: 07/11/24
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
Complejidad: O(n).
Descripción: Destruye la lista enlazada eliminando todos los nodos, 
llamando repetidamente a removeFirst(). Se asegura de liberar la memoria utilizada por cada nodo.
*/
MyLinkedList::~MyLinkedList(){
    while(!isEmpty()){
        removeFirst();
    }
}

/*
Complejidad: O(1).
Descripción: Devuelve el número de elementos en la lista. Simplemente retorna el valor de size, 
que se mantiene actualizado en todas las operaciones de inserción y eliminación.
*/
int MyLinkedList::length(){
    return size;
}

/*
Complejidad: O(1).
Descripción: Verifica si la lista está vacía. Retorna true si el tamaño 
de la lista es 0, de lo contrario, retorna false.
*/
bool MyLinkedList::isEmpty(){
    //return this->head = nullptr;
    return this->size == 0;
}

/*
Complejidad: O(n).
Descripción: Esta funcion nos permite buscar un nodo en la lista enlazada en dopnde key tiene que ser igual 
a la llave propocionada. Va buscando de manera secuencial y cuando lo encuentra regresa el valor del nodo.
*/
int MyLinkedList::getAt(string key){
    //buscar el elemento que tiene la llave key y regresar su el data (value)
    //si no existe la llave, lanzar una excepcion
    MyNodoLL* tmp = head; // Se comienza desde el primer nodo
    while(tmp != nullptr){
        if(tmp->key == key){
            return tmp->data;
        }
        tmp = tmp->next;
    }
    throw invalid_argument("No se encontro la llave (getAtMLL)");
}

/*
Complejidad: O(1).
Descripcion: Inserta un nuevo nodo al principio de la lista. Se crea un nuevo nodo con la llave y el valor proporcionados,
y se establece el puntero next del nuevo nodo al nodo actual en la cabeza de la lista. Luego se actualiza el head para que
apunte al nuevo nodo.
*/
void MyLinkedList::insertFirst(string key, int data){
    MyNodoLL* nuevo = new MyNodoLL(key, data, this->head); //Se crea un nuevo nodo
    if(this->size == 0){
        this->tail = nuevo;
    }
    this->head = nuevo;
    this->size++; //El size se incrementa
}

/*
Complejidad: O(1).
Descripción: Elimina el primer nodo de la lista. Si la lista está vacía, lanza una excepción. Si el tamaño se reduce a 0 después 
de la eliminación, el puntero tail también se actualiza a nullptr.
*/
void MyLinkedList::removeFirst(){
    if(this->size > 0 ){
        MyNodoLL* tmp = this->head;
        this->head = this->head->next;
        delete tmp;
        this->size--;
        if(this->size == 0){
            this->tail = nullptr;
        }
    }else{
       throw invalid_argument("No se puede borrar el primer elemento de una lista vacia");
    }
}

/*
Complejidad: O(n) en el peor de los casos y en el mejor de los casos es O(1).
Descripción: Elimina el nodo que tiene la llave proporcionada. Si la llave no se encuentra en el rango de datos
manda una excepcion.
*/
void MyLinkedList::removeAt(string key){
    //buscar el elemento que tiene la llave key y lo borra de la lista 
    //si no existe la llave, lanzar una excepcionx
    MyNodoLL* primero = this->head;
    MyNodoLL* ante = nullptr;
    while(primero != nullptr && primero->key != key){
        ante = primero;
        primero = primero->next;
    }
    if(primero == nullptr){
        throw invalid_argument("No se encontro la llave (removeAtMLL)");
    }
    if(primero == this->head) { 
        this->head = this->head->next; 
        if(this->head == nullptr) { 
            this->tail = nullptr; 
        } 
    } else { 
        ante->next = primero->next; 
        if(primero == this->tail) { 
            this->tail = ante; 
        } 
    } 
    delete primero; 
    this->size--; 
}
