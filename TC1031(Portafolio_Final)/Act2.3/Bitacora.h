// Equipo 5
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
// Descripcion: Este programa maneja una lista enlazada de registros y lee un archivo que contienen registros los cuales se ordenan de menor a mayor usando la IP de los regstros y genera un nuevo archivo con los regisrtros ordenados
// ademas de que permite hacer la busqueda de los registros que se quieren ingresar pidiendo al usuario un rango que tiene un inicio y un fin dichos registros son almacenados en un nuevo archivo .txt
// Fecha: 12 de octubre del 2024

#ifndef BITACORA_H
#define BITACORA_H

#include "Registro.h"

#include <iostream>
#include <vector>
#include <iomanip>  
using namespace std;

class  Bitacora{
private:
    int size;
    Registro *head,
            *tail;

    Registro* busqSecuencial(long long int ini_ID);
    Registro* ordenaMerge(Registro* iniNodo, Registro* finNodo);
    Registro* mezcla(Registro* iniNodo, Registro* cenNodo); 
    void exportarBitacora(Registro* posIni, Registro* posFin, string nombreArchivoExp); //Escribe los registrso contenidos en el rango dado en un archivo con el nombre dado
    void leerArchivo(string archivo); //Obtiene los registros contenidos en un archivo
    
public:
    
    Bitacora(); //Constructor
    Bitacora(Registro* registro); //Constructor por defaut
    Bitacora(string nombreArchivo); //Constructor que recibe nombre del archivo con registros
    ~Bitacora(); //Destructor

    int getSize(); //Retorna la cantidad de registros en la bitacora
    void ordenarBitacora(); //Ordena los registros de la bitacora

    bool isEmpty();
    void removeLast(); //Exc invalid_argument
    void insertFirst(string data); //Exc invalid_argument
    void buscarRegistro(int N); //Funcion para buscar registros en cierto rango. Manda el numero de busqueda

    void exportarBitacoraCompleta(string nombreArchivoExp);    
};

#endif