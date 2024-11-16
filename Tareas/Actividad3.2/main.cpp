/*#include "MyHeap.h"
#include <iostream>

using namespace std;

int main() {
    // Crear un heap vacío
    MyHeap heap;

    // Insertar elementos en el heap
    heap.push(10);
    heap.push(20);
    heap.push(15);
    heap.push(30);
    heap.push(25);

    // Imprimir los elementos del heap
    cout << "Contenido del heap despues de las inserciones: " << endl;
    heap.imprimir();

    // Verificar si el heap está vacío
    if (heap.isEmpty()) {
        cout << "El heap está vacio." << endl;
    } else {
        cout << "El heap no esta vacio." << endl;
    }

    // Eliminar el elemento del tope (pop)
    heap.pop();
    cout << "Contenido del heap despues de eliminar el elemento maximo (pop): " << endl;
    heap.imprimir();

    // Ver el tamaño del heap
    cout << "Tamaño del heap: " << heap.length() << endl;

    return 0;
}*/

#include <iostream>
#include "MyHeap.h"

using namespace std;

int main() {
    // Crear un heap vacio
    cout << "Prueba 1: Creando un heap vacio\n";
    MyHeap heap;
    heap.imprimir();
    cout << "El heap esta vacio? " << (heap.isEmpty() ? "Si" : "No") << endl;
    
    // Insertar valores en el heap
    cout << "\nPrueba 2: Insertando valores [10, 5, 30, 2, 8, 15, 40]\n";
    int valores[] = {10, 5, 30, 2, 8, 15, 40};
    for (int i = 0; i < 7; i++) {
        heap.push(valores[i]);
        heap.imprimir();
    }
    cout << "El heap esta vacio? " << (heap.isEmpty() ? "Si" : "No") << endl;
    cout << "Numero de elementos en el heap: " << heap.length() << endl;
    cout << "Elemento en el tope del heap: " << heap.top() << endl;

    // Eliminar elementos del heap
    cout << "\nPrueba 3: Eliminando elementos del heap\n";
    while (!heap.isEmpty()) {
        cout << "Elemento eliminado: " << heap.top() << endl;
        heap.pop();
        heap.imprimir();
    }
    cout << "El heap esta vacio? " << (heap.isEmpty() ? "Si" : "No") << endl;

    // Construir un heap con un arreglo dado
    cout << "\nPrueba 4: Construyendo un heap a partir de un arreglo [7, 3, 10, 1, 9, 8]\n";
    int valores2[] = {7, 3, 10, 1, 9, 8};
    MyHeap heap2(valores2, 6);
    heap2.imprimir();
    cout << "Numero de elementos en el heap2: " << heap2.length() << endl;
    cout << "Elemento en el tope del heap2: " << heap2.top() << endl;

    // Insertar mas elementos y verificar redimensionamiento
    cout << "\nPrueba 5: Insertando mas valores en el heap2 [12, 4, 20, 16]\n";
    int valores3[] = {12, 4, 20, 16};
    for (int i = 0; i < 4; i++) {
        heap2.push(valores3[i]);
        heap2.imprimir();
    }
    cout << "Numero de elementos en el heap2: " << heap2.length() << endl;
    cout << "Elemento en el tope del heap2: " << heap2.top() << endl;

    // Realizar varias eliminaciones en heap2
    cout << "\nPrueba 6: Eliminando elementos del heap2\n";
    while (!heap2.isEmpty()) {
        cout << "Elemento eliminado: " << heap2.top() << endl;
        heap2.pop();
        heap2.imprimir();
    }
    cout << "El heap2 esta vacio? " << (heap2.isEmpty() ? "Si" : "No") << endl;

    // Prueba de inserciones y eliminaciones repetidas
    cout << "\nPrueba 7: Inserciones y eliminaciones repetidas en heap\n";
    for (int i = 1; i <= 10; i++) {
        heap.push(i);
    }
    heap.imprimir();
    cout << "Numero de elementos en el heap: " << heap.length() << endl;
    
    for (int i = 0; i < 5; i++) {
        cout << "Elemento eliminado: " << heap.top() << endl;
        heap.pop();
        heap.imprimir();
    }
    cout << "Numero de elementos en el heap despues de eliminar 5 elementos: " << heap.length() << endl;
    
    // Insertar de nuevo en el heap
    cout << "\nPrueba 8: Insertar [25, 17, 32] en el heap\n";
    int valores4[] = {25, 17, 32};
    for (int i = 0; i < 3; i++) {
        heap.push(valores4[i]);
        heap.imprimir();
    }
    cout << "Numero de elementos en el heap: " << heap.length() << endl;

    cout << "\nPrueba completada.\n";
    return 0;
}