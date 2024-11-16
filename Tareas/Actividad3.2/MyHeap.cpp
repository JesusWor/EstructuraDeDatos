/*
Programa en el cual implementaremos los algoritmos necesarios para el 
buen funcionamiento del arbol Heap con una fila priorizada adenas de que
se implemntaran metodos para su ordenamiento de prioridad (MaxHeap).
El metod swap para el cambio se uso el codigo anteriormente visto en clase para el ordenamiento
de listas.
Referencias: Michael Sambol. (2016, 2 agosto). Heap sort in 4 minutes [Vídeo]. YouTube. https://www.youtube.com/watch?v=2DmK_H7IdTo
Este video se utilio para tener una idea mas clara para el metodo heapsort.
Algunos metodos fueron tomados de la clase de Estructura de Datos y corregidos en algunnso aspectos minimos por Copilot (ya que durante el 
testeo usando un main dado por chatgpt se mostro algunos errores logicos).
Nombre: Jesus Eduardo Escobar Meza 
Matricula: A01743270 
Fecha: 29 de octubre de 2024
*/
#include "MyHeap.h"
#include <iostream>

using namespace std;

/*
Constructo que inicializa el los atributos. El atributo values lo inicializa como un arreglo vacío tamaño de 7.
Complejidad: O(1) (esta complejidad esta en ambos casos tanto peor como mejor).
*/
MyHeap::MyHeap(){
    this->values = new int[7];
    this->size = 0;
    this->len = 7;
}

/*
Constructor que toma un arreglo y su tamaño para inicializar un heap, toma los valores de entrada y los manda a
la funcion heapify que sera explicada despues para ordenarlos.
Complejidad: O(n) (al iagual que el anterior esta complejidad actua en ambos casos ya que cada que se inrgesa un 
valor se tiene que pasasr por el heapify pór que actua de manera lineal todo el tiempo).
*/
MyHeap::MyHeap(int* valores, int size) {
    this->size = size; 
    this->len = size; 
    this->values = new int[this->len]; 
    for (int i = 0; i < size; i++) { 
        this->values[i] = valores[i]; 
        } 
    for (int i = this->size/2-1; i >= 0; i--) { 
        heapify(i); 
    } 
}

/*
Esta funcion se encarga de ordenar el arbol para asegurar la propiedad mas alta (siendo que se respete el hecho de que los que estamos haciendo es un 
MaxHeap+). Esta funcion se encarga de hacer que el padre sea mayor que sus hijos. Se compara el nodo actual con sus hijos y se hace un swap si el nodo
hjo es mayor que el padre
Complejidad:
mejor de los casos O(1): Esto ocurre cuando el nodo actual es mayor que sus hijos por lo que no se necesita hacer ningun cambio.
peor de los casos O(log(n)):Esto ocurre cuando el nodo tiene que intercambiar posiciones con nodos hasta llegar al fondo del subarbol.
*/
void MyHeap::heapify(int i){
    int inicio = i;
    int izq = 2*i+1;
    int der = 2*i+2;
    if(izq < this->size && this->values[izq] > this->values[inicio]){ // Ver si el hijo izquiero es mayor al nodo al actual
        inicio = izq;
    } if(der < this->size && this->values[der] > this->values[inicio]){ // Ver si el hijo derecho es mayor al nodo actual
        inicio = der;
    } if(inicio != i) {
        swap(i,inicio);
        heapify(inicio);
    }
}

/*
Esta funcion nos permite agregar un nuevo valor al arbol, si el arbol ya esta lleno se duplica el tamaño del arbol, se copian los valores
y se libera el anteroir espacio de memoria. Despues se inserta el nuevo valor en la ultima posicion del arbol.+
Complejidad:
mejor de los casos O(1): Esto pasa cuando el elemento que se quiere insertar ya cumple con la propiedad de los maxheap
peor de los casos O(log(n)): Esto pasa cuando el nuevo elemento se debe de mover hasta la raiz del arbol.
*/
void MyHeap::push(int n){
    if (this->size == this->len){
        int* temp = new int[this->len*2+1];
        for(int i=0; i < this->size; i++){
            temp[i] = this->values[i]; //generar copia de los valores
        }  
        delete[] this->values;
        this->values = temp;
        this->len = this->len * 2 + 1;
    }
    this->values[this->size] = n;
    this->size++;
    int raiz = this->size -1;
    bool ciclo = true; //variable para romper el ciclo
    while(raiz > 0 && ciclo){
        int padre = (raiz-1)/2;
        if(this->values[raiz] <= this->values[padre]){
            ciclo = false;
        } else {
            swap(raiz,padre);
        }
        raiz = padre;
    }
}

/*
Esta funcion se encarga de eliminar el valor de la raiuz del arbol, reduce el tamaño del arbol y se llama a la 
funcion heapify para mantener la estructura del arbol.
Complejidad:
mejor de los casos O(1): Si el heap solo tiene un valor se elimina de manera directa.
peor de los casos O(log(n)): Ocurre cuando despues de eliminar el maximo el nuevo elemento en la raiz tiene que ser movido hasta el fondo del arbol
para que vuelva a tener la propiedad de un maxheap.
*/
void MyHeap::pop(){
    if(this->size == 0){
        return;
    }
    this->values[0] = this->values[this->size-1];
    this->size--;
    heapify(0);
}

/*
Esta funcion manda a llamar el valor maximo del arcbol sin eliminarlo, en caso del que el arbol este vacio retorna -1.
Complejidad O(1): En ambos casos tiene la misma complejidad ya que solo se esta devolviendo el primer elemento del arbol.
*/
int MyHeap::top(){
    if(this->size > 0){
        return this->values[0];
    }
    return -1;
}

/*
Esta funcion nos permite saber si el arbol esta vacio o no.
Complejidad O(1): Al igual que en las primeras funciones esta tiene un complejidada constante debido a que solo se
esta comparando un valor.
*/
bool MyHeap::isEmpty(){
    return this->size==0;
}

/*
Retorna el numero de valores que hay en el arbol.
Complejidad O(1): Al igual que en las primeras funciones esta tiene un complejidada constante debido a que solo se
buscando conocer un valor el cual se puede obtener de manera directa.
*/
int MyHeap::length(){
    return this->size;
}

/*
Esta funcion nos permite intercambiar los valores en las posiciones i y j del arbol (Dicho codigo se obtuvo anteriormente
durante una actividad de clase).
Complejida O(1): En ambos casos tanto peor como mejor se tiene la misma complejidad ya que solo se estan cambiando los valores de posicion.
*/
void MyHeap::swap(int i, int j){
    int temp = this->values[i];
    this->values[i] = this->values[j];
    this->values[j] = temp;
}

/*
Ordena el heap eztrayendo el elemento mas grande del heap, mandandolo al final y reagustandolo al arbol cada vez.
Complejidad:
mejor de los casos O(n log n): El metodo del heap sort requiere pasar por cada nodo ademas de agregar la complejidad del heapify.
En el peor de los casos constaria de la misma complejidad ya que se tiene que pasar por cada nodo sin importar el orden en el que esten.
*/
void MyHeap::heapsort() {
    for (int i = this->size / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
    for (int i = this->size - 1; i > 0; i--) {
        swap(0, i);
        this->size--;
        heapify(0);
    }
}

/*
Esta funcion nos permite imprimir el arbol, se imprime el tamaño del arbol, el tamaño del arreglo y los valores del arbol.
Complejidad O(n): Esta funcion tiene una complejidad lineal ya que se esta recorriendo con forme los valores que tengo el arbol.
*/
void MyHeap::imprimir(){
    cout<<"arbol size: "<<this->size<<" len:"<<this->len<<endl;
    for(int i=0; i<this->size; i++){
        cout<<values[i]<<",";
    }
    cout<<endl;
}