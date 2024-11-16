#include <iostream>
#include "MyHashTable.h"
using namespace std;

int main() {
    MyHashTable* hashTable= new MyHashTable();

    // Prueba de tabla vacia
    cout << "La tabla esta vacia? " << (hashTable->isEmpty() ? "Si" : "No") << endl;

    // Insertar elementos iniciales
    cout << "\nInsertando elementos:" << endl;
    for (int i = 1; i <= 8; i++) {
        hashTable->put("clave" + to_string(i), i * 10);
    }

    // Mostrar el contenido de la tabla
    cout << "\nContenido de la tabla despues de las primeras inserciones:" << endl;
    for (int i = 0; i < hashTable->sizeA; i++) {
        cout << "Posicion " << i << ": " << hashTable->tabla[i] << endl;
    }

    // Obtener valores por clave
    cout << "\nPrueba de get para claves existentes:" << endl;
    for (int i = 1; i <= 8; i++) {
        try {
            int value = hashTable->get("clave" + to_string(i));
            cout << "Valor de clave" << i << ": " << value << endl;
        } catch (const std::exception& e) {
            cout << e.what() << endl;
        }
    }

    // Intentar obtener un valor de una clave inexistente
    cout << "\nPrueba de get para clave inexistente:" << endl;
    try {
        hashTable->get("clave_inexistente");
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    // Insertar mas elementos para forzar el rehashing
    cout << "\nInsertando mas elementos para desencadenar rehashing:" << endl;
    for (int i = 9; i <= 15; i++) {
        hashTable->put("clave" + to_string(i), i * 10);
    }

    // Mostrar la tabla despues de rehashing
    cout << "\nContenido de la tabla despues de rehashing:" << endl;
    for (int i = 0; i < hashTable->sizeA; i++) {
        cout << "Posicion " << i << ": " << hashTable->tabla[i] << endl;
    }

    // Prueba de eliminacion de elementos
    cout << "\nEliminando algunos elementos (clave3, clave6, clave10):" << endl;
    hashTable->remove("clave3");
    hashTable->remove("clave6");
    hashTable->remove("clave10");

    // Intentar eliminar un elemento que no existe
    cout << "\nIntentando eliminar una clave inexistente (clave100):" << endl;
    try {
        hashTable->remove("clave100");
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    // Verificar la tabla despues de las eliminaciones
    cout << "\nContenido de la tabla despues de las eliminaciones:" << endl;
    for (int i = 0; i < hashTable->sizeA; i++) {
        cout << "Posicion " << i << ": " << hashTable->tabla[i] << endl;
    }

    // Verificar si la tabla esta vacia despues de todas las operaciones
    cout << "\nLa tabla esta vacia? " << (hashTable->isEmpty() ? "Si" : "No") << endl;

    delete hashTable;

    cout<<"d";

    return 0;
}
