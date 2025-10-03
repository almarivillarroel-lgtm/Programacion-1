// Materia: Programación I, Paralelo 4 
// Autor: Almari Villarroel 
// Carnet: 9120066 L.P 
// Carrera del estudiante: Ing. Biomedica 
// Fecha creación: 01/10/2025
#include <iostream>
using namespace std;
int EncontrarMax (int a, int b) 
{
    if (a > b)
    {
        return a;
    }    
    else
    {
        return b;
    }   
}
int main() 
{
    int num1, num2;
    cout << "Ingrese dos numeros: ";    
    cin >> num1 >> num2;
    cout << "El mayor es: " << EncontrarMax(num1, num2) << endl;
    return 0;
} 