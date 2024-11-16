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
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>


using namespace std;

struct MyNodoLL{
    string key;
    int data;
    MyNodoLL* next;
    
    MyNodoLL(string key, int data, MyNodoLL* next){
    this->key = key;
    this->data = data;
    this->next = next;
    }

    MyNodoLL(string key, int data):MyNodoLL(key, data, nullptr){}
};

class MyLinkedList{
    //private:
    public:
        int size;
        MyNodoLL *head,
                  *tail;
    //public:
        MyLinkedList(); 
        int length();
        bool isEmpty();
        ~MyLinkedList(); //Debe liberar la memoria de cada uno de los nodos.

        int getAt(string key);//Exc invalid_argument HACER
        void insertFirst(string key, int data);
        void removeFirst();//Exc invalid_argument Dudosa ya que se usa en el removeAt
        void removeAt(string key);//Exc invalid_argument HACER
        /*
        Esta esua funcion nos permite imprimir los valores de una lista enlaazada
        complejidad: O(n) en esta funciuon ambos casos contienen la misma complejidad ya que realmente la lista siempre va a recorrer todos
        los nodos que tenga la lista
        */
        friend ostream &operator<<(ostream& os,const MyLinkedList& ll){
            MyNodoLL* current = ll.head;
            for(int i = 0; i < ll.size; i++){
                os <<"[" << current->key << "," << current->data <<"],";
                current = current->next;
            }   
            return os;
        }       
};
#endif // MYLINKEDLIST_H
