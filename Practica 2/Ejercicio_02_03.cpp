// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 3
#include <iostream>
using namespace std;    
#include <cstdlib>
#include <ctime>
int main()
{
    srand(time(0)); // Inicializa la semilla aleatoria
    int num = rand() % 10 + 1;

    // Calcular el factorial
    int factorial = 1;
    for (int i = 1; i <= num; i++) {
        factorial =factorial*i;
    }

    cout << "Número aleatorio: " << num << endl;
    cout << "Factorial: " << factorial << endl;

    return 0;
}