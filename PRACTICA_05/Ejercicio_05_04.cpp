// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 02/10/2025 
// Número de ejercicio: 1 
// Problema planteado: Leer 2 vectores de dimensión N y calcule la multiplicación de los mismos en otro vector. 
#include <iostream>
using namespace std;

int main() 
{
    int N;
    cout << "Ingrese la dimension de los vectores: ";
    cin >> N;
    int vector1[N], vector2[N], resultado[N];
    cout << "\nVector 1:" << endl;
    for(int i = 0; i < N; i++) 
    {
        cout << "Elemento " << (i+1) << ": ";
        cin >> vector1[i];
    }
    cout << "\nVector 2:" << endl;
    for(int i = 0; i < N; i++) 
    {
        cout << "Elemento " << (i+1) << ": ";
        cin >> vector2[i];
    }
    for(int i = 0; i < N; i++) 
    {
        resultado[i] = vector1[i] * vector2[i];
    }
    cout << "\nResultado de la multiplicacion:" << endl;
    for(int i = 0; i < N; i++) 
    {
        cout << resultado[i] << " ";
    }
    cout << endl;
    
    return 0;
}