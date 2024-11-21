// Equipo 3
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
// Descripcion: Este programa hace uso de una hash table concatenada medainte un BST para el guardado y acomodo
// de Registros dados mediane un archivo

#include "MyHashTable.h"
#include <iostream>
#include <fstream> //para manipular los archivos 

using namespace std;

int main(){

    //Carga la bitacora a partir de un archivo.
    MyHashTable* archivo= new MyHashTable("bitacora3.txt");

    int resp;
    bool repeticion=true;

    do{ //ciclo para repetir el programa 
        //Activa la busqueda de registros por fecha y manda un aviso si ocurre un error al ingresar los datos mal
        try {
            archivo->busqueda();
        } 
        catch (const std::length_error& e) {
            cout<< "Error ocurrido al ingresar los datos, favor de hacerlo de nuevo." <<"\n";
        } 
        //Pregunta al usuario si desea buscar otro rango de fechas
        cout<<"-Quieres hacer otra busqueda (y=1/n=0)?"<<endl;
        cin>>resp;
        if(resp == 1){
            cout<<"\n";
        }
        else if(resp == 0){
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