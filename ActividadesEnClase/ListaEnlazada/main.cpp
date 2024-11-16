#include "MyLinkedList.h"
#include "MyStack.h"
#include "MyQueue.h"

#include <iostream>

using namespace std;

int main()
{
    try
    {
        MyLinkedList lista;

        lista.insertFirst(10);
        lista.insertFirst(20);
        lista.insertFirst(30);
        cout << "Lista despues de insertar al inicio: " << lista << endl;
        lista.insertLast(40);
        lista.insertLast(50);
        cout << "Lista despues de insertar al final: " << lista << endl;
        lista.insertAt(2, 25);
        cout << "Lista despues de insertar en la posicion 2: " << lista << endl;
        cout << "Primer elemento: " << lista.first() << endl;
        cout << "Ultimo elemento: " << lista.last() << endl;
        cout << "Elemento en la posición 2: " << lista.getAt(2) << endl;
        lista.setAt(2, 100);
        cout << "Lista despues de modificar el elemento en la posicion 2: " << lista << endl;
        lista.removeFirst();
        cout << "Lista despues de eliminar el primer elemento: " << lista << endl;
        lista.removeLast();
        cout << "Lista despues de eliminar el ultimo elemento: " << lista << endl;
        lista.removeAt(1);
        cout << "Lista despues de eliminar el elemento en la posicion 1: " << lista << endl;

        MyStack pila;
        for(int i = 0; i < 100; i++){
            pila.push(i);
        }

        while(!pila.isEmpty()){
            cout << pila.top() << " ";
            pila.pop();
        }
    }
    catch (invalid_argument ex) 
    {
        cout << "Se presento una excepcion " << ex.what() << endl;
    }
    return 0;
}