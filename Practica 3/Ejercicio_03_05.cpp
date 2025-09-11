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

// Función para calcular el promedio ponderado
float promedioPonderado(int calificaciones[], int pesos[], int n) 
{
    int sumaPesos = 0;
    float suma = 0;
    for (int i = 0; i < n; i++) 
    {
        suma=suma+calificaciones[i] * pesos[i];
        sumaPesos=sumaPesos+pesos[i];
    }
    return suma / sumaPesos;
}

int main() 
{
    srand(time(0));
    int calificaciones[4];
    int pesos[4] = {10, 20, 30, 40};

    cout << "Calificaciones generadas: ";
    for (int i = 0; i < 4; i++) {
        calificaciones[i] = rand() % 100 + 1; 
        cout << calificaciones[i] << " ";
    }
    cout << endl;

    float promedio = promedioPonderado(calificaciones, pesos, 4);
    cout << "El promedio ponderado es: " << promedio << endl;

    return 0;
}