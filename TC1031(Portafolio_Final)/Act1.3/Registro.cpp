//Equipo 5
//Ángel Gabriel Camacho Pérez - A01743075
//Ana Paula Navarro Hernández - A01644875
//Jesús Eduardo Escobar Meza - A01743270
//Descripción: Este programa lee un archivo de texto y lo ordena mediante el método de ordenamiento Merge
//Fecha: 18 de septiembre del 2024

#include "Registro.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <ctime> //Funciones para trabajar con fechas y horas.

using namespace std;

Registro::Registro(){
    //Crea un registro "nulo"
    this->mes= "000";
    this->dia= "00";
    this->tiempo= "00:00:00";
    this->direccionIP= "000.000";
    this->razon= "----NULO----";
    this->ID= 0;
}

Registro::Registro(string linea) {
    istringstream stream(linea);
    //Guardar elementos separdaos por espacios:
    stream >> this->mes;
    stream >> this->dia;
    stream >> this->tiempo;
    stream >> this->direccionIP;
    getline(stream >> std::ws, this->razon); //Guardar el resto del string

    Estandarizar(); //Normalizamos el formato del registro
    this->ID= ConstruirID(); //Generamos un ID único
}

Registro::Registro(string mes, string dia, time_t tiempo, string direccionIP, string razon){
    //Crear un registro con cada parte por separado
    this->mes= mes;
    this->dia= dia;
    this->tiempo= tiempo;
    this->direccionIP= direccionIP;
    this->razon= razon;
    this->ID= ConstruirID();
}

void Registro::Estandarizar(){
    //Asigna el numero del mes y se estandariza cómo se guarda
    if(mes=="Jan" || mes=="jan" || mes=="JAN" || mes=="1"){
        mes= "Jan";
        mesN= "01";
    } else if(mes=="Feb" || mes=="feb" || mes=="FEB" || mes=="2"){
        mes= "Jan";
        mesN= "02";
    } else if(mes=="Mar" || mes=="mar" || mes=="MAR" || mes=="3"){
        mes= "Mar";
        mesN= "03";
    } else if(mes=="Apr" || mes=="apr" || mes=="APR" || mes=="4"){
        mes= "Apr";
        mesN= "04";
    } else if(mes=="May" || mes=="may" || mes=="MAY" || mes=="5"){
        mes= "May";
        mesN= "05";
    } else if(mes=="Jun" || mes=="jun" || mes=="JUN" || mes=="6"){
        mes= "Jun";
        mesN= "06";
    } else if(mes=="Jul" || mes=="jul" || mes=="JUL" || mes=="7"){
        mes= "Jul";
        mesN= "07";
    } else if(mes=="Aug" || mes=="aug" || mes=="AUG" || mes=="8"){
        mes= "Aug";
        mesN= "08";
    } else if(mes=="Sep" || mes=="sep" || mes=="SEP" || mes=="9"){
        mes= "Sep";
        mesN= "09";
    } else if(mes=="Oct" || mes=="oct" || mes=="OCT" || mes=="10"){
        mes= "Oct";
        mesN="10";
    } else if(mes=="Nov" || mes=="nov" || mes=="NOV" || mes=="11"){
        mes= "Nov";
        mesN="11";
    } else if(mes=="Dec" || mes=="dic" || mes=="DIC" || mes=="12"){
        mes= "Dec";
        mesN="12";
    }

    //Guarda el día en dos dígitos:
    if (dia=="1" || dia=="2" || dia=="3" || dia=="4" || dia=="5" || dia=="6" || dia=="7" || dia=="8" || dia=="9"){
        this-> dia= "0"+dia; //Agrega un cero al inicio si es necesario
    }
}

int Registro::ConstruirID(){
    string tt;
    vector<string> vecTiempo;
    istringstream stream(tiempo);
    //Divide el tiempo en hh, mm y ss para poder hacer el ID
     while (getline(stream, tt, ':')) {
        vecTiempo.push_back(tt);
    }
    //Suma los string de los datos para después pasarlo a int y crear un ID
    return stoi(mesN+ dia+ vecTiempo[0]+ vecTiempo[1]+ vecTiempo[2]);

}

string Registro::GetMes(){
    return mes;
}

string Registro::GetDia(){
    return dia;
}

string Registro::GetTiempo(){
    return tiempo;
}

string Registro::GetDireccionIP(){
    return direccionIP;
}

string Registro::GetRazon(){
    return razon;
}

int Registro::GetID(){
    return ID;
}