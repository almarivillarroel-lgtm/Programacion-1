// Materia: Programación I, Paralelo 4 
// Autor: Almari Sara Villarroel Gallo
// Carnet: 9120066 L.P. 
// Carrera del estudiante: Ingeniería Biomedica 
// Fecha creación: 17/09/2025 
// Número de ejercicio: 9
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int calcularSueldo(int antiguedad, int totalVendido, double &sueldoBasico, double &comision, double &sueldoTotal);

int main() 
{
    srand(time(0));
    int numerovendedoras;
    cout << "Ingrese el número de vendedoras: ";
    cin >> numerovendedoras;

    for (int i = 1; i <= numerovendedoras; ++i) 
    {
        int antiguedad = rand() % 6; 
        int totalVendido = rand() % 101; 
        cout << "Vendedora " << i << endl;
        cout << "Antigüedad : " << antiguedad << endl;
        cout << "Total vendido en el mes: $" << totalVendido << endl;

        double sueldoBasico;
        double comision;
        double sueldoTotal;
        calcularSueldo(antiguedad, totalVendido, sueldoBasico, comision, sueldoTotal);

        cout << "Sueldo Básico: $" << sueldoBasico << endl;
        cout << "Comisión (10% del total vendido): $" << comision << endl;
        cout << "Sueldo Total a pagar: $" << sueldoTotal << endl;
    }

    return 0;
}

int calcularSueldo(int antiguedad, int totalVendido, double &sueldoBasico, double &comision, double &sueldoTotal) {
    if (antiguedad < 1) 
    {
        sueldoBasico = 300.0; 
    } 
    else if (antiguedad <= 3) 
    {
        sueldoBasico = 500.0; 
    } 
    else 
    {
        sueldoBasico = 700.0; 
    }

    comision = totalVendido * 0.10;
    sueldoTotal = sueldoBasico + comision;

    return 0;
}