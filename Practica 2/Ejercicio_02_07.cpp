// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 7 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int N;
    cout << "Ingrese la cantidad total de niños: ";
    cin >> N;

    srand(time(0));

    // Generar aleatoriamente la cantidad de niños de 1, 2 y 3 años
    int n1 = rand() % (N + 1); 
    int n2 = rand() % (N - n1 + 1); 
    int n3 = N - n1 - n2; 

    cout << "Niños de 1 año: " << n1 << endl;
    cout << "Niños de 2 años: " << n2 << endl;
    cout << "Niños de 3 años: " << n3 << endl;

    int paniales = (n1 * 6) + (n2 * 3) + (n3 * 2);

    cout << "Consumo total de pañales por día: " << paniales << " PAÑALES" << endl;

    return 0;
}