#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "MyLinkedList.h"
#include <iostream>

using namespace std;

class MyHashTable{
    private:
    //public: //Recuerden que esto sólo lo hacemos para poder revisar las actividades pero debería ser público
        MyLinkedList* tabla;
        int size; //Cantidad de valores que hay almacenados en la tabla
        int sizeA; //Cantidad del arreglo
        void rehashing(); //Crece el arreglo al doble del tamaño del arreglo actual + 1. 
                        //Se llama cuando el facor de carga excede 0.75
        int getPos(string key);

        void leerArchivo(string nombreArchivo);
        void insertLine(string linea);
        int obtenerFechaID(string mes, int dia, int hora, int minuto, int segundo);

    public:
        MyHashTable();  //Tamaño inicial 11
        MyHashTable(string archivoNombre);  //Tamaño inicial 11
        ~MyHashTable();
        bool isEmpty();
        void put(string key, string data, int id);
        string get(string key);
        void remove(string key);

        void busqueda();
        void showList(string key);
};

#endif


//Todas las funcionalidades deberán de estar correctamente alineadas y documentadas. Como parte de la documentación deberá incluirse la complejidad de cada una de ellas.
