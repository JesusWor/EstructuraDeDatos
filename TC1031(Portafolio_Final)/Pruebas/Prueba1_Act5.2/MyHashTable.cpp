#include "MyHashTable.h"
#include "MyLinkedList.h"

#include <cmath>
#include <functional>
#include <fstream>
#include <sstream>

//O(1)
//Constructor por default
MyHashTable::MyHashTable(){
    this->size=0;
    this->sizeA=24000;
    this->tabla=new MyLinkedList[this->sizeA];
}

//O(n)
//Destrctor
MyHashTable::~MyHashTable() {
    for (int i= 0; i< sizeA; i++) {
        MyLinkedList* casilla= &tabla[i];
        while (!casilla->isEmpty()) {
            casilla->removeFirst();
        }
    }
    delete[] tabla;
}

//O(1)
//Retorna true si el hash esta vacio
bool MyHashTable::isEmpty(){
    return this->size==0;
}

//O(1)
//Inserta un valor en el Hash
void MyHashTable::put(string key, string data, int id){
    //Checa si necesita incrementar su tamaño segun la regla .75
    if(size>= double(sizeA)*3/4){
        //cout<<"s:" <<size <<" sA:"<<sizeA <<" rehashing";
        rehashing();
        cout<<"Rehashing \n";
    }
    int pos= getPos(key); // 1
    MyLinkedList* casilla = &tabla[pos];
    //cout<<pos <<"\n";
    casilla->insert(key, data, id);
    size++;
    //cout<<data<<"\n";
}

//O(n)
//Reestructura el Hash a una capacidad mayor
void MyHashTable::rehashing(){
    //Guarda valores viejos para recorrer los elementos existentes
    int sizeA_temp= sizeA;
    MyLinkedList* tabla_temp= tabla;
    //Crea una nueva tabla y sizeA con el tamaño aumentado
    this->sizeA= this->sizeA*2 +1;
    this->tabla = new MyLinkedList[this->sizeA];
    this->size=0;

    //Recorre cada elemento del Hash
    for(int i= 0; i< sizeA_temp; i++){
        MyLinkedList* casilla= &tabla_temp[i];
        while(! casilla->isEmpty()){
            //Inresa el elemento en la nueva tabla mas grande mientras lo borra de la anterior
            put(casilla->head->key, casilla->head->data, casilla->head->id); //1
            casilla->removeFirst(); //1
        }
    }
    delete[] tabla_temp;
}

//O(1)
//Obtiene un número cifrado mediante un string dado
int MyHashTable::getPos(string key){
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}

//O(n)
//Elimina el elemento referente a la llave ingresada
void MyHashTable::remove(string key){
    int pos= getPos(key); //1
    MyLinkedList* casilla = &tabla[pos];
    casilla->removeAt(key); //n
    size--;
}



//Funciones de Bitacora


//O(n)
//Constructor que recibe el nombre del archivo que contiene los registros
MyHashTable::MyHashTable(string nombreArchivo):MyHashTable(){
    leerArchivo(nombreArchivo); //n
}

//O(n)
//Abree un archivo de texto y verficica que se abra correctamente y lo lee linea por liena
void MyHashTable::leerArchivo(string nombreArchivo){
    //Abre el archivo
    ifstream archivo(nombreArchivo);
    if(! archivo.is_open()){
        cout << "Error al abrir el archivo" <<"\n";
        exit(EXIT_FAILURE);
    }

    //Manda a crear un archivo con cada renglon y se establece al incio de la lista enlazada
    string linea;
    while (getline(archivo, linea)) {
        //cout<<"in - s:" <<size <<" sA:"<<sizeA <<"\n";
        insertLine(linea);
    }
    //cout<<"Archivo leido";
    archivo.close();
}

//Divide una linea de texto en sus componentes y los guarda en los atributos de registro, ademas de que genera un ID para el registro;
//complejidad O(n)
void MyHashTable::insertLine(string linea) {
    istringstream stream(linea);
    string mes, dia, tiempo, direccionIP, razon, IP, puerto;
    int horaN, minutoN, segundoN;

    //Guardar elementos separados por espacios:
    stream >> mes >> dia >> tiempo >> direccionIP;
    //Capturar el resto del string en razon
    getline(stream >> ws, razon);

    //Dividir direccionIP en IP y puerto
    size_t pos = direccionIP.find(':');
    if (pos != string::npos) {
        IP = direccionIP.substr(0, pos);
        puerto = direccionIP.substr(pos + 1);
    }

    //Dividir tiempo en horas, minutos y segundos 
    size_t pos_hora = tiempo.find(':'); 
    size_t pos_minuto = tiempo.find(':', pos_hora + 1); 
    if (pos_hora != std::string::npos && pos_minuto != std::string::npos){ 
        horaN= stoi(tiempo.substr(0, pos_hora)); 
        minutoN= stoi(tiempo.substr(pos_hora + 1, pos_minuto - pos_hora - 1)); 
        segundoN= stoi(tiempo.substr(pos_minuto + 1)); 
    }

    //Obtiene un valor numerico de fecha y tiempo para ordenarse
    int id= obtenerFechaID(mes, stoi(dia), horaN, minutoN, segundoN);

    //Inserta el nodo
    //cout<<"s:" <<size <<" sA:"<<sizeA <<"\n";
    //cout<<IP+" "+ mes+" "+dia+" "+tiempo +" - " <<id <<"\n";
    put(IP, mes+" "+dia+" "+tiempo, id);
}

//O(1)
//Obtiene el id que es el numero de segundos pasados tras esa fecha
int MyHashTable::obtenerFechaID(string mes, int diaN, int horaN, int minutoN, int segundoN){
    int mesN;
    //Obtiene los dias del inicio del año al fin del mes
    if(mes== "Jan"){
        mesN= 0;
    } else if(mes=="Feb"){
        mesN= 31;
    } else if(mes=="Mar"){
        mesN= 60;
    } else if(mes=="Apr"){
        mesN= 91;
    } else if(mes=="May"){
        mesN= 121;
    } else if(mes=="Jun"){
        mesN= 152;
    } else if(mes=="Jul"){
        mesN= 182;
    } else if(mes=="Aug"){
        mesN= 213;
    } else if(mes=="Sep"){
        mesN= 244;
    } else if(mes=="Oct"){
        mesN= 274;
    } else if(mes=="Nov"){
        mesN= 305;
    } else if(mes=="Dec"){
        mesN= 335;
    }
    return (mesN+diaN)*86400 + horaN*3600 + minutoN*60 + segundoN;
}


//O(n)
//Obtiene el valor respectivo de la llave ingresada
void MyHashTable::showList(string key) {
    int pos= getPos(key); //1
    MyLinkedList* casilla= &tabla[pos];
    casilla->showForKey(key); //n
}

void MyHashTable::busqueda(){
    string IP_buscada;
    cout<<"IP a buscar:"<<"\n";
    cin>>IP_buscada;
    cout<<"\n";

    showList(IP_buscada);
}

