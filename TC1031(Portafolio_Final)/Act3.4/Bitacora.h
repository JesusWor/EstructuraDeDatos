// Equipo 3
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
/* Descripcion: Este programa lee un archivo que contiene registros, los cuales se ordenan de menor a mayor por medio de la IP y el puerto, las IP se almacenan en un BST tomando en cuenta su frecuencia de intento de acceso. Se genera un nuevo archivo .txt con los registros ordenados y además imprime las IP que mas frecuencia de acceso tuvieron. */
// Fecha: 04 de noviembre del 2024

#ifndef BITACORA_H
#define BITACORA_H

#include "Registro.h"

#include <iostream>
#include <vector>
#include <iomanip>  
using namespace std;



struct NodoIP{
private:
    
public:
    string IP;
    int frecuencia;
    NodoIP *left, // Puntero al hijo izquierdo
            *right; // Puntero al hijo derecho

    //constructores 
    NodoIP():NodoIP("0.0.0.0", 0, nullptr, nullptr){}
    NodoIP(string IP, int frecuencia):NodoIP(IP, frecuencia, nullptr, nullptr){}
    NodoIP(string IP, int frecuencia, NodoIP* left, NodoIP* right){ 
        this->IP= IP;
        this->frecuencia= frecuencia;
        this->left= left;
        this->right= right;
    }
};

class  Bitacora{
private:
    int sizeReg,
        sizeIP=0;
    Registro *head,
            *tail;
    NodoIP *root;

    Registro* busqSecuencial(long long int ini_ID); //metodo de busqueda secuencial
    Registro* ordenaMerge(Registro* iniNodo, Registro* finNodo); //metodo de ordenamiento por merge
    Registro* mezcla(Registro* iniNodo, Registro* cenNodo); 
    void exportarBitacora(Registro* posIni, Registro* posFin, string nombreArchivoExp); //Escribe los registrso contenidos en el rango dado en un archivo con el nombre dado
    void leerArchivo(string archivo); //Obtiene los registros contenidos en un archivo

    //Nuevas funciones para IP
    void insertBST(NodoIP* nodo);
    int showIP(NodoIP* nodo, int n);
    void deleteIP(NodoIP *nodo);
    
public:
    Bitacora(); //Constructor
    Bitacora(Registro* registro); //Constructor por defaut
    Bitacora(string nombreArchivo); //Constructor que recibe nombre del archivo con registros
    ~Bitacora(); //Destructor

    int getSizeRegistros(); //Retorna la cantidad de registros en la bitacora
    void ordenarBitacora(); //Ordena los registros de la bitacora

    bool isEmpty();
    void removeLast(); //Exc invalid_argument
    void insertFirst(string data); //Exc invalid_argument
    //void buscarRegistro(int N); //Funcion para buscar registros en cierto rango. Manda el numero de busqueda

    void exportarBitacoraCompleta(string nombreArchivoExp);    

    //Nuevas funciones para la IP
    void encontrarFrecuenciaIPs();
    void showIP(int n); //Imprime las IPs con mayor frecuencia de acceso
};


#endif