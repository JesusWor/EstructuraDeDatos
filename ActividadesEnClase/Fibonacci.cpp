#include <iostream>
using namespace std;
///using namespace std::chronos;

unsigned long long fibo(int n) { //Funcion de recursividad sin normal
    if (n == 0 || n == 1) 
    {
        return 1;
    }
    else
    {
        return fibo(n-2) + fibo(n-1);
    }
}

unsigned long long fibOpt(int n, unsigned long long tabla[]) { //Recursividad optimizada
    if(tabla[n] == 0)
    {
        tabla[n] =  fibOpt(n-2,tabla) + fibOpt(n-1,tabla);
    }
    return tabla[n];
}


unsigned long long fibOpt(int n){ //Funcion de preparacion 
// Esto es una tecnica de neomemorizacion
    unsigned long long tabla[n+1];
    for(int i =0; i<n+1; i++)
    {
        tabla[i] = 0;
    }
    tabla[0] = tabla[1] = 1; 
    return fibOpt(n,tabla);
}

int main()
{
    int n;
    //unsigned long long resfibo;
    cout << "Introduce el termino de la serie fibonacci que deseas calcular: ";
    cin>>n;
    //resfibo = fibOpt(n);
    cout<< "El resultado de la operacion "<<fibOpt(n);
}