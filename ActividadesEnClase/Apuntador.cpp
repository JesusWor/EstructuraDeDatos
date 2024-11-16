#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
   int a = 10;
   int* ptr = &a;
   *ptr = 50;
   cout<<a<<" "<<*ptr<<endl;
}