// Equipo 3
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
// Descripcion: Este programa hace uso de una hash table concatenada medainte un BST para el guardado y acomodo
// de Registros dados mediane un archivo

#include "MyHashTable.h"

#include <cmath>
#include <functional>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

//O(1)
//Constructor por defecto
MyHashTable::MyHashTable() {
    this->size = 0;
    this->sizeA = 24000; //largo ideal de la hash para evitar rehashing (24000)
    this->tabla = new MyBST[this->sizeA];
}

//O(1)
//Destructor
MyHashTable::~MyHashTable() {
    delete[] tabla;
}

//O(1)
//Retorna true si el hash está vacío
bool MyHashTable::isEmpty() {
    return this->size == 0;
}

//O(log n)
//Inserta un valor en el hash table
void MyHashTable::put(string key, string data, int id) {
    //Checa si necesita incrementar su tamaño según la regla .75
    if (size >= double(sizeA) * 3/4) {
        //cout << "Rehashing \n";
        rehashing();
        //cout << "Rehashing ends \n";
    }
    int pos= getPos(key); 
    MyBST* casilla = &tabla[pos];
    casilla->insert(key, data, id); //log n
    size++;
}

//O(n)
//Reestructura el Hash a una capacidad mayor
void MyHashTable::rehashing(){
    //Guarda valores viejos para recorrer los elementos existentes
    int sizeA_temp= sizeA;
    MyBST* tabla_temp= tabla;
    //Crea una nueva tabla y sizeA con el tamaño aumentado
    this->sizeA= this->sizeA*2 +1;
    this->tabla = new MyBST[this->sizeA];
    this->size=0;

    //Recorre cada elemento del Hash
    for(int i= 0; i< sizeA_temp; i++){
        MyBST* casilla= &tabla_temp[i];
        while(! casilla->getSize() == 0){
            //Inresa el elemento en la nueva tabla mas grande mientras lo borra de la anterior>getRaizData() <<"-" <<casilla->getRaiztId() <<"\n";
            put(casilla->getRaizKey(), casilla->getRaizData(), casilla->getRaiztId()); //1
            casilla->eliminarRaiz(); //1
        }
    }
    delete[] tabla_temp;
}

//O(1)
//Obtiene un número cifrado mediante un string dado
int MyHashTable::getPos(string key) {
    size_t hashC= hash<string>{}(key);
    int hashCode= static_cast<int>(hashC);
    return abs(hashCode) % this->sizeA;
}

//O(1)
//Elimina el elemento referente a la llave ingresada
void MyHashTable::remove(string key) {
    int pos= getPos(key);  //1
    MyBST* casilla= &tabla[pos];
    //No hay implementación de eliminar en MyBST, así que esta función queda incompleta.
}

//Funciones de Bitácora

//O(n log n)
//Constructor que recibe el nombre del archivo que contiene los registros
MyHashTable::MyHashTable(string nombreArchivo) : MyHashTable() {
    leerArchivo(nombreArchivo); //n log n
}

//O(n log n)
//Abre un archivo de texto y lo lee línea por línea
void MyHashTable::leerArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo" << "\n";
        exit(EXIT_FAILURE);
    }

    string linea;
    while (getline(archivo, linea)) {
        insertLine(linea); //log n
    }
    archivo.close();
}

//O(log n)
//Divide una línea de texto en sus componentes y los inserta en el hash table
void MyHashTable::insertLine(string linea) {
    istringstream stream(linea);
    string mes, dia, tiempo, direccionIP, razon, IP, puerto;
    int horaN, minutoN, segundoN;

    //Guardar elementos separados por espacios
    stream >> mes >> dia >> tiempo >> direccionIP;
    getline(stream >> ws, razon);

    //Dividir dirección IP en IP y puerto
    size_t pos = direccionIP.find(':');
    if (pos != string::npos) {
        IP= direccionIP.substr(0, pos);
        puerto= direccionIP.substr(pos + 1);
    }

    //Dividir tiempo en horas, minutos y segundos
    size_t pos_hora= tiempo.find(':');
    size_t pos_minuto= tiempo.find(':', pos_hora + 1);
    if (pos_hora != string::npos && pos_minuto != string::npos) {
        horaN= stoi(tiempo.substr(0, pos_hora));
        minutoN= stoi(tiempo.substr(pos_hora + 1, pos_minuto - pos_hora - 1));
        segundoN= stoi(tiempo.substr(pos_minuto + 1));
    }

    int id= obtenerFechaID(mes, stoi(dia), horaN, minutoN, segundoN); //1
    put(IP, mes + " " + dia + " " + tiempo, id); //log n
}

//O(1)
//Obtiene el id que es el número de segundos pasados tras esa fecha
int MyHashTable::obtenerFechaID(string mes, int diaN, int horaN, int minutoN, int segundoN) {
    int mesN;
    if (mes == "Jan") { mesN = 0; 
    } else if (mes == "Feb") { 
        mesN= 31;
    } else if (mes == "Mar") { 
        mesN= 60; 
    } else if (mes == "Apr") { 
        mesN= 91; 
    } else if (mes == "May") { 
        mesN= 121; 
    } else if (mes == "Jun") { 
        mesN= 152; 
    } else if (mes == "Jul") { 
        mesN= 182; 
    } else if (mes == "Aug") { 
        mesN= 213; 
    } else if (mes == "Sep") { 
        mesN= 244; 
    } else if (mes == "Oct") { 
        mesN= 274; 
    } else if (mes == "Nov") { 
        mesN= 305; 
    } else if (mes == "Dec") { 
        mesN= 335; 
    }
    return (mesN+diaN)*86400 + horaN*3600 + minutoN*60 + segundoN;
}

//O(n)
//Obtiene el valor respectivo de la llave ingresada
void MyHashTable::showList(string key) {
    int pos= getPos(key); //1
    MyBST* casilla= &tabla[pos];
    cout<<key<<endl;
    casilla->mostrar(); //n
}

//O(n)
//Realiza una búsqueda en el hash table por una IP específica
void MyHashTable::busqueda() {
    string IP_buscada;
    cout << "IP a buscar:" << "\n";
    cin >> IP_buscada;
    cout << "\n";
    showList(IP_buscada); //n
}

