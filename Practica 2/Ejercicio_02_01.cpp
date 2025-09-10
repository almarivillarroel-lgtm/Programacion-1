// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 1 
#include <iostream>
using namespace std;
#include <cstdlib>  
#include <ctime>    
int main() 
{
    int n=0;
    cout << "Ingrese el número de lanzamientos: ";
    cin >> n;

    int pares = 0;
    srand(time(0)); // Inicializa la semilla aleatoria

    for (int i = 0; i < n; i++) 
    {
        int dado = rand() % 6 + 1; // Número entre 1 y 6
        if (dado % 2 == 0) 
        {
            pares= pares + 1;
        }
    }

    cout << "Frecuencia de caras pares: " << pares << endl;
    return 0;
}