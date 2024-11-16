/*
En el siguiente programa se aplicaran las funciones vistas en clase de ordenamiento
y busuqeda, ademas, se contaran las comparaciones que tiene que hacer cada uno de ellos
tanto para ordenar como para encontar un valor
Nombre: Jesus Eduardo Escobar Meza
Matricula: A01743270
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/* Inicializacion de cada una de las funciones y sus argumntos correspondientes */
void swap(vector<int>& vec,int i, int j);
int ordenaInsercion(vector<int>& vec);
int ordenaBurbuja(vector<int>& vec);
int ordenaMerge(vector<int>& vec);
void merge(vector<int>& vec, int ini, int fin, int& conM);
void mezcla(vector<int>& vec, int ini, int mitad, int fin, int& conM);
int busqSecuencial(vector<int>& vec, int dato, int &cantBS);
int busqBinaria(vector<int>& vec, int dato, int &cantBB);

int main()
{
    vector<int> v1, v2, v3;
    int n, dato;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> dato;
        v1.push_back(dato);
        v2.push_back(dato);
        v3.push_back(dato);
    }
    cout << ordenaInsercion(v1) << " " << ordenaBurbuja(v2) << " " << ordenaMerge(v3) << endl;
    int q, pos;
    int cantBS, cantBB;
    cin >> q;
    for (int i = 0; i < q; i++){
        cantBS = 0;
        cantBB = 0;
        cin >> dato;
        pos = busqSecuencial(v1, dato, cantBS);
        pos = busqBinaria(v1, dato, cantBB);
        cout << pos << " " << cantBS << " " << cantBB << endl;
    }
}

/* Función para que sirve para intercambiar los valores i y j del vector */
void swap(vector<int>& vec, int i, int j){
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

/* Función de ordenaminento la cual se base en irse recorriendo uno por uno 
par acomodarse de manera correcta con una complejidad en el peor de los casos 
de O(n^2) y en el mejor de O(n) */
int ordenaInsercion(vector<int>& vec){
    int n = vec.size();
    int conI = 0;
    for (int i = 1; i < vec.size(); i++){
        int temp = vec[i];
        int j = i - 1;
        for(int j = i; j > 0; j--){
            conI++;
            if(vec[j-1] > vec[j]){
                swap(vec[j-1], vec[j]);
            }else{
                break;
            }
        }
    }
    return conI;
}

/* Codigo para el ordenamiento burbuja va comparando parers y los intercambia si
estos estan acomodados de manera incorrecta. Contiene una complejidad en el peor 
de los casos O(n^2) y en el mejor de O(n) al igual que la función ordenaInsercion */
int ordenaBurbuja(vector<int>& vec){
    int n = vec.size();
    int conB = 0;
    bool ordenado = false;
    for (int i = 0; i < n - 1 && !ordenado; i++){
        ordenado = true;
        for (int j = 0; j < n - 1 - i; j++){
            if (vec[j] > vec[j + 1]){ 
                swap(vec[j], vec[j + 1]);
                ordenado = false;
            }
            conB++;
        }
    }
    return conB;
}

/* La función ordemaMerge divide el vector en mitades de manera recusiva, y luego 
las devuelve ordenadamente. Contiene una complejidad en el peor y mejor de los casos
de O(n log n) */
int ordenaMerge(vector<int>& vec){
    int conM = 0;
    merge(vec, 0, vec.size() - 1, conM);
    return conM;
}

/* La función merge se encarga de dividir el vector en mitades para luego llamar a 
la función mezcla para combinarlos. Contiene una complejidad igual que el anterior 
de O(n log n) ya que este codigo es parte de ordenaMerge */
void merge(vector<int>& vec, int ini, int fin, int& conM){
    int mitad = ini+(fin - ini) / 2;
    if (ini < fin){
        merge(vec, ini, mitad, conM);
        merge(vec, mitad + 1, fin, conM);
        mezcla(vec, ini, mitad, fin, conM);
    }
}

/* toma las dos mitades de un vector y las conbina en un solo vector ya ordenado. 
Contiene una complejidad de O(n)*/
void mezcla(vector<int>& vec, int ini, int mitad, int fin, int& conM){
    vector<int> vec2(fin - ini + 1);
    int i = ini,
        j = mitad + 1,
        k = 0;
    while (i <= mitad && j <= fin){
        if (vec[i] > vec[j]){
            vec2[k] = vec[j];
            j++;
        }else{
            vec2[k] = vec[i];
            i++;
        }     
        conM++;
        k++;
    }
    while (i <= mitad){
        vec2[k] = vec[i];
        i++;
        k++;
    }
    while (j <= fin){
        vec2[k] = vec[j];
        j++;
        k++;
    }
    for (int l = 0; l < vec2.size(); l++){
        vec[ini+l] = vec2[l];
    }
}

/* La función busqSecuencia recorre el vector uno por uno buscando el valor deseado.
Contiene una complejidad de O(n) en el peor de los casos y O(1) en el mejor. */
int busqSecuencial(vector<int>& vec, int dato, int &cantBS){
    for (int i = 0; i < vec.size(); i++){
        cantBS++;
        if (vec[i] == dato){
            return i;
        }
    }
    return -1;
}

/* La función busqBinaria divide el vector en mitades y comopara el elemento central
con el valor, la mitad que elija dependera si el valor es mayor o menor. Contiene una
complejidad de O(log n) */
int busqBinaria(vector<int>& vec, int dato, int &cantBB){
    int min = 0, 
    max = vec.size() - 1,
    avg;
    while (min <= max){
        avg = (min + max) / 2;
        if (vec[avg] == dato){
            cantBB++;
            return avg;
        }
        else if (dato > vec[avg]){
            cantBB++;
            min = avg + 1;
        }
        else{
            max = avg - 1;

        }
        cantBB++;
    }
    return -1;
}