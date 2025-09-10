// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 2 
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
int main()
{
    int n=0;
    cout << "Ingrese el número de lanzamientos: ";
    cin >> n;

    int caras = 0;
    int cruz = 0;
    srand(time(0)); // Inicializa la semilla aleatoria

    for (int i = 0; i < n; i++) {
        int moneda = rand() % 2; // 0 = cara, 1 = cruz
        if (moneda == 0)
            caras= caras + 1;
        else
            cruz= cruz + 1;
    }

    double porcentajeCaras = (caras * 100.0) / n;
    double porcentajeCruz = (cruz * 100.0) / n;

    cout << "Porcentaje de caras: " << porcentajeCaras << "%" << endl;
    cout << "Porcentaje de cruz: " << porcentajeCruz << "%" << endl;

    return 0;
}