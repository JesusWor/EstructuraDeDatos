// Equipo 3
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
/* Descripcion: Este programa lee un archivo que contiene registros, los cuales se ordenan de menor a mayor por medio de la IP y el puerto, las IP se almacenan en un BST tomando en cuenta su frecuencia de intento de acceso. Se genera un nuevo archivo .txt con los registros ordenados y además imprime las IP que mas frecuencia de acceso tuvieron. */
// Fecha: 04 de noviembre del 2024

#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
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

    string getIP(); //Metodo para separar la IP
    string getPuerto(); //Metodo para separar el puerto 
};

#endif