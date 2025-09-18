// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 17/09/2025 
// Número de ejercicio: 2
#include <iostream>
#include <ctime> 
#include <cstdlib>

using namespace std;

double CalcularVolumen(double radio, double altura) ;

int main() 
{
    double radio;
    double altura = 10;
    srand(time(0));
    cout << "Ingrese el radio del cilindro: ";
    double volumen = CalcularVolumen(radio, altura);
    cout << "El volumen del cilindro es: " << volumen << endl;

    return 0;
}

double CalcularVolumen(double radio, double altura) 
{
    radio = rand() % 100 + 1; 
    cout << "El radio generado es: " << radio << endl;
    double volumen = 3.14159 * radio * radio * altura;
    return volumen;
}