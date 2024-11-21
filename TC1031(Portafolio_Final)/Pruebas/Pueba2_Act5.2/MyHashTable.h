/*#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "MyBST.h"
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
        int getPos(string key);//modificar

        void leerArchivo(string nombreArchivo);
        void insertLine(string linea);
        int obtenerFechaID(string mes, int dia, int hora, int minuto, int segundo);

    public:
        MyHashTable();  //Tamaño inicial 11
        MyHashTable(string archivoNombre);  //Tamaño inicial 11
        ~MyHashTable();
        bool isEmpty();
        void put(string key, string data, int id);//modificar
        string get(string key);
        void remove(string key);

        void busqueda();//modificar
        void showList(string key);//modificar
};

#endif*/

#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include <string>
#include "MyBST.h"
using namespace std;

class MyHashTable {
private:
    int size;         // Número de elementos actuales en la tabla hash
    int sizeA;        // Tamaño de la tabla hash
    MyBST* tabla;     // Arreglo dinámico de árboles binarios de búsqueda (BST)

    int getPos(string key);                 // Calcula la posición hash para una llave
    void rehashing();                       // Reajusta la tabla hash al aumentar de tamaño
    void leerArchivo(string nombreArchivo); // Lee y procesa un archivo con los registros
    void insertLine(string linea);          // Procesa una línea del archivo y la inserta en la tabla
    int obtenerFechaID(string mes, int diaN, int horaN, int minutoN, int segundoN); // Calcula el ID basado en la fecha y tiempo

public:
    MyHashTable();                          // Constructor por defecto
    MyHashTable(string nombreArchivo);      // Constructor que lee los registros desde un archivo
    ~MyHashTable();                         // Destructor para liberar memoria
    bool isEmpty();                         // Verifica si la tabla hash está vacía
    void put(string key, string data, int id); // Inserta un nuevo nodo en la posición hash calculada
    void showList(string key);              // Muestra la lista de registros para una llave específica
    void remove(string key);                // Elimina registros por llave (incompleto)
    void busqueda();                        // Realiza la búsqueda de registros por IP
};

#endif



//Todas las funcionalidades deberán de estar correctamente alineadas y documentadas. Como parte de la documentación deberá incluirse la complejidad de cada una de ellas.
