#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <string>
#include <ostream>
using namespace std;

// Clase MyLinkedList
struct MyNodoLL{
  string key;
  string data;
  int id;
  MyNodoLL* next;

  //esto es un constructor
  MyNodoLL(string key, string data, int id, MyNodoLL* next){
    this->key= key;
    this->data= data;
    this->id= id;
    this->next= next;
  }

  //esto es un constructor que crea un nodo con data = data y next = nullptr
  MyNodoLL(string key, string data, int id):MyNodoLL(key, data, id, nullptr){} //nullptr significa que no hay nada
};
    
class MyLinkedList{
  private:

  public:
    int size;
    MyNodoLL* head; //puntero a un nodo
    MyNodoLL* tail;
    MyLinkedList();
    ~MyLinkedList();
    int length();
    bool isEmpty();
    string getAtData(string key);
    int getAtID(string key);
    void setAt(int pos, string data);
    void insertFirst(string key, string data, int id);
    void removeFirst();
    void removeAt(string key); 

    void insert(string key, string data, int id);
    void showForKey(string key);

  friend ostream& operator<<(ostream& os,const MyLinkedList& ll){
      MyNodoLL* current= ll.head;
      for(int i=0; i<ll.size; i++){
        os<<"["<<current->key<<","<<current->data<<"],";
        current= current->next;
      }
      return os;
  }
};

#endif