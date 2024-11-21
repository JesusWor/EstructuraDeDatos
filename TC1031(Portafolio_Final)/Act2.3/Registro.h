// Equipo 5
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
// Descripcion: Este programa maneja una lista enlazada de registros y lee un archivo que contienen registros los cuales se ordenan de menor a mayor usando la IP de los regstros y genera un nuevo archivo con los regisrtros ordenados
// ademas de que permite hacer la busqueda de los registros que se quieren ingresar pidiendo al usuario un rango que tiene un inicio y un fin dichos registros son almacenados en un nuevo archivo .txt
// Fecha: 12 de octubre del 2024

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
    string dia;
    string tiempo;
    string direccionIP;
    string razon;
    long long int ip_ID;

    long long int construirID(); //Metodo para generar un ID 
    
public:
    Registro *next;

    Registro();
    Registro(string linea, Registro* next);
    Registro(string mes, string dia, string tiempo, string direccionIP, string razon, Registro* next);

    //Metodos de acceso (getters)
    void insertLine(string linea);
    string getMes();
    string getDia();
    string getTiempo();
    string getDireccionIP();
    string getRazon();
    string getRegistroStr();
    long long int getID(); 
};

#endif