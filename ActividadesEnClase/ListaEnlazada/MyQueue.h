#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "MyLinkedList.h"

class MyQueue
{
private:
    MyLinkedList lista;
public:
    /* No se necesita ni desgructor ni constructor */
    void enqueue(int data);//Insertar el valor
    void dequeue();//Eliminar el valor
    int peek();//ver cual es el siguiente elemento en salir
    bool isEmpty();//checar si la lista no esta vacia
    int length();//Dar el largo
    void flush();//elimina todos los elementos
};

#endif // MYQUEUE_H
