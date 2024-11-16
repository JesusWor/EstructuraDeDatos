#include "ListaEnteros.h"
#include <iostream>
#include <vector>
using namespace std;

ListaEnteros::ListaEnteros(int lenght)
{
    this->lenght = lenght;
    this->size = 0;
    this->valores = new int[lenght];
}

ListaEnteros::ListaEnteros(int lenght, int valores[]) : ListaEnteros(lenght)
{
    this->size = lenght;
    for (int i = 0; i < lenght; i++)
    {
        this->valores[i] = valores[i];
    }
    this->valores = valores;
}

void ListaEnteros::Swap(int i, int j){
    int temp = this->valores[i];
    this->valores[i] = this->valores[j];
    this->valores[j] = temp;
}

void ListaEnteros::Imprime()
{
    for (int i = 0; i < this->lenght; i++)
    {
        cout << this->valores[i] << " , ";
    }
    cout << endl;
}

int ListaEnteros::BusquedaSecuencial(int valor){
    for (int i = 0; i < lenght; i++){
        if (this->valores[i] == valor){
            return i;
        }
    }
    return -1;
}

int ListaEnteros::BusquedaBinaria(int valor)
{
    int min = 0,
        max = this->size - 1,
        avg;
    while (min <= max)
    {
        avg = (min + max) / 2;
        if (this->valores[avg] == valor)
        {
            return avg;
        }
        else if (valor > this->valores[avg])
        {
            min = avg + 1;
        }
        else
        {
            max = avg - 1;
        }
    }
    return -1;
}

void ListaEnteros::BubbleSort(int* valores){
    //Codigo hecho por el profesor
    //Requiere (n-1) iteraciones
    bool ordenado = false;
    for (int i = 0; i < this->size - 1 && !ordenado; i++){
        ordenado = true;
        for (int j = 0; j < this->size - 1 - i; j++){
            if(this->valores[j] > this->valores[j+1])
            {
                Swap(j,j+1);
                ordenado = false;
            }
        }
    }
    //Codigo hecho por mi
    /*for (int i = 0; i < this->size - 1; i++){
        for (int j = i + 1; j < this->size; j++){
            if(this->valores[i] > this->valores[j])
            {
                Swap(i,j);
            }
        }
    }*/
}

void ListaEnteros::SelectionSort(int* valores){
    int posMin;
    for (int i = 0; i < this->size - 1; i++){
        posMin = i;
        for(int j = i+1; j < this->size; j++){
            if(this->valores[j] < this->valores[posMin]){
                posMin = j;
            }
        }
        swap(i,posMin);
    }
}

void ListaEnteros::Insertsort(int* valores){
    for(int i = 0; i < this->size-1; i++){
        int temp = this->valores[i];
        int j = i - 1;
        while (j >= 0 && this->valores[j] > temp){
            this->valores[j+1] = this->valores[j];
            j--;
        }
        this->valores[j+1] = temp;
    }
}

void ListaEnteros::Mezcla(int ini, int fin){
    //Crea un arrreglo temporal
    //Calcular el punto medio
    //Hacer la mezcla
    //y lo regresas al arreglo original
    int l = (fin-ini)+1;
    int* a = new int[l];
    int mitad = (ini + fin)/2;
    int i = ini;
    int j = mitad + 1;
    int k = 0;
    while(i <= mitad && j <= fin){
        if(this->valores[i] < this->valores[j]){
            a[k] = this->valores[i];
            i++;
        }
        else{
            a[k] = this->valores[j];
            j++;
        }
        k++;
    }
    while(i <= mitad){
        a[k] = this->valores[i];
        i++;
        k++;
    }
    while(j <= fin){
        a[k] = this->valores[j];
        j++;
        k++;
    }
    for(int x = ini; x < fin; x++){
        this->valores[x] = a[x - ini];
    }
    delete[] a;
}

void ListaEnteros::Mergesort(int ini, int fin){
    if(ini < fin){
        int mitad = (ini + fin)/2;
        Mergesort(ini, mitad);
        Mergesort(mitad+1,fin);
        Mezcla(ini,fin);
    }
}

void ListaEnteros::MergeSort(int* valores){
    Mergesort(0, this->size-1);
}

void ListaEnteros::QuickSort(int* valores){
    QuickSortHelper(valores, 0, this->size-1);
}

void ListaEnteros::QuickSortHelper(int* valores, int low, int high){
    if(low < high){
        int ppospivot = Particion(valores, low, high);
        QuickSortHelper(valores, low, ppospivot - 1);
        QuickSortHelper(valores, ppospivot + 1, high);
    }
}

int ListaEnteros::Particion(int* valores, int low, int high){
    int pivot = valores[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++){
        if(valores[j] < pivot){
            i++;
            Swap(i,j);
        }
    }
    Swap(i+1, high);
    return i+1;
}