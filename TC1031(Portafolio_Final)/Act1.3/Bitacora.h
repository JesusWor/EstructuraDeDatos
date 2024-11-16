//Equipo 5
//Ángel Gabriel Camacho Pérez - A01743075
//Ana Paula Navarro Hernández - A01644875
//Jesús Eduardo Escobar Meza - A01743270
//Descripción: Este programa lee un archivo de texto y lo ordena mediante el método de ordenamiento Merge
//Fecha: 18 de septiembre del 2024

#ifndef BITACORA_H
#define BITACORA_H

#include "Registro.h"

#include <iostream>
#include <vector>
#include <iomanip> 
#include <string> 
using namespace std;

class  Bitacora{
private:
    vector<Registro> registros; //Almacena los registros de la bitácora
    bool ordenado;  //Indica si los registros están ordenados
    
    //void OrdenaMerge(int ini, int fin); //Ordena los registros utilizando Merge Sort
    //void Mezcla(int ini, int cen, int fin); 

    void OrdenaQuick(int low, int high);//Quick
    int Particion(int low, int high);//Quick

    int BusquedaBinaria(int iniID); //Realiza una búsqueda binaria para encontrar un registro por ID
    
public:
    Bitacora(string arc); //Constructor para cargar registros desde un archivo
    Bitacora(vector<Registro> reg); //Constructor que recibe un vector de registros

    int GetSize(); //Retorna la cantidad de registros en la bitácora
    void OrdenarBitacora(); //Ordena los registros de la bitácora
    void ExportarBitacora(string nombre, int j); //Exporta los registros a un archivo de texto
    vector <Registro> BuscarRegistro(); //Busca registros en un rango de fechas dadas por el usuario 
};

#endif