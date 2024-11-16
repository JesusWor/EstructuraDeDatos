/*
Programa para saber la sumatoria de un numero dado n de
forma iterativa, recursiva y directa
Nombre: Jesus Eduardo Escobar Meza
Matricula: A01743270
*/
#include <iostream>
using namespace std;

//Complejidad O(n)
/* Esta función nos permite conocer la sumatoria de un número dado N de 
forma iterativa, con una complejidad anteriormente dada. Utiliza un argumento 
N y un acumulador llamado SUMA, que se encargará de guardar los valores sumados y
será regresado al final del ciclo. Dicho ciclo se realizará desde 1 hasta N */
int sumaIterativa(int n){
    int suma = 0;
    for(int i=1; i<=n;i++){
        suma += i;
    }
    return suma;
}

//Complejidad O(n)
/* Esta función al igual que la anterior nos permite saber la sumatoria de un número
N pero lo hace de manera recursiva. Esto hace que la función se este llamando asi misma
todo el tiempo. Al igual que la anterior tiene un argumento de N */
int sumaRecursiva(int n){
    if(n==0)
    {
        return 0;
    }
    else
    {
        return n + sumaRecursiva(n-1);
    }
}

//Complejidad O(1)
/* Esta función al igual que las anteriores nos permite conocer la sumatoria de un nÚmero 
N solo que este usa una funcion más sencilla. Este codigo es mas eficiente y rapido, esto
se puede saber debido a su complejidad anteriormente dada. Al igual que las anteriores
funciones esta tiene un argumento de N */
int sumaDirecta(int n){
    return (n*(n+1))/2;
}

int main(){
    int N;
    cout << "Introduce el termino al que te interesa calcular la sumatoria: ";
    cin>> N;
    cout<< "El resultado de la operacion con suma iteratuva: "<<sumaIterativa(N)<<endl;
    cout<< "El resultado de la operacion con suma recursiva: "<<sumaRecursiva(N)<<endl;
    cout<< "El resultado de la operacion con suma directa: "<<sumaDirecta(N)<<endl;
}