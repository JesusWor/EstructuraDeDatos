// Equipo 3
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
// Descripcion: Este programa hace uso de una hash table concatenada medainte un BST para el guardado y acomodo
// de Registros dados mediane un archivo

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
