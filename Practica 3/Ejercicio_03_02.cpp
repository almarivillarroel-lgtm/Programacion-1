// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 2 
#include <iostream>
using namespace std;
// Función para convertir Celsius a Fahrenheit
float celsius_a_fahrenheit(float celsius) 
{
    return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    float grados_C;
    cout << "Ingrese la temperatura en grados Celsius: ";
    cin >> grados_C;
    float grados_F = celsius_a_fahrenheit(grados_C);
    cout << grados_C << " grados Celsius equivalen a " << grados_F << " grados Fahrenheit." << endl;
    return 0;
}