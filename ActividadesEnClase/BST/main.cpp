#include "MyBST.h"
#include <iostream>

using namespace std;

int main() {
    MyBST tree;

    // Prueba de inserción
    cout << "Insertando elementos en el arbol:" << endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    cout << "Elementos insertados: 50, 30, 70, 20, 40, 60, 80" << endl;

    // Prueba de longitud y verificación de vacío
    cout << "Tamaño del arbol: " << tree.length() << endl;
    cout << "¿El árbol esta vacio? " << (tree.isEmpty() ? "Si" : "No") << endl;

    // Prueba de búsqueda
    cout << "Buscando elementos 40 y 100 en el árbol:" << endl;
    cout << "¿Elemento 40 está en el arbol? " << (tree.search(40) ? "Sí" : "No") << endl;
    cout << "¿Elemento 100 está en el arbol? " << (tree.search(100) ? "Sí" : "No") << endl;

    // Prueba de recorrido en diferentes órdenes
    cout << "Recorrido en preorden:" << endl;
    tree.preorder();
    cout << endl;

    cout << "Recorrido en inorden:" << endl;
    tree.inorder();
    cout << endl;

    cout << "Recorrido en postorden:" << endl;
    tree.postorder();
    cout << endl;

    cout << "Recorrido por niveles:" << endl;
    tree.level();
    cout << endl;

    // Prueba de altura
    cout << "Altura del arbol: " << tree.height() << endl;

    // Prueba de ancestros
    cout << "Ancestros del nodo 40:" << endl;
    tree.ancestors(40);
    cout << endl;

    // Prueba del nivel del nodo
    cout << "Nivel del nodo 40: " << tree.whatLevelAmI(40) << endl;
    cout << "Nivel del nodo 100 (no existente): " << tree.whatLevelAmI(100) << endl;

    // Prueba de eliminación
    cout << "Eliminando elementos 20, 30 y 50 del arbol:" << endl;
    tree.remove(20);
    tree.remove(30);
    tree.remove(50);

    cout << "Recorrido en inorden despues de eliminar 20, 30, 50:" << endl;
    tree.inorder();
    cout << endl;

    // Prueba de merge sort
    cout << "Probando ordenamiento (mergeSort):" << endl;
    tree.mergeSort();
    cout << "Elementos ordenados en inorden despues de mergeSort:" << endl;
    tree.inorder();
    cout << endl;

    return 0;
}
