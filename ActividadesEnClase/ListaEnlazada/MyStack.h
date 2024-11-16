#ifndef MYSTACK_H
#define MYSTACK_H
#include "MyLinkedList.h"

class MyStack{
    private:
        MyLinkedList lista;
    public:
        /* No se necesita ni desgructor ni constructor */
        void push(int data);//Insertar el valor
        void pop();//Eliminar el valor
        int top();//ver cual es el elemnto mas arriba
        bool isEmpty();//checar si la lista no esta vacia
        int length();//Dar el largo
        void flush();//elimina todos los elementos
};

#endif