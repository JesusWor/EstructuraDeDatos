/* 
Implmentacion de listas enlazadas
En el siguiente codigo veremos las funciones que necesitamos para poder 
implementar el algoritmo de listas enlazadas
Jesús Eduardo Escobar Meza A01743270
27/09/24
*/
#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

//Se declara la clase nodo en la cuales podremos dar los valores del dato (data) y el dato siguiente (next)
struct MyNodoLL{
    int data;
    MyNodoLL* next;
    
    MyNodoLL(int data, MyNodoLL* next){
        this->data = data;
        this->next = next;
    }

    MyNodoLL(int data):MyNodoLL(data, nullptr){}
};

//Se declara la clase MyLinkedList en la cual se podran realizar las operaciones de la lista enlazada
//En el archivo .cpp se dara una breve explicacion sobre las funciones y su complejidad
class MyLinkedList{
    public:
        int size;
        MyNodoLL *head,
                  *tail;

        MyLinkedList();
        int length();
        bool isEmpty();
        int first();//Exc invalid_argument
        int last(); //Exc invalid_argument
        ~MyLinkedList(); //Debe liberar la memoria de cada uno de los nodos.

        int getAt(int pos);//Exc invalid_argument
        void setAt(int pos, int data); //Exc invalid_argument
        void insertFirst(int data);
        void insertLast(int data);
        void insertAt(int pos, int data);//pos:[0,size] Exc invalid_argument
        void removeFirst();//Exc invalid_argument
        void removeLast();//Exc invalid_argument
        void removeAt(int pos);//pos:[0,size] Exc invalid_argument
        friend ostream &operator<<(ostream& os,const MyLinkedList& ll);
};
#endif // MYLINKEDLIST_H