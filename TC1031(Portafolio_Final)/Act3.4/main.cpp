// Equipo 3
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
/* Descripcion: Este programa lee un archivo que contiene registros, los cuales se ordenan de menor a mayor por medio de la IP y el puerto, las IP se almacenan en un BST tomando en cuenta su frecuencia de intento de acceso. Se genera un nuevo archivo .txt con los registros ordenados y además imprime las IP que mas frecuencia de acceso tuvieron. */
// Fecha: 04 de noviembre del 2024

#include "Bitacora.h"
#include <iostream>
#include <fstream> //para manipular los archivos 
#include <stdexcept> //para manejar excepciones

using namespace std;

int main(){

    //Carga la bitacora a partir de un archivo.
    Bitacora* archivo= new Bitacora("bitacora2.txt");

    //Ordena la Bitacora
    archivo->ordenarBitacora();

    //Exporta la bitacora completa
    archivo->exportarBitacoraCompleta("bitacoraOrdenadaIP-Eq3-BST.txt");

    //Numero de IPs mayores a mostrar
    int N=15;
    archivo->encontrarFrecuenciaIPs();
    archivo->showIP(N);

    // Borrar las bitacoras dinamicas
    delete archivo;
    
    return 0; 
}