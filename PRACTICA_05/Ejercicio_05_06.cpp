// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Fecha creación: 02/10/2025 
// Número de ejercicio: 6 
// Problema planteado:  Programa que declare tres vectores ‘vector1’, ‘vector2’ y ‘vector3’ de cinco enteros 
// cada uno, pida valores para ‘vector1’ y ‘vector2’ y calcule vector3=vector1+vector2. 
#include <iostream>
using namespace std;
int main() 
{
    int vector1[5], vector2[5], vector3[5];
    cout << "VECTOR 1 (5 elementos):" << endl;
    for(int i = 0; i < 5; i++) 
    {
        cout << "Elemento " << (i+1) << ": ";
        cin >> vector1[i];
    }
    cout << "VECTOR 2 (5 elementos):" << endl;
    for(int i = 0; i < 5; i++) 
    {
        cout << "Elemento " << (i+1) << ": ";
        cin >> vector2[i];
    }
    for(int i = 0; i < 5; i++) 
    {
        vector3[i] = vector1[i] + vector2[i];
    }
    cout << "\nRESULTADO vector3 = vector1 + vector2:" << endl;
    cout << "Vector1: ";
    for(int i = 0; i < 5; i++) cout << vector1[i] << " ";
    
    cout << "\nVector2: ";
    for(int i = 0; i < 5; i++) cout << vector2[i] << " ";
    
    cout << "\nVector3: ";
    for(int i = 0; i < 5; i++) cout << vector3[i] << " ";
    cout << endl;
    
    return 0;
}
