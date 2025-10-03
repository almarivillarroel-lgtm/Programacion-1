// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Carnet: 9120066 L.P 
// Carrera del estudiante: Ing. Biomedica 
// Fecha creación: 01/10/2025
#include <iostream>
using namespace std;

double ParteFraccionaria(double numero) 
{
    int entero = numero; 
    return numero - entero;  
}

int main() 
{
    double numero;
    
    cout << "Ingrese un numero: ";
    cin >> numero;
    
    double fraccion = ParteFraccionaria(numero);
    cout << "La parte fraccionaria es: " << fraccion << endl;
    
    return 0;
}