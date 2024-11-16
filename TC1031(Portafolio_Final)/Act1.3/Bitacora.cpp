//Equipo 5
//Ángel Gabriel Camacho Pérez - A01743075
//Ana Paula Navarro Hernández - A01644875
//Jesús Eduardo Escobar Meza - A01743270
//Descripción: Este programa lee un archivo de texto y lo ordena mediante el método de ordenamiento Merge
//Fecha: 18 de septiembre del 2024
//Referencias: Para ExportarBitacora utilizamos de referencia el siguiente video de youtube: https://www.youtube.com/watch?v=LTSF2wnfNH0&list=PLCTD_CpMeEKTofxs7iottRxJ5YPM7BOcc&index=139
//Novato, P. [@programadornovato]. (s/f). 133.- C++ desde cero 2019🦸‍♂️ [Crear Archivos en c++]. Youtube. Recuperado el 18 de septiembre de 2024, de https://www.youtube.com/watch?v=LTSF2wnfNH0&list=PLCTD_CpMeEKTofxs7iottRxJ5YPM7BOcc&index=139

#include "Bitacora.h"
#include "Registro.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <string>

Bitacora::Bitacora(string arc){
    //Abre el archivo txt y verifica si se abre correctamente
    ifstream archivo(arc);
    if(! archivo.is_open()){
        cout << "Error al abrir el archivo" <<"\n";
        exit(EXIT_FAILURE);
    }
    //Divide el archivo por renglones y manda cada renglon a hacer un registro
    string linea;
    while (getline(archivo, linea)) {
        registros.push_back(Registro (linea));
    }
    archivo.close();
    ordenado=true; //Indica que los registros están listos para ser usados
}

Bitacora::Bitacora(vector<Registro> reg){
    //Inicializa la bitácora con un vector de registros
    registros= reg;
}

int Bitacora::GetSize(){
    //Retorna la cantidad de registros en la bitácora
    return registros.size();
}

void Bitacora::OrdenarBitacora(){
    //Se inicia el proceso de ordenamiento usando Merge Sort
    OrdenaQuick(0, registros.size()-1);
}

/*void Bitacora::OrdenaMerge(int ini, int fin){
    //Para ordenar los registros 
    int cen=ini+(fin-ini)/2;
    if(ini<fin){                             
        OrdenaMerge(ini, cen);
        OrdenaMerge(cen+1, fin);    
        Mezcla(ini, cen, fin);       
    }
}

void Bitacora::Mezcla(int ini, int cen, int fin){   
    //Mezcla dos mitades ordenadas 
    vector<Registro> vari(fin-ini+1);
    int i= ini;
    int j= cen+1;
    int k= 0;
    while(i <= cen && j <= fin){    //n
        if(registros[i].GetID()> registros[j].GetID()){
            vari[k]= registros[j];
            j++;
        } else {
            vari[k]= registros[i];
            i++;
        }
        k++;
    }
    while(i<= cen){
        vari[k]= registros[i];
        i++;
        k++;
    }
    while (j<= fin){
        vari[k]= registros[j];
        j++;
        k++;
    }
    //Actualiza el vector original con los registros ordenados
    for(int c=0; c<vari.size(); c++){
        registros[ini+c]= vari[c];
    }
}*/

void Bitacora::OrdenaQuick(int low, int high){
    //Ordena los registros utilizando Quick Sort
    if(low<high){
        int pi= Particion(low, high);
        OrdenaQuick(low, pi-1);
        OrdenaQuick(pi+1, high);
    }
}

int Bitacora::Particion(int low, int high){
    //Particiona los registros para el Quick Sort
    int pivot= registros[high].GetID();
    int i= low-1;
    for(int j= low; j<high; j++){
        if(registros[j].GetID()<pivot){
            i++;
            swap(registros[i], registros[j]);
        }
    }
    swap(registros[i+1], registros[high]);
    return i+1;
}

vector<Registro> Bitacora::BuscarRegistro(){
    //Pide los datos de su busqueda al usuario
    string datosIni, datosFin;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Dame la fecha y hora del inicio (MMM DD hh:mm:ss): ";
    getline(cin, datosIni);
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Dame la fecha y hora del final (MMM DD hh:mm:ss): ";
    getline(cin, datosFin);
    cout<<"---------------------------------------------------"<<endl;

    //Se crean registros (para aprovechar código) con los datos de fecha y horario ingresados y se suma texto basio para asignar a direcciónIP y comentario
    Registro registroIni(datosIni+ " aa bb");
    Registro registroFin(datosFin+ " aa bb");

    //Localiza en que posición está el registro de inicio de la búsqueda
    int posIni= BusquedaBinaria(registroIni.GetID());

    //guada los registros entre el rango de fechas en un nuevo vector
    vector <Registro> registrosBus;
    while (registros[posIni].GetID() <= registroFin.GetID()){
        registrosBus.push_back(registros[posIni]);
        posIni++;
    }
    return registrosBus; //Retorna los registros encontrados
}

int Bitacora::BusquedaBinaria(int iniID){
    //Implementamos búsqueda binaria para encontrar un registro por ID
    int min=0, max=registros.size()-1, avg;
    while(min <= max){             
        avg= (min+max)/2;
        if(registros[avg].GetID()==iniID){    
            return avg;
        } else if(iniID>registros[avg].GetID()){
            min=avg+1;
        } else {
            max=avg-1;
        }
    }
    return min;
}

void Bitacora::ExportarBitacora(string nombre, int j){
    //Exporta los registros a un archivo de texto
    fstream file;
    file.open(nombre,ios::out);
    if(file.is_open()){
        for(int i=0; i<j; i++){
            file<<registros[i].GetMes() <<" " <<registros[i].GetDia() <<" " <<registros[i].GetTiempo() <<" " <<registros[i].GetDireccionIP() <<" " <<registros[i].GetRazon() <<"\n";
        }
        file.close();
        cout<<"Archivos guardados exitosamente";
    } else {
        cout<<"Error al abrir el archivo" <<"\n";   
    }
}