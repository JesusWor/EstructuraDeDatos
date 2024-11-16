#include "ListaEnteros.h"
#include <iostream>
//C:\Users\Pity\Documents\TECMO\Semestre 3\Estrutura de datos\Lista
int main(){
    int valores[] = {50,73,25,80,60,30,40};
    int tamano = sizeof(valores)/sizeof(*valores);
    ListaEnteros le(tamano,valores);
    valores[0] = 59;
    le.Imprime();
    int valor = 25;
    int poss = le.BusquedaSecuencial(valor);
    std::cout << "El elemento " << valor << " esta en la posicion "<< poss << std::endl;
    le.QuickSort(valores);
    le.Imprime();
    int posb = le.BusquedaBinaria(valor);
    std::cout << "El elemento " << valor << " esta en la posicion "<< posb << std::endl;
}