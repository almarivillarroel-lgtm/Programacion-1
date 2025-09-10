// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 6
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función para verificar si un número es primo
bool esPrimo(int num) 
{
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) 
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    int N;
    cout << "Ingrese la cantidad de números aleatorios a generar: ";
    cin >> N;

    srand(time(0));
    int contadorPrimos = 0;

    cout << "Números generados:" << endl;
    for (int i = 0; i < N; i++) 
    {
        int num = rand() % 10000 + 1; // Número entre 1 y 10000
        cout << num << " ";
        if (esPrimo(num)) 
        {
            contadorPrimos= contadorPrimos + 1;
        }
    }
    cout << endl << "Cantidad de números primos: " << contadorPrimos << endl;

    return 0;
}