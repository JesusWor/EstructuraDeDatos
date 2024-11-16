/*
En el siguiente programa veremos los metods necesearios para poder implementar un hash table asi como tambien la complejidad que tiene cada uno
y una breve descripcion de lo que hace cada uno de los metodos adenmas de que se agrego la calse MyLinkedList (clase la cual se habia hecho anteriormente)m 
esta clase nos sirvio ya que lo que hacemos es que cada una de las posiciones del arreglo de la tabla de hash sea una lista enlazada, esto nos ayuda a que
al momento de guardar un valor este se guarde en una lista si es que el la posicion ya tiene otro valor (la clase fue alterada para que pudiera ser compatible y
usable para este programa).
Nombre: Jesus Eduardo Escobar Meza
Matricula: A01743270
Fecha: 07/11/24
*/
#include "MyLinkedList.h"
#include "MyHashTable.h"
#include <cmath>
#include <functional>

/*
Inicilia la tabla de hash con un tamaño de su arreglo igual 11 y con una cantidad dentro de 
la tabla de 0 ademas de que la tabla es un arreglo de listas enlazadas cada posicion de la 
tabla es una lista enlazada.
Compejidad: O(1) ya que solo se inicializan las variables asi que en ambos casos 
contienen la misma complejidad.
*/
MyHashTable::MyHashTable(){
    this->size=0;
    this->sizeA=11;
    this->tabla=new MyLinkedList[this->sizeA];
}

/*
Esta funcion nos permite eliminar todas las listas enlazadas que hay en la tabla y libera
la memoria asignada.
Compejidad: 
Peor de los casos: O(n * m) si la lista enlazdas no estan vacias se tiene que ir recorriendo 
cada no de la lista (m) y cada elemento de la tabla (n).
Mejor de los casos: O(n) si la lista esta vacia eliminarlas sera mas rapido.
*/
MyHashTable::~MyHashTable(){
    // Borrar cada una de las listas y despues borrar el arreglo
    for (int i = 0; i < sizeA; i++) {
        while(!this->tabla[i].isEmpty()){
            this->tabla[i].removeFirst(); 
        }
    }    
    delete[] this->tabla;
}

/*
Duplica el tamaño del arreglo y reorganiza los elementos ingresando los elementos de la vieja
tabla en la nueva tabla ademas de que elimina la tabla anterior.
Complejidad: O(n) esto es en el peor y mejor caso ya que todos los elementos tienen que volver a 
ser ingresados en la nueva tabla.
*/
void MyHashTable::rehashing() { 
    int sizeAOg = this->sizeA;
    this->size = 0;
    sizeA = 2 * this->sizeA + 1;
    MyLinkedList* tablaOg = tabla;
    tabla = new MyLinkedList[sizeA]; 
    for(int i = 0; i < sizeAOg; i++) { 
        MyLinkedList* tmp = &tablaOg[i]; 
        while(!tmp->isEmpty()) { 
            put(tmp->head->key, tmp->head->data);
            tmp->removeFirst(); 
        } 
    } 
    delete[] tablaOg; 
}

/*
Esta funcion nos permite calcular la llave para saber posicion en la que se va a guardar un nodo 
en la tabla.
Complejidad: O(1) esto es en ambos casos ya que solo se calcula la posicion en la que se va a 
guardar el nodo.
*/
int MyHashTable::getPos(string key){
    size_t hashC = hash<string>{}(key); // Genera un numero basado en el contenido de la llave
    int hashCode = static_cast<int>(hashC);
    return abs(hashCode) % this->sizeA;
}

/*
Esta funcion nos permite saber si la tabla esta vacia o no.
Complejidad: O(1) esto es en ambos casos ya que solo se pregunta si la tabla esta vacia o no.
*/
bool MyHashTable::isEmpty(){
    return this->size == 0;
}

/*
Esta funcion nos permite checar si es que el tamaño de la tabla es mayor o igual al 75% del tamaño 
si cumple esa condiciones se llama a la funcion rehashing para aumentar su tamaño ademas de que nos
permite insertar un nuevo nodo par clave-valor.
Complejidad:
Peor de los casos: O(n) si se tiene que hacer rehashing se tiene que recorrer toda la tabla para
insertar los elementos en la nueva tabla.
Mejor de los casos: O(1) si no se tiene que hacer rehashing solo se inserta el nodo en la tabla.
*/
void MyHashTable::put(string key, int value){
    //LoadFactor = numero de elemetos almacenados / tamaño de la tabla
    //double carga = static_cast<double>(this->size)/this->sizeA;
    //if(carga >= 0.75){
    if(this->size >= double(this->sizeA) * 0.75){
        rehashing();
    }
    int pos = getPos(key);
    MyLinkedList* lista = &this->tabla[pos];
    lista->insertFirst(key,value);
    //this->tabla[pos].insertFirst(key,value);
    this->size++;
}

/*
Esta funcion nos permite obtener el valor de un nodo en la tabla de hash mendiante su llave.
Complejidad: 
Peor de los casos: O(n) si el nodo no existe en la tabla se tiene que recorrer toda la lista enlazada.
Mejor de los casos: O(1) si el nodo existe en la tabla solo se tiene que regresar el valor del nodo.
*/
int MyHashTable::get(string key){
    int pos = getPos(key);
    //cout<< "pos: "<<pos<<endl;
    MyLinkedList* lista = &this->tabla[pos];
    return lista->getAt(key);
    //return this->tabla[pos].getAt(key);
}

/*
Esta funcion nos permite eliminar un nodo de la tabla de hash mediante su llave.
Complejidad:
Peor de los casos: O(n) si el nodo no existe en la tabla se tiene que recorrer toda la lista enlazada.
Mejor de los casos: O(1) si el nodo existe en la tabla solo se tiene que eliminar el nodo.
*/
void MyHashTable::remove(std::string key) { 
    int pos = getPos(key); 
    if(this->tabla[pos].isEmpty()) { 
        throw std::invalid_argument("No se encontro la llave(removeMHT)"); 
    } 
    this->tabla[pos].removeAt(key); 
    this->size--;
}