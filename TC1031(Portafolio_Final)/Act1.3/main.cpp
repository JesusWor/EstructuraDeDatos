//Equipo 5
//Ángel Gabriel Camacho Pérez - A01743075
//Ana Paula Navarro Hernández - A01644875
//Jesús Eduardo Escobar Meza - A01743270
//Descripción: Este programa lee un archivo de texto y lo ordena mediante el método de ordenamiento Merge
//Fecha: 18 de septiembre del 2024

#include "Bitacora.h"
#include <iostream>
#include <fstream> //para manipular los archivos 
#include <vector> 
#include <stdexcept> //para manejar excepciones

using namespace std;

int main(){
    //vector<Registro> registros;
    string resp; 
    bool repeticion= true;
    int N=1; //Contador para exportar registros
    int i,
        j;
    string nombreBitacora = "BitacoraOrdenada.txt";

    //Sirve para carga la bitácora a partir de un archivo.
    Bitacora archivo("bitacora-1.txt");
    archivo.OrdenarBitacora();
    j = archivo.GetSize();
    archivo.ExportarBitacora(nombreBitacora, j);
    Bitacora busqueda(archivo.BuscarRegistro());
    
    while(repeticion){ //ciclo para repetir el programa 
        //Activa la búsqueda de registros por fecha y manda un aviso si ocurre un error al ingresar los datos mal
        try {
            if(busqueda.GetSize()==0){ 
                cout<<"No hay registros en ese rango de tiempo";
            }
            i = busqueda.GetSize(); //Obtiene la cantidad de registros encontrados
            string nombre = "salida"+to_string(N)+"-eq5.txt"; //Nombre y numero que va a llevar la exportacion de los registros buscados
            busqueda.ExportarBitacora(nombre, i); //Exporta los registros encontrados a un archivo txt
            N++;
        } 
        catch (const std::length_error& e) {
            cout<< "Error ocurrido al ingresar los datos, favor de hacerlo de nuevo." <<"\n";
        } 
        while(true){
            //Pregunta al usuario si desea buscar otro rango de fechas
            cout<<endl<<"¿Quieres hacer otra busqueda (y/n)?"<<endl;
            getline(cin, resp);
            if(resp == "y"){
                break; //Regresa al inicio del bucle principal
            }
            else if(resp == "n"){
                cout<<"Gracias por usar el programa"<<endl;
                repeticion=false; //Termina el bucle principal
                break;
            }
            else{
                cout<<"Respuesta invalida"<<endl;
            }   
        }  
    }
    return 0; 
}