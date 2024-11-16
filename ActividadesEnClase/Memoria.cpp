#include <iostream>
using namespace std;

// * este significa una apuntador
// & este significa una direccion
void swap1(int a, int b){
   int aux = a;
   a = b;
   b = aux;
}

void swap2(int* a, int* b){//apuntador
   int aux = *a;
   *a = *b;
   *b = aux;
} 

void swap3(int& a, int&b){
   int aux = a;
   a = b;
   b = aux;
}

int main(){
   int a = 10;
   int b = 50;
   int* ptr = &a;
   *ptr = 50;
   cout<<a<<" "<<*ptr<<endl;
//-----------------------------
   a = 10;
   b = 50;
   swap1(a,b);
   cout<<a<<" "<<b<<endl;
//-----------------------------
   a = 10;
   b = 50;
   swap2(&a, &b); //direccion
   cout<<a<<" "<<b<<endl;
//-----------------------------
   a = 10;
   b = 50;
   swap2(&a, &b); //direccion
   cout<<a<<" "<<b<<endl;
   return 0;
}