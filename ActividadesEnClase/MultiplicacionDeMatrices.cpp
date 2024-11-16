#include <iostream>
using namespace std;

unsigned long long multiplicadordemat(int n){
    for (int i = 1; i<= n; i++)
    {
        for (int j = 1; j<= n; j++)
        {
            C[i,j] = 0
            for(int k = 1; k <= n; k++)
            {
                C[i,j] = C[i,j] + A[i,k] * B[k,j];
            }
        }
    }
}