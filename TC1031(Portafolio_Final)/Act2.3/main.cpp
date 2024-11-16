// Equipo 5
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
// Descripcion: Este programa maneja una lista enlazada de registros y lee un archivo que contienen registros los cuales se ordenan de menor a mayor usando la IP de los regstros y genera un nuevo archivo con los regisrtros ordenados
// ademas de que permite hacer la busqueda de los registros que se quieren ingresar pidiendo al usuario un rango que tiene un inicio y un fin dichos registros son almacenados en un nuevo archivo .txt
// Fecha: 12 de octubre del 2024

#include "Bitacora.h"
#include <iostream>
#include <fstream> //para manipular los archivos 
#include <stdexcept> //para manejar excepciones

using namespace std;

int main(){

    //Carga la bitacora a partir de un archivo.
    Bitacora* archivo= new Bitacora("bitacora.txt");

    //Ordena la Bitacora
    archivo->ordenarBitacora();

    //Exporta la bitacora completa
    archivo->exportarBitacoraCompleta("bitacoraOrdenadaIP-Eq5.txt");

    bool repeticion=true;
    string resp;
    int N=1;

    do{ //ciclo para repetir el programa 
        //Activa la busqueda de registros por fecha y manda un aviso si ocurre un error al ingresar los datos mal
        try {
            archivo->buscarRegistro(N);
            N++;
        } 
        catch (const std::length_error& e) {
            cout<< "Error ocurrido al ingresar los datos, favor de hacerlo de nuevo." <<"\n";
        } 
        //Pregunta al usuario si desea buscar otro rango de fechas
        cout<<"-Quieres hacer otra busqueda (y/n)?"<<endl;
        getline(cin, resp);
        if(resp == "y"){
            cout<<"\n";
        }
        else if(resp == "n"){
            cout<<"Gracias por usar el programa"<<endl;
            repeticion=false; //Termina el bucle
        }
        else{
            cout<<"Respuesta invalida"<<endl<<endl;
            repeticion=false; //Termina el bucle
        }   
    } while(repeticion);

    // Borrar las bitacoras dinamicas
    delete archivo;
    cout<<"Eliminacion de Bitacora exitosa.";
    
    return 0; 
}