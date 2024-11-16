#include "MyBST.h"
#include <iostream>

int main() {
    MyBST bst;

    // Verificar si el árbol está vacío
    std::cout << "El arbol esta vacio? " << (bst.isEmpty() ? "Si" : "No") << std::endl;

    // Insertar un valor
    bst.insert(10);

    // Verificar la altura del árbol
    std::cout << "Altura del arbol: " << bst.height() << std::endl;

    return 0;
}
