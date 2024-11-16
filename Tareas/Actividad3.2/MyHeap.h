/*
Programa en el cual implementaremos los algoritmos necesarios para el 
buen funcionamiento del arbol Heap con una fila priorizada adenas de que
se implemntaran metodos para su ordenamiento de prioridad (MaxHeap).
El metod swap para el cambio se uso el codigo anteriormente visto en clase para el ordenamiento
de listas.
Nombre: Jesus Eduardo Escobar Meza 
Matricula: A01743270 
Fecha: 29 de octubre de 2024
*/
#ifndef MYHEAP_H
#define MYHEAP_H

//Recuerden poner como comentario en cada operación la complejidad de la misma para el mejor de los casos y para el peor de los casos
//y expliquen en cual situación se da el mejor de los casos y en cual el peor.
class   MyHeap{
    private:
        //Metodo extra para el 
        void swap(int i, int j); //permite cambiar los valores esto sera para cuando el hijo se mayr al padre poder cambiarlos
        void heapify(int i); //Metodo para poder ordenarse cuando 
        void heapsort(); //Metodo para ordenar el heap

    public: //Dejar todo público para poder revisar atributos
        int* values; //Arreglo donde se van a guardar los valores del HEAP
        int size;    //Representa cuantos valores tiene almacenado el Heap
       int len;    //Representa el tamaño o capacidad máxima actual del arreglo
    //public:
        MyHeap();//Inicializa el los atributos. El atributo values lo inicializa como un arreglo vacío tamaño de 7.
        MyHeap(int* valores,int size); //Conviert el arreglo en un heap. Lo deja del mismo tamaño que tiene el arreglo
        void push(int n); //Inserta un valor en el heap. Sólo cuando el nuevo valor no cabe en el arreglo
                          //crece el arreglo al tamaño 2*n+1. (Expansión din+amica del arreglo)
                          //Es decir si se tiene el arreglo ya con 7 valores y se quiere insertar otro valor(El 8vo)
                          //entonces el arreglo se crece a tamaño 15, se copian los primeros 7 valores del arreglo original
                          //y se inserta el 8vo valor.
        void pop();//Se elimina un valor del heap. No es necesario nunca decrementar el tamaño del arreglo.
        int top();//regresa quien es el siguiente elemento en salir pero sin borrarlo
        bool isEmpty();//regresa true si el heap está vacío caso contrario regresa false
        int length();//regresa cuántos elementos están almacenando el heap. OJO: NO EL TAMAÑO
        void imprimir();//Imprime los atributos del heap. Debe ser la implementación que se muestra abajo. No cambiar nada.

         /*Pone en el .h sólo la declaración del método y en el cpp esta definición
         void MyHeap::imprimir(){
              cout<<"arbol size: "<<this->size<<" len:"<<this->len<<endl;
              for(int i=0; i<this->size; i++){
                    cout<<values[i]<<",";
               }
               cout<<endl;
         }*/
   };

#endif 