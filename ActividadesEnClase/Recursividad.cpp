#include <iostream>
using namespace std;

unsigned long long factorial(int n)
{
    if(n > 1)
    {
        return n*factorial(n-1);
    }
    else{
        return 1;
    }
}
int main()
{
    int n;
    unsigned long long resFac;
    cout << "Ingresa el numero al cual le quieras calcular su factorial: ";
    cin >> n;
    resFac = factorial(n);
    cout<< "El factorial de "<<n<<" es: "<<resFac;
}