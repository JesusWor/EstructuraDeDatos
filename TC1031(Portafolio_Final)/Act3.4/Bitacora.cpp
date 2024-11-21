// Equipo 3
// Angel Gabriel Camacho Perez - A01743075
// Ana Paula Navarro Hernandez - A01644875
// Jesus Eduardo Escobar Meza - A01743270
/* Descripcion: Este programa lee un archivo que contiene registros, los cuales se ordenan de menor a mayor por medio de la IP y el puerto, las IP se almacenan en un BST tomando en cuenta su frecuencia de intento de acceso. Se genera un nuevo archivo .txt con los registros ordenados y además imprime las IP que mas frecuencia de acceso tuvieron. */
// Fecha: 04 de noviembre del 2024

#include "Bitacora.h"
#include "Registro.h"

// <iostream> <iomanip> Ya estan en el .h
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// iniciliza la bitacora
Bitacora::Bitacora(Registro* registro){
    this->sizeReg=0;
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
    //cout<<"Registros eliminados correctamente. \n";

    deleteIP(root);
    //cout<<"NodoIPs eliminados correctamente. \n";
}

/*Elimina el ultimo registro que hay dentro de lo que se seleccione
en este caso se ua para limpiar los constructores cuenta con una complejidad de O(1)*/
void Bitacora::removeLast(){ 
    if(this->sizeReg >0){
        if(this->sizeReg==1){ //si solo hay un registro
            delete tail;
            this->tail=nullptr; //se elimina el registro
            this->head= nullptr; //se elimina el primer nodo

        } 
        else { //si hay mas de un registro
            Registro *nodo= head, 
            *tmp= this->tail; //se crean dos nodos auxiliares

            for(int i=1; i<this->sizeReg-1; i++){ //se recorre el arbol
                nodo= nodo->next;
            }
            this->tail= nodo;
            this->tail->next=nullptr;
            delete tmp;
        }
        sizeReg--; 
    } 
    else {
        //throw invalid_argument("No se puede remover el ultimo elemento de una lista vacia. ");
    }
}

/*Esto nos permite inserta un nuevo registro al inicio de la lista enlazada, si la lista no esta vacia crea un nuevo nodo el cual apunta al head existente y lo actualiaza, si la lista esta vacia crea 
un nuevo nodo y lo asigna tanto a head como a tail.
La complejidad de este metodo es O(1)*/
void Bitacora::insertFirst(string data){ 
    if(this->sizeReg >0){ //si la lista no esta vacia
        Registro* nvo= new Registro(data, this->head); 
        this->head=nvo;

    } 
    else { //si la lista esta vacia
        Registro* nvo= new Registro(data, nullptr); //se crea un nuevo nodo
        this->head=nvo;
        this->tail=nvo;
    }
    this->sizeReg++;
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
int Bitacora::getSizeRegistros(){
    //Retorna la cantidad de registros en la bitacora
    return sizeReg;
}

// Ordena los registros de la bitacora verificando si es que esta contiene mas de 1 registro
// complejidad O(nlog(n))
void Bitacora::ordenarBitacora(){
    if(sizeReg>1){
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
        Registro* cenNodo=ss; //se guarda el puntero al centro de la lista

        //Divide la lista en dos partes
        Registro* cen= ordenaMerge(cenNodo->next, finNodo);
        cenNodo->next=nullptr;
        Registro* ini= ordenaMerge(iniNodo, cenNodo);

        return mezcla(ini, cen); 
    } 
    else{ //Si la lista tiene un solo nodo
        return iniNodo;
    }
}

//Mezcla dos mitades ordenadas y la devuelve una sola que ya esta ordenada
// complejidad O(n)
Registro* Bitacora::mezcla(Registro* iniNodo, Registro* cenNodo){   
    //Mezcla dos mitades ordenadas 
    Registro* i= iniNodo; //se crea un nuevo nodo que apunta al inicio de la primera mitad
    Registro* j= cenNodo; //se crea un nuevo nodo que apunta al inicio de la segunda mitad
    Registro* k= nullptr; //se crea un nuevo nodo 
    Registro* k_ini= nullptr; //se crea un nuevo nodo que apunta al inicio de la lista ordenada
    Registro* tempNodo; //nodo temporal

    while(i != nullptr && j != nullptr){
        if(i->getID() < j->getID()){ //si el primer nodo es menor que el segundo
            tempNodo=i; //se guarda el primer nodo
            i=i->next;
        } 
        else { //si el segundo nodo es menor que el primero
            tempNodo=j;
            j=j->next;
        }
        if(k_ini== nullptr){ //si la lista esta vacia
            k_ini= tempNodo;
            k= tempNodo;
        } 
        else { //si la lista no esta vacia
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
        } 
        else {
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
        } 
        else {
            k->next=tempNodo; 
            k= k->next;
        }
    }

    //Coloca nuevos apuntadores al head y tail de la
    if(k->getID() > tail->getID()){ 
        tail= k; //se actualiza el tail
    }
    if(k_ini->getID() < head->getID()){
        head= k_ini; //se actualiza el head
    }

    return k_ini;
}

//Se implementa el metodo de busqueda con el cual sabremos el inicio y el final del rango de 
// busqueda con una complejidad de O(n)
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
    while (actual != nullptr && actual->getID() <= posFin->getID()) {

        // Si el ID del registro actual esta dentro del rango
        file<<actual->getRegistroStr() <<"\n";
        actual = actual->next;
    }

    //Cierra el archivo despues de completar la busqueda
    file.close();
    //cout<<"Archivos guardados exitosamente" <<"\n";
}

//Manda a exportar la bitacora con todos sus registros. Complpejidad O(n)
void Bitacora::exportarBitacoraCompleta(string nombreArchivoExp){
    exportarBitacora(head, tail, nombreArchivoExp); //O(n)
}

//Genera los nodos de IP con su respectiva cantidad de accesos y los manda a insertar en el BST. Complejidad O(n log n)
void Bitacora::encontrarFrecuenciaIPs(){
    Registro* actual= head;
    int frecuencia=1;

    while (actual != nullptr) {
        if( actual->next != nullptr && actual->getIP() == actual->next->getIP()){ //si el siguiente nodo es igual al actual
            frecuencia++;
        } 
        else { //si el siguiente nodo es diferente al actual
            NodoIP* nodo= new NodoIP(actual->getIP(), frecuencia); 
            insertBST(nodo); //se inserta el nodo en el BST. O(log n)
            frecuencia= 1;
        }
        actual = actual->next; //se avanza al siguiente nodo
    }
}

//Guarda las IP en un arbol binario acomodado segun su frecuencia. O(log n)
void Bitacora::insertBST(NodoIP* nodoAgr){
    NodoIP* nodo= root;
    NodoIP* nodoPa= root;
    while(nodo != nullptr){
        if(nodoAgr->frecuencia < nodo->frecuencia){ //si la frecuencia del nodoAgr es menor que la del nodo
            nodoPa=nodo;
            nodo= nodo->left;
        } 
        else if(nodoAgr->frecuencia >= nodo->frecuencia){ //si la frecuencia del nodoAgr es mayor o igual que la del nodo
            nodoPa=nodo;
            nodo= nodo->right; 
        }
    }
    
    if(nodoPa == nullptr){ //si el nodo padre es nulo
        root= nodoAgr; 
        sizeIP++;
        return;
    } 
    else if(nodoAgr->frecuencia< nodoPa->frecuencia){ //si la frecuencia del nodoAgr es menor que la del nodo padre
        nodoPa->left= nodoAgr;
        sizeIP++;
        return;
    } 
    else if(nodoAgr->frecuencia>= nodoPa->frecuencia){  //si la frecuencia del nodoAgr es mayor o igual que la del nodo padre
        nodoPa->right= nodoAgr;
        sizeIP++;
        return;
    } 
    else { 
        return;
    }
}

//Hace un recorrido en inorden para mostrar las IPs con mayor frecuencia
void Bitacora::showIP(int n){ //O(n)
    showIP(root, n);
}

int Bitacora::showIP(NodoIP* current, int n){ //O(n)
    if(current->right != nullptr){ //si el nodo derecho no es nulo
        n= showIP(current->right, n); //se manda a llamar a la funcion con el nodo derecho
    }
    if(n>0){ //si n es mayor a 0
        cout<< current->IP <<" " <<current->frecuencia <<"\n"; //se imprime la IP y su frecuencia
        n--;
    }
    if(current->left != nullptr){ //si el nodo izquierdo no es nulo
        n= showIP(current->left, n); //se manda a llamar a la funcion con el nodo izquierdo
    }
    return n;
}

//Borra el BST de IPs
void Bitacora::deleteIP(NodoIP* current){ //O(n)
    if(current->left != nullptr){ //si el nodo izquierdo no es nulo
        deleteIP(current->left); 
    }
    if(current->right != nullptr){ //si el nodo derecho no es nulo
        deleteIP(current->right);
    }
    delete current; //se elimina el nodo 
}