//Equipo 5
//Ángel Gabriel Camacho Pérez - A01743075
//Ana Paula Navarro Hernández - A01644875
//Jesús Eduardo Escobar Meza - A01743270
//Descripción: Este programa lee un archivo de texto y lo ordena mediante el método de ordenamiento Merge
//Fecha: 18 de septiembre del 2024

#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

class Registro{
private:
    //Atributos que almacenan la información de un registro
    string mes;
    string mesN;
    string dia;
    string tiempo;
    string direccionIP;
    string razon;
    long int ID;

    void Estandarizar(); //Método para estandarizar el formato del registro
    int ConstruirID(); //Método para generar un ID 
    
public:
    Registro();
    Registro(string linea);
    Registro(string mes, string dia, time_t tiempo, string direccionIP, string razon);

    //Métodos de acceso (getters)
    string GetMes();
    string GetDia();
    string GetTiempo();
    string GetDireccionIP();
    string GetRazon();
    int GetID(); 
};

#endif