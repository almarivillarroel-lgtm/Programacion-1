// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 02/10/2025 
// Número de ejercicio: 1 
// Problema planteado:  Leer 2 vectores de dimensión N y combine ambos en otro vector. 
#include <iostream>
using namespace std;

int main() 
{
    int N;
    cout << "Ingrese la dimension de los vectores: ";
    cin >> N;
    int vector1[N], vector2[N], combinado[2*N];
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
        combinado[i] = vector1[i];
        combinado[i + N] = vector2[i];
    }
    cout << "\nVector combinado:" << endl;
    for(int i = 0; i < 2*N; i++) 
    {
        cout << combinado[i] << " ";
    }
    cout << endl;
    
    return 0;
} 