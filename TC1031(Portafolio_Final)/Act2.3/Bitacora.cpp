// Equipo 5
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
// Descripcion: Este programa maneja una lista enlazada de registros y lee un archivo que contienen registros los cuales se ordenan de menor a mayor usando la IP de los regstros y genera un nuevo archivo con los regisrtros ordenados
// ademas de que permite hacer la busqueda de los registros que se quieren ingresar pidiendo al usuario un rango que tiene un inicio y un fin dichos registros son almacenados en un nuevo archivo .txt
// Fecha: 12 de octubre del 2024

#include "Bitacora.h"
#include "Registro.h"

// <iostream> <iomanip> Ya están en el .h
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// iniciliza la bitacora
Bitacora::Bitacora(Registro* registro){
    this->size=0;
    this->head=registro;
    this->tail=registro;
}

// constructor por default
Bitacora::Bitacora():Bitacora(nullptr){}

// constructor por default
Bitacora::Bitacora(string nombreArchivo):Bitacora(nullptr){
    leerArchivo(nombreArchivo);
}

// Destructor de la bitacora
Bitacora::~Bitacora(){
    while(!isEmpty()){
        removeLast();
    }
}

/*Elimina el ultimo registro que hay dentro de lo que se seleccione
en este caso se ua para limpiar los constructores cuenta con una complejidad de O(1)*/
void Bitacora::removeLast(){ 
    if(this->size >0){
        if(this->size==1){
            delete tail;
            this->tail=nullptr;
            this->head= nullptr;

        } else {
            Registro *nodo= head,
            *tmp= this->tail;

            for(int i=1; i<this->size-1; i++){
                nodo= nodo->next;
            }
            this->tail= nodo;
            this->tail->next=nullptr;
            delete tmp;
        }
        size--;
    } else {
        //throw invalid_argument("No se puede remover el ultimo elemento de una lista vacia. ");
    }
}

/*Esto nos permite inserta un nuevo registro al inicio de la lista enlazada, si la lista no esta vacia crea un nuevo nodo el cual apunta al head existente y lo actualiaza, si la lista esta vacia crea 
un nuevo nodo y lo asigna tanto a head como a tail.
La complejidad de este metodo es O(1)*/
void Bitacora::insertFirst(string data){ 
    if(this->size >0){
        Registro* nvo= new Registro(data, this->head);
        this->head=nvo;

    } else {
        Registro* nvo= new Registro(data, nullptr);
        this->head=nvo;
        this->tail=nvo;
    }
    this->size++;
}

// Abree un archivo de texto y verficica que se abra correctamente y lo lee linea por liena
// Tiene una complejidad de O(n)
void Bitacora::leerArchivo(string arc){
    //Abre el archivo
    ifstream archivo(arc);
    if(! archivo.is_open()){
        cout << "Error al abrir el archivo" <<"\n";
        exit(EXIT_FAILURE);
    }

    //Mada a crear un archivo con cada renglon y se establece al incio de la lista enlazada
    string linea;
    while (getline(archivo, linea)) {
        insertFirst(linea);
    }
    archivo.close();
}

// Devuelve el tamaño de la bitacora
// complejidad O(1)
int Bitacora::getSize(){
    //Retorna la cantidad de registros en la bitacora
    return size;
}

// Ordena los registros de la bitacora verificando si es que esta contiene mas de 1 registro
// complejidad O(nlog(n))
void Bitacora::ordenarBitacora(){
    if(size>1){
        //Se inicia el proceso de ordenamiento usando Merge Sort
        ordenaMerge(head, tail);
    } else {
        throw("No se puede ordenar una bitacora de menos de 2 registros");
    }
}

// Implementa el Merge Sort para una lista enlazada y encuentra el punto medio
// complejidad O(nlog(n))
Registro* Bitacora::ordenaMerge(Registro* iniNodo, Registro* finNodo){
    if(iniNodo != finNodo ){
        Registro* ss= iniNodo;
        Registro* ff= iniNodo->next;

        //Encuentra el puntero al centro de la lista
        while(ff != nullptr && ff->next != nullptr){
            ss= ss->next;
            ff= ff->next->next;
        }
        Registro* cenNodo=ss;

        //Divide la lista en dos partes
        Registro* cen= ordenaMerge(cenNodo->next, finNodo);
        cenNodo->next=nullptr;
        Registro* ini= ordenaMerge(iniNodo, cenNodo);

        return mezcla(ini, cen);     
    } else{
        return iniNodo;
    }
}

// Mezcla dos mitades ordenadas y la devuelve una sola que ya esta ordenada
// complejidad O(n)
Registro* Bitacora::mezcla(Registro* iniNodo, Registro* cenNodo){   
    //Mezcla dos mitades ordenadas 
    Registro* i= iniNodo;
    Registro* j= cenNodo;
    Registro* k= nullptr;
    Registro* k_ini= nullptr;
    Registro* tempNodo;

    while(i != nullptr && j != nullptr){
        if(i->getID() < j->getID()){
            tempNodo=i;
            i=i->next;
        } else {
            tempNodo=j;
            j=j->next;
        }

        if(k_ini== nullptr){
            k_ini= tempNodo;
            k= tempNodo;
        } else {
            k->next=tempNodo;
            k= k->next;
        }
    }

    //Une los nodos restantes de las listas que no fueron comparados
    while(i != nullptr){
        tempNodo= i;
        i= i->next;
        if(k_ini== nullptr){
            k_ini= tempNodo;
            k= tempNodo;
        } else {
            k->next=tempNodo;
            k= k->next;
        }
    }
    while (j != nullptr){
        tempNodo= j;
        j= j->next;
        if(k_ini== nullptr){
            k_ini= tempNodo;
            k= tempNodo;
        } else {
            k->next=tempNodo;
            k= k->next;
        }
    }

    //Coloca nuevos apuntadores al head y tail de la
    if(k->getID() > tail->getID()){
        tail= k;
    }
    if(k_ini->getID() < head->getID()){
        head= k_ini;
    }

    return k_ini;
}

// Se implementa el metodo de busqueda con el cual sabremos el inicio y el final del rango de busqueda con una complejidad de O(n)
Registro* Bitacora::busqSecuencial(long long int ini_ID){
    //Implementamos busqueda secuencia para encontrar un registro por ID
    Registro* actual = head;
    while (actual->getID() < ini_ID && actual!= nullptr) {
        actual=actual->next;
    }
    return actual;  //apuntador al registro encontrado
}

//Devuelve true si la lista esta vacia
bool Bitacora::isEmpty(){
    return this->head==nullptr;
}

//Busca los registros en un rango de tiempo y manda a exporarlos. Complejidad O(n)
void Bitacora::buscarRegistro(int N){
    //Pide los datos de su busqueda al usuario
    string datosIni, datosFin;
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Dame la IP de inicio de busqueda: ";
    getline(cin, datosIni);
    cout<<"---------------------------------------------------"<<endl;
    cout<<"Dame la IP de fin de busqueda: ";
    getline(cin, datosFin);
    cout<<"---------------------------------------------------"<<endl;

    //Se crean registros (para aprovechar codigo) con los datos de IP y se suma texto basio para asignar a mes, dia, hora, minuto, segundo, puerto y razon
    Registro registroIni("mm dd hh:mm:ss "+ datosIni + ":0000 rr", nullptr);
    Registro registroFin("mm dd hh:mm:ss "+ datosFin + ":9999 rr", nullptr);


    //Imprime el archivo con los registros en el rango de busqueda
    Registro* posIni= busqSecuencial(registroIni.getID());
    Registro* posFin= &registroFin;

    exportarBitacora(posIni, posFin, "salida"+to_string(N)+"-Eq5.txt");
}

//Crea un archivo con los registros contenidos en los rangos y el nombre dado. Complejidad O(n)
void Bitacora::exportarBitacora(Registro* posIni, Registro* posFin, string nombreArchivoExp){
    //Crea el archivo de todos los registros ordenados
    fstream file;

    //Checa si el apuntador al inicio esta dentro del rango
    if(posIni==nullptr){
        throw invalid_argument("No hay registros en ese rango de tiempo");
    }
    //Checa si el apuntador del final es menor al del inicio
    if(posFin->getID()< posIni->getID()){
        throw invalid_argument("Limites de inicio y final incorrectos");
    }

    //Crea el archivo de busqueda
    file.open(nombreArchivoExp, ios::out);

    //Ciclo para escribir los registros de la busqueda en su respectivo archivo
    Registro* actual= posIni;
    while (actual->getID() < posFin->getID() && actual != nullptr) {

        // Si el ID del registro actual esta dentro del rango
        file<<actual->getMes() <<" " <<actual->getDia() <<" " <<actual->getTiempo() <<" " <<actual->getDireccionIP() <<" " <<actual->getRazon() <<"\n";
        actual = actual->next;
    }

    //Cierra el archivo despues de completar la busqueda
    file.close();
    cout<<"Archivos guardados exitosamente" <<"\n";
}

//Manda a exportar la bitacora con todos sus registros. Complpejidad O(n)
void Bitacora::exportarBitacoraCompleta(string nombreArchivoExp){
    exportarBitacora(head, tail, nombreArchivoExp); //O(n)
}