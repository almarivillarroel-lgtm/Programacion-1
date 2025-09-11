// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo 
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 10/09/2025 
// Número de ejercicio: 4 
#include <iostream>
using namespace std;

// Función para calcular el IMC
float calcularIMC(float peso, float altura) 
{
    return peso / (altura * altura);
}

int main() {
    float peso;
    float altura;
    cout << "Ingrese el peso en kilogramos: ";
    cin >> peso;
    cout << "Ingrese la altura en metros: ";
    cin >> altura;

    float imc = calcularIMC(peso, altura);
    cout << "El IMC es: " << imc << endl;

    return 0;
}