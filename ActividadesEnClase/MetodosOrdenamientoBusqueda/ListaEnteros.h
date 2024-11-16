#ifndef LISTA_ENTEROS_H
#define LISTA_ENTEROS_H

class ListaEnteros
{
private:
    int* valores;
    int size, //Numeros de elementos almacenados
        lenght; //Capacidad del arreglo
        void Swap(int i, int j);
        void Mergesort(int ini, int fin);//Merge
        void Mezcla(int ini, int fin);//Merge
        void QuickSortHelper(int* valores, int low, int high);//Quick
        int Particion(int* valores, int low, int high);//Quick
public:
    ListaEnteros(int lenght); // inicializamos todas las variables
    ListaEnteros(int lenght, int valores[]); //tener una copia de las variables seleccionadas
    void Imprime();
    int BusquedaSecuencial(int valor);
    int BusquedaBinaria(int valor);
    void BubbleSort(int* valores);
    //~ListaEnteros();
    void SelectionSort(int* valores);
    void Insertsort(int* valores);
    void MergeSort(int* valores);//Fucion de preparacion
    void QuickSort(int* valores);
};

#endif // LISTA_ENTEROS_H