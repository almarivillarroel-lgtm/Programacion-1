// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 5
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    int N;
    cout << "Ingrese la cantidad de números aleatorios a generar: ";
    cin >> N;

    srand(time(0));

    int suma = 0;
    int mayor = 0;
    int menor = 1001; // Mayor que el máximo posible (1000)
    int num;

    for (int i = 0; i < N; i++) 
    {
        num = rand() % 1000 + 1; // Número entre 1 y 1000
        suma += num;
        if (num > mayor) mayor = num;
        if (num < menor) menor = num;
    }

    double promedio = (N > 0) ? (double)suma / N : 0;

    cout << "Sumatoria: " << suma << endl;
    cout << "Promedio: " << promedio << endl;
    cout << "Mayor valor generado: " << mayor << endl;
    cout << "Menor valor generado: " << menor << endl;

    return 0;
}