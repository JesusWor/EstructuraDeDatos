
#include "MyLinkedList.h"
//Ya en el .h <string>
#include <fstream>
#include <stdexcept>
#include <iostream>
using namespace std;

//O(1)
//Constructor por default
MyLinkedList::MyLinkedList(){
  this->size=0;
  this->head=this->tail=nullptr; 
}

//O(n)
//Destructor
MyLinkedList::~MyLinkedList(){
  while(!isEmpty()){
  removeFirst();
  }
}

//O(1)
//Retorna el tamaño de la lista
int MyLinkedList::length(){
  return this->size; 
}

//O(1)
//Retorna true si la lista esta vacia
bool MyLinkedList::isEmpty(){
  return this->size==0; 
}

//O(n)
//Busca el elemento que tiene la llave key y regresa data
string MyLinkedList::getAtData(string key){
  MyNodoLL* nodo= head;
  while(nodo != nullptr){
    if(nodo->key == key){
      return nodo->data;
    }
    nodo= nodo->next;
  }
  //Si no esta entonces arroja una excepcion
  throw std::invalid_argument("No se puede obtener data de un nodo inexistente \n");
}

//O(n)
//Busca el elemento que tiene la llave key y lo borra de la lista
void MyLinkedList::removeAt(string key) {
  MyNodoLL* nodo= head;
  MyNodoLL* nodoPa= nullptr;

  // Verifica que la lista no esté vacía
  if (head == nullptr) {
    throw std::invalid_argument("No se puede borrar de una lista vacía.\n");
  }

  while(nodo != nullptr){
    if(nodo->key == key) {
      if (nodo == head) {
        removeFirst();
        return;
      }else if(nodo == tail){
        nodoPa->next = nullptr;
        tail = nodoPa;
        delete nodo;
        size--;
        return;
      }
      nodoPa->next= nodo->next;
      delete nodo;
      size--;
      return;
    }
    nodoPa= nodo;
    nodo= nodo->next;
  }
  //Si no esta, arroja una excepción
  throw std::invalid_argument("No se puede borrar un nodo inexistente \n");
}

//O(n)
//Asigna un valor en una posición dada
void MyLinkedList::setAt(int pos, string data){
  if(pos<0 || pos>=size){
    throw invalid_argument("Posición inválida");
  }
  MyNodoLL* current=head;
  for(int i=0; i<pos; ++i) {
    current=current->next;
  }
  current->data=data;
}

//O(1)
//Inserta un nuevo nodo al inicio de la lista
void MyLinkedList::insertFirst(string key, string data, int id){
  MyNodoLL* nvo=new MyNodoLL(key, data, id, this->head);
  this->head=nvo;
  this->size++;
  if(this->size==1){
    this->tail= this->head;
  }
}

//
//Inseta un nuevo nodo ordenadamente segun su ID
void MyLinkedList::insert(string key, string data, int id){
  MyNodoLL* nvo=new MyNodoLL(key, data, id, nullptr);
  MyNodoLL* nodoC= head,
          *nodoC_padre= nullptr;
  this->size++;

  if(this->size==1){
    this->head=nvo;
    this->tail= this->head;
  } else {
    while(nodoC !=nullptr){
      if(nodoC->id > nvo->id){
        if(nodoC_padre== nullptr){
          nvo->next= head;
          head= nvo;
        } else {
          nvo->next= nodoC;
          nodoC_padre->next= nvo;
        }
        return;
      }
      nodoC_padre= nodoC;
      nodoC= nodoC->next;
   }
   nodoC_padre->next= nvo;
   tail=nvo;
  }
}

//O(1)
//Elimina el primer nodo de la lista
void MyLinkedList::removeFirst(){
  if(this->size>0){
    MyNodoLL* tmp=this->head;
    this->head=this->head->next;
    delete tmp;
    this->size--;
    if(this->size==0){
      this->tail=nullptr;
    }
  }
  else{
    throw invalid_argument("No se puede borrar el primer elemento de una lista vacia");
  }
}

//O(n)
//Muestra en consola la data de todos los nodos con la IP correspondiente
void MyLinkedList::showForKey(string key){
  MyNodoLL* current=head;
  std::cout<<key <<"\n";
  int c=0, h=0;
  while(current != nullptr){
    if(current->key == key){
      std::cout<<current->data <<"\n";
      c++;
    }
    current= current->next;
    h++;
  }
  if(c==0){
    cout<<"No se tienen registros con esa IP" <<"\n";
  }
  //cout<<"cantidad IP:"<<c <<"\n";
  //cout<<"cantidad Gen:"<<h <<"\n";
}
