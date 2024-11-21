// Equipo 3
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
/* Descripcion: Este programa lee un archivo que contiene registros, los cuales se ordenan de menor a mayor por medio de la IP y el puerto, las IP se almacenan en un BST tomando en cuenta su frecuencia de intento de acceso. Se genera un nuevo archivo .txt con los registros ordenados y además imprime las IP que mas frecuencia de acceso tuvieron. */
// Fecha: 04 de noviembre del 2024

#include "Registro.h"
// <iostream> <iomanip> Ya estan en el .h
#include <sstream>

using namespace std;

Registro::Registro() : Registro("","","","","", nullptr){
}

//Este constructor inicializa un registro a partir de una li­nea de tento y punto al siguiente registro
//complejidad O(1)
Registro::Registro(string linea, Registro* next) {
    insertLine(linea);
    this->next= next;
}

//Este constructor inicliza un registro con cada parte por separado y un puntero al siguiente registro.
//complejidad O(1)
Registro::Registro(string mes, string dia, string tiempo, string direccionIP, string razon, Registro* next){
    //Crear un registro con cada parte por separado
    this->mes= mes;
    this->dia= dia;
    this->tiempo= tiempo;
    this->direccionIP= direccionIP;
    this->razon= razon;
    this->next= next;
    
}

//Construye un ID unico para cada registro a partir de la direccion IP, la cual consta de 4 partes, estas se dividen
// y se ajustan para que cada parte tenga 3 digitos y despues se concatenan. Complejidad O(1) a O(12) segun los 0s a rellenar
long long int Registro::construirID(){

    //Separamos la IP y el puerto 
    string IP, puerto;
    int pos, pos1, pos2, pos3;
    string part1, part2, part3, part4;
    pos=direccionIP.find(':');

    //Obtenemos la Ip y el puerto
    IP=direccionIP.substr(0, pos);
    puerto=direccionIP.substr(pos+1);

    //Separamos la IP en 4 partes
    pos1=IP.find('.');
    part1=IP.substr(0, pos1);

    pos2=IP.find('.', pos1+1);
    part2 = IP.substr(pos1+1, pos2-pos1-1);

    pos3=IP.find('.', pos2+1);
    part3=IP.substr(pos2+1, pos3-pos2-1);
    
    part4=IP.substr(pos3+1);


    //ya que la separamos, verificamos que todas las partes tengan 3 di­gitos, y si no, las rellenamos con 0
    while(part1.length()<3){
        part1="0"+part1;
    }

    while(part2.length()<3){
        part2="0"+part2;
    }

    while(part3.length()<3){
        part3="0"+part3;
    }

    while(part4.length()<3){
        part4="0"+part4;
    }

    //el puerto debe tener 4 digitos, sino, se rellena con 0 a la izquierda hasta tenerlos
    while(puerto.length()<4){
        puerto="0"+puerto;
    }

    //ya que nos aseguramos de que las partes tengan 3 di­gitos, las unimos en una sola cadena fara volver a formar la IP completa
    long long int completeIP = stoll(part1+part2+part3+part4+puerto); 
    return completeIP;
}

//Devuelve el valor de atributo correspondiente
//complejidad O(1)
string Registro::getMes(){
    return mes;
}

//Devuelve el valor de atributo correspondiente
//complejidad O(1)
string Registro::getDia(){
    return dia;
}

//Devuelve el valor de atributo correspondiente
//complejidad O(1)
string Registro::getTiempo(){
    return tiempo;
}

//Devuelve el valor de atributo correspondiente
//complejidad O(1)
string Registro::getDireccionIP(){
    return direccionIP;
}

//Guardamos el valor de la IP y la ceparamos del puerto
//complejidad O(1)
string Registro::getIP(){

    //Separamos la IP y el puerto 
    string IP;
    int pos;
    pos=direccionIP.find(':');

    //Obtenemos la Ip
    IP=direccionIP.substr(0, pos);

    return IP;
}

//Guardamos el valor del puerto y la ceparamos de la IP  
string Registro::getPuerto(){
    
    //Separamos la IP y el puerto 
    string puerto;
    int pos;
    pos=direccionIP.find(':');

    //Obtenemos la Ip y el puerto
    puerto=direccionIP.substr(pos+1);

    return puerto;
}

//Devuelve el valor de atributo correspondiente
//complejidad O(1)
string Registro::getRazon(){
    return razon;
}

//Devuelve el valor de atributo correspondiente
//complejidad O(1)
long long int Registro::getID(){
    //cout<<IP_ID <<"\n";
    return ip_ID;
}

//Devuelve una cadena con todos los atributos de registro
//complejidad O(1)
string Registro::getRegistroStr(){
    return mes +" "+ dia +" "+ tiempo +" "+ direccionIP +" "+ razon;
}

//Divide una linea de texto en sus componentes y los guarda en los atributos de registro, ademas de que genera un ID para el registro;
//complejidad O(1)
void Registro::insertLine(string linea){
    istringstream stream(linea);
    //Guardar elementos separados por espacios:
    stream >> this->mes;
    stream >> this->dia;
    stream >> this->tiempo;
    stream >> this->direccionIP;
    getline(stream >> std::ws, this->razon); //Guardar el resto del string en razon

    this->ip_ID= construirID();
}