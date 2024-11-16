/*
En el siguiente programa veremos los metods necesearios para poder implementar un hash table asi como tambien la complejidad que tiene cada uno
y una breve descripcion de lo que hace cada uno de los metodos adenmas de que se agrego la calse MyLinkedList (clase la cual se habia hecho anteriormente)m 
esta clase nos sirvio ya que lo que hacemos es que cada una de las posiciones del arreglo de la tabla de hash sea una lista enlazada, esto nos ayuda a que
al momento de guardar un valor este se guarde en una lista si es que el la posicion ya tiene otro valor (la clase fue alterada para que pudiera ser compatible y
usable para este programa).
Nombre: Jesus Eduardo Escobar Meza
Matricula: A01743270
Fecha: 07/11/24
*/
#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include "MyLinkedList.h"

class MyHashTable{
    //private:
    public://Recuerden que esto sólo lo hacemos para poder revisar las actividades pero debería ser público aunque normalemnte se hacen privados
    MyLinkedList* tabla;
    int size; // La cantidad de elementos que hay en la tabla
    int sizeA; // Es el tamaño del arreglo
    void rehashing(); // Lo llama el put cuando el factor de carga excede a 0.75
                      // Incrementa el tamaño del arreglo al 2*sizeA+1 y reorganiza los elementos
    int getPos(string key);

    //public:
    MyHashTable();  // Tamaño inicial del arreglo 11
    ~MyHashTable();
    bool isEmpty();
    void put(string key, int value);
    int get(string key);
    void remove(string key);
};
#endif
//Todas las funcionalidades deberán de estar correctamente alineadas y documentadas. Como parte de la documentación deberá incluirse la complejidad de cada una de ellas.