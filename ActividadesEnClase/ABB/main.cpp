#include <iostream>
#include "MyBST.h"

using namespace std;

int main() {
    MyBST tree;

    // Prueba de la función `isEmpty`
    cout << "¿El árbol está vacío? " << (tree.isEmpty() ? "Sí" : "No") << endl;

    // Prueba de `insert`
    cout << "Insertando valores..." << endl;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(7);
    tree.insert(15);
    tree.insert(30);

    // Verificando si los valores están insertados
    cout << "¿El árbol está vacío? " << (tree.isEmpty() ? "Sí" : "No") << endl;
    cout << "Tamaño del árbol: " << tree.length() << endl;

    // Prueba de `search`
    cout << "¿El valor 7 está en el árbol? " << (tree.search(7) ? "Sí" : "No") << endl;
    cout << "¿El valor 100 está en el árbol? " << (tree.search(100) ? "Sí" : "No") << endl;

    // Prueba de `remove`
    cout << "Eliminando el valor 20..." << endl;
    tree.remove(20);
    cout << "¿El valor 20 está en el árbol? " << (tree.search(20) ? "Sí" : "No") << endl;

    // Convertir el árbol a un arreglo ordenado
    int* arr = new int[tree.length()];
    int index = 0;
    //tree.treeToArray(tree.getRoot(), arr, index);

    cout << "Árbol convertido a arreglo ordenado: ";
    for (int i = 0; i < tree.length(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Convertir el arreglo de nuevo a un árbol equilibrado
    MyNodeBST* balancedRoot = tree.arrayToTree(arr, 0, tree.length() - 1);
    cout << "Árbol convertido de nuevo a un BST equilibrado." << endl;

    // Prueba de `mergeSort`
    cout << "Ejecutando mergeSort en el árbol..." << endl;
    tree.mergeSort();

    cout << "Árbol ordenado: ";
    index = 0;
    //tree.treeToArray(tree.getRoot(), arr, index);
    for (int i = 0; i < tree.length(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Liberar memoria del arreglo
    delete[] arr;

    // Prueba del destructor
    cout << "Liberando memoria y eliminando el árbol." << endl;

    return 0;
}
